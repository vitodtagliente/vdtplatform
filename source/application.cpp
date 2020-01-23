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
				Window* const window = createWindow();
				if (window && window->open({}))
				{
					m_windows.push_back(window);
					return m_state = State::Running, m_state;
				}
			}
			m_state = State::Error;
		}
		return m_state;
	}

	void Application::update()
	{
		if (m_state == State::Running)
		{
			for (int i = 0; i < m_windows.size(); ++i)
			{
				m_windows[i]->update();
				// main window
				if (i == 0 && m_windows[i]->isOpen() == false)
				{
					m_state = State::Closing;
				}
			}

			for (const auto& listener : m_listeners)
			{
				listener->onUpdate();
			}
		}
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