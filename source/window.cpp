#include <vdtplatform/window.h>

namespace platform
{
	// default configuration
	Window::Settings::Settings()
		: title("vdtplatform")
		, width(640)
		, height(480)
		, fullscreen(false)
		, vsync(false)
	{

	}

	Window::Window()
		: m_state(State::Create)
		, m_listeners()
	{
	}

	bool Window::open(const Settings& settings)
	{
		if (m_state == State::Create)
		{
			if (openImplementation(settings))
			{
				for (auto listener : m_listeners)
				{
					listener->onOpen();
				}
				m_state = State::Open;
				return true;
			}
		}
		m_state = State::Error;
		return false;
	}

	Window::State Window::update()
	{
		if (m_state == State::Open)
		{
			updateImplementation();
		}
		return m_state;
	}

	void Window::close()
	{
		if (m_state == State::Open || m_state == State::Closing)
		{
			for (auto listener : m_listeners)
			{
				listener->onClose();
			}

			closeImplementation();
			m_state = State::Closed;
		}
	}

	void Window::resize(const std::uint32_t width, const std::uint32_t height)
	{
		for (IListener* const listener : m_listeners)
		{
			listener->onResize(width, height);
		}
	}

	void Window::registerListener(IListener* const listener)
	{
		m_listeners.insert(listener);
	}

	void Window::unregisterListener(IListener* const listener)
	{
		m_listeners.erase(listener);
	}
}