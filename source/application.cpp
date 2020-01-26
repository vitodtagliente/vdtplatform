#include <vdtplatform/application.h>

#include <vdtplatform/api.h>
#include <vdtplatform/window.h>

namespace platform
{
	Application::Application(API* const api)
		: m_api(api)
		, m_state(State::Created)
		, m_window()
		, m_inputSystem(api)
		, m_time()
	{
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

	void Application::bindEvents()
	{
	}

	void Application::unbindEvents()
	{

	}
	
	Time* const Application::getTime() const
	{
		return m_time.get();
	}

	Application::State Application::launch()
	{
		if (m_state == State::Created)
		{
			if (initialize())
			{
				m_time = std::move(m_api->createTime());
				m_window = std::move(m_api->createWindow());

				if (m_window && m_window->open({}))
				{
					bindEvents();
					return m_state = State::Running, m_state;
				}
			}
			m_state = State::Error;
		}
		return m_state;
	}

	Application::State Application::update()
	{
		if (m_state == State::Running)
		{
			m_time->tick();

			if (supportsWindows())
			{
				if (m_window->update() == Window::State::Closing)
				{
					m_window->close();
					m_state = State::Closing;
					return m_state;
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
			unbindEvents();

			for (const auto& listener : m_listeners)
			{
				listener->onClose();
			}

			if (m_window)
			{
				m_window->close();
			}
		}
	}

	bool Application::supportsWindows() const
	{
		return true;
	}

	Window* const Application::getWindow() const
	{
		return m_window.get();
	}

	Window* const Application::getMainWindow() const
	{
		return m_window.get();
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