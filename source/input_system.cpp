#include <vdtplatform/input_system.h>

namespace platform
{
	InputSystem::InputSystem(API* const api)
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

	void InputSystem::update()
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
	
	bool InputSystem::isKeyDown(const KeyCode key) const
	{
		return hasKeyState(key, KeyState::Down);
	}
	
	bool InputSystem::isKeyPressed(const KeyCode key) const
	{
		return hasKeyState(key, KeyState::Pressed);
	}
	
	bool InputSystem::isKeyReleased(const KeyCode key) const
	{
		return hasKeyState(key, KeyState::Released);
	}

	bool InputSystem::hasKeyState(const KeyCode key, const KeyState state) const
	{
		const auto it = m_lastKeysState.find(key);
		if (it != m_lastKeysState.end())
			return it->second == state;
		return false;
	}
	
	void InputSystem::setKeyState(const KeyCode key, const KeyState state)
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
	}
	
	void InputSystem::setMousePosition(const float x, const float y)
	{
		m_lastMousePosition = m_mousePosition;
		m_mousePosition = { x, y };
		m_deltaMousePosition = { x - m_lastMousePosition.first, y - m_lastMousePosition.second };
	}
	
	void InputSystem::setMousePosition(const std::uint32_t x, const std::uint32_t y)
	{
		m_lastMousePosition = m_mousePosition;
		m_mousePosition = { x, y };
		m_deltaMousePosition = { x - m_lastMousePosition.first, y - m_lastMousePosition.second };
	}
	
	void InputSystem::setMousePositionValid(const bool valid)
	{
		m_isMousePositionValid = valid;
	}
	
	const std::pair<std::uint32_t, std::uint32_t>& InputSystem::getMousePosition() const
	{
		return m_mousePosition;
	}
	
	const std::pair<std::uint32_t, std::uint32_t>& InputSystem::getDeltaMousePosition() const
	{
		return m_deltaMousePosition;
	}
	
	bool InputSystem::isMousePositionValid() const
	{
		return m_isMousePositionValid;
	}
	
	void InputSystem::clear()
	{
		m_lastKeysState.clear();
		m_keysState.clear();
	}
}