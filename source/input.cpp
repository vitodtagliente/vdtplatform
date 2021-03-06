#include <vdtplatform/input.h>

#include <vdtplatform/application.h>

namespace platform
{
	Input::Input(API* const api)
		: m_api(api)
		, m_lastKeysState()
		, m_keysState()
		, m_lastMousePosition()
		, m_mousePosition()
		, m_deltaMousePosition()
		, m_isMousePositionValid(true)
		, m_listeners()
	{
	}

	void Input::update()
	{
		auto temp_lastKeysState = std::move(m_lastKeysState);
		m_lastKeysState = std::move(m_keysState);
		m_keysState.clear();

		// handle mouse buttons keystate
		for (auto key_code : { KeyCode::MouseLeftButton, KeyCode::MouseRightButton, KeyCode::MouseWheelButton })
		{
			auto key_code_it = temp_lastKeysState.find(key_code);
			if (key_code_it != temp_lastKeysState.end())
			{
				if (key_code_it->second == KeyState::Pressed || key_code_it->second == KeyState::Down)
				{
					auto it = m_lastKeysState.find(key_code);
					if (it != m_lastKeysState.end())
					{
						if (it->second != KeyState::Released)
						{
							it->second = KeyState::Down;
						}
					}
					else
					{
						m_lastKeysState.insert({ key_code, KeyState::Down });
					}
				}
			}
		}
	}
	
	bool Input::isKeyDown(const KeyCode key) const
	{
		return hasKeyState(key, KeyState::Down);
	}
	
	bool Input::isKeyPressed(const KeyCode key) const
	{
		return hasKeyState(key, KeyState::Pressed);
	}
	
	bool Input::isKeyReleased(const KeyCode key) const
	{
		return hasKeyState(key, KeyState::Released);
	}

	bool Input::hasKeyState(const KeyCode key, const KeyState state) const
	{
		const auto it = m_lastKeysState.find(key);
		if (it != m_lastKeysState.end())
			return it->second == state;
		return false;
	}
	
	void Input::setKeyState(const KeyCode key, const KeyState state)
	{
		const auto it = m_keysState.find(key);
		if (it != m_keysState.end())
		{
			m_keysState[key] = state;
		}
		else
		{
			m_keysState.insert({ key, state });
		}

		for (IListener* const listener : m_listeners)
		{
			switch (state)
			{
			case KeyState::Down: listener->onKeyDown(key); break;
			case KeyState::Pressed: listener->onKeyPressed(key); break;
			case KeyState::Released: listener->onKeyReleased(key); break;
			}
		}
	}
	
	void Input::setMousePosition(const float x, const float y)
	{
		m_lastMousePosition = m_mousePosition;
		m_mousePosition = { static_cast<std::uint32_t>(x), static_cast<std::uint32_t>(y) };
		m_deltaMousePosition = { m_mousePosition.first - m_lastMousePosition.first, 
			m_mousePosition.second - m_lastMousePosition.second };
	}
	
	void Input::setMousePosition(const std::uint32_t x, const std::uint32_t y)
	{
		m_lastMousePosition = m_mousePosition;
		m_mousePosition = { x, y };
		m_deltaMousePosition = { m_mousePosition.first - m_lastMousePosition.first,
			m_mousePosition.second - m_lastMousePosition.second };
	}
	
	void Input::setMousePositionValid(const bool valid)
	{
		m_isMousePositionValid = valid;
	}
	
	const std::pair<std::uint32_t, std::uint32_t>& Input::getMousePosition() const
	{
		return m_mousePosition;
	}
	
	const std::pair<std::uint32_t, std::uint32_t>& Input::getDeltaMousePosition() const
	{
		return m_deltaMousePosition;
	}
	
	bool Input::isMousePositionValid() const
	{
		return m_isMousePositionValid;
	}
	
	void Input::clear()
	{
		m_lastKeysState.clear();
		m_keysState.clear();
	}
	
	void Input::registerListener(IListener* const listener)
	{
		m_listeners.insert(listener);
	}

	void Input::unregisterListener(IListener* const listener)
	{
		m_listeners.erase(listener);
	}

	Input* const Input::instance()
	{
		if (Application* const application = Application::instance())
		{
			return application->getInput();
		}
		return nullptr;
	}
}