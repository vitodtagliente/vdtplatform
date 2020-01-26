#include <vdtplatform/api/glfw/keycode_utils.h>

#include <GLFW/glfw3.h>

namespace platform
{
	KeyCode KeyUtils_GLFW::toKeyCode(const int key)
	{
		return KeyCode();
	}
	
	KeyState KeyUtils_GLFW::toKeyState(const int action)
	{
		auto key_state = KeyState::Down;
		if (action == GLFW_PRESS)
			key_state = KeyState::Pressed;
		else if (action == GLFW_RELEASE)
			key_state = KeyState::Released;
		return key_state;
	}
}