#include <vdtplatform/application.h>

#include <vdtplatform/api.h>
#include <vdtplatform/window.h>

namespace platform
{
	Application::Application(API* const api)
		: m_api(api)
		, m_state(State::Created)
	{
	}

	Application::~Application()
	{
		// the application is responsible for its windows
		for (auto it = m_windows.begin(); it != m_windows.end(); ++it)
		{
			delete (*it);
		}
		m_windows.clear();
	}
	
	bool Application::initialize()
	{
		bool success = true;
		for (auto it = m_listeners.begin(); it != m_listeners.end() && success; ++it)
		{
			success &= (*it)->onInitialize();
		}
		return success;
	}
	
	Application::State Application::launch()
	{
		if (m_state == State::Created)
		{
			if (initialize())
			{
				if (supportsWindows())
				{
					Window* const window = createWindow();
					if (window && window->open({}))
					{
						m_windows.push_back(window);
						m_state = State::Running;
					}
					else
					{
						m_state = State::Error;
					}
					return m_state;
				}
				else
				{
					m_state = State::Running;
				}
				return m_state;
			}
			m_state = State::Error;
		}
		return m_state;
	}

	Application::State Application::update()
	{
		if (m_state == State::Running)
		{
			for (auto it = m_windows.begin(); it != m_windows.end(); ++it)
			{
				if ((*it)->update() == Window::State::Closing)
				{
					(*it)->close();

					// close the application if it was the main window
					if (it == m_windows.begin())
					{
						return m_state = State::Closing, m_state;
					}
					else
					{
						delete (*it);
						m_windows.erase(it);
					}
				}
			}

			for (const auto& listener : m_listeners)
			{
				listener->onUpdate();
			}
		}
		return m_state;
	}
	
	void Application::close()
	{
		if (m_state == State::Running || m_state == State::Closing)
		{
			for (const auto& listener : m_listeners)
			{
				listener->onClose();
			}

			for (Window* const window : m_windows)
			{
				window->close();
			}
		}
	}

	bool Application::supportsWindows() const
	{
		return true;
	}

	bool Application::supportsMultipleWindows() const
	{
		return false;
	}

	Window* const Application::getWindow(const int index) const
	{
		if (index < m_windows.size())
			return m_windows[index];
		return nullptr;
	}

	Window* const Application::getMainWindow() const
	{
		return getWindow();
	}
	
	void Application::registerListener(IListener* const listener)
	{
		m_listeners.insert(listener);
	}
	
	void Application::unregisterListener(IListener* const listener)
	{
		m_listeners.erase(listener);
	}
	
	Application* const Application::instance()
	{
		return API::Factory::get()->getApplication();
	}
}