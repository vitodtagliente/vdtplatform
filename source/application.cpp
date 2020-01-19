#include <vdtplatform/application.h>
#include <vdtplatform/window.h>

namespace platform
{
	Application::Application(API* const api)
		: m_api(api)
		, m_state(State::Created)
	{
	}
	
	bool Application::initialize()
	{
		return false;
	}
	
	void Application::update()
	{
		if (m_state == State::Running)
		{
			m_window->update();

			for (const auto& listener : m_listeners)
			{
				listener->update();
			}
		}
	}
	
	void Application::close()
	{
		if (m_state == State::Running)
		{
			m_window->close();

			for (const auto& listener : m_listeners)
			{
				listener->close();
			}
		}
	}
}