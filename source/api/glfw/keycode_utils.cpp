#include <vdtplatform/api/glfw/keycode_utils.h>

#include <GLFW/glfw3.h>
#include <map>

namespace platform
{
	KeyCode KeyUtils_GLFW::toKeyCode(const int key)
	{
		static std::map<int, KeyCode> keys{
			{GLFW_KEY_Q, KeyCode::Q},
			{GLFW_KEY_W, KeyCode::W},
			{GLFW_KEY_E, KeyCode::E},
			{GLFW_KEY_R, KeyCode::R},
			{GLFW_KEY_T, KeyCode::T},
			{GLFW_KEY_Y, KeyCode::Y},
			{GLFW_KEY_U, KeyCode::U},
			{GLFW_KEY_I, KeyCode::I},
			{GLFW_KEY_O, KeyCode::O},
			{GLFW_KEY_P, KeyCode::P},
			{GLFW_KEY_A, KeyCode::A},
			{GLFW_KEY_S, KeyCode::S},
			{GLFW_KEY_D, KeyCode::D},
			{GLFW_KEY_F, KeyCode::F},
			{GLFW_KEY_G, KeyCode::G},
			{GLFW_KEY_H, KeyCode::H},
			{GLFW_KEY_J, KeyCode::J},
			{GLFW_KEY_K, KeyCode::K},
			{GLFW_KEY_L, KeyCode::L},
			{GLFW_KEY_Z, KeyCode::Z},
			{GLFW_KEY_X, KeyCode::X},
			{GLFW_KEY_C, KeyCode::C},
			{GLFW_KEY_V, KeyCode::V},
			{GLFW_KEY_B, KeyCode::B},
			{GLFW_KEY_N, KeyCode::N},
			{GLFW_KEY_M, KeyCode::M},
			{GLFW_KEY_F1, KeyCode::F1 },
			{GLFW_KEY_F2, KeyCode::F2 },
			{GLFW_KEY_F3, KeyCode::F3 },
			{GLFW_KEY_F4, KeyCode::F4 },
			{GLFW_KEY_F5, KeyCode::F5 },
			{GLFW_KEY_F6, KeyCode::F6 },
			{GLFW_KEY_F7, KeyCode::F7 },
			{GLFW_KEY_F8, KeyCode::F8 },
			{GLFW_KEY_F9, KeyCode::F9 },
			{GLFW_KEY_F10, KeyCode::F10 },
			{GLFW_KEY_F11, KeyCode::F11 },
			{GLFW_KEY_F12, KeyCode::F12 },
			{GLFW_KEY_ENTER, KeyCode::Enter},
			{GLFW_KEY_SPACE, KeyCode::Space},
			{GLFW_KEY_ESCAPE, KeyCode::Escape},
			{GLFW_KEY_UP, KeyCode::UpArrow},
			{GLFW_KEY_DOWN, KeyCode::DownArrow},
			{GLFW_KEY_RIGHT, KeyCode::RightArrow},
			{GLFW_KEY_LEFT, KeyCode::LeftArrow},
			{GLFW_KEY_0, KeyCode::Keypad0},
			{GLFW_KEY_1, KeyCode::Keypad1},
			{GLFW_KEY_2, KeyCode::Keypad2},
			{GLFW_KEY_3, KeyCode::Keypad3},
			{GLFW_KEY_4, KeyCode::Keypad4},
			{GLFW_KEY_5, KeyCode::Keypad5},
			{GLFW_KEY_6, KeyCode::Keypad6},
			{GLFW_KEY_7, KeyCode::Keypad7},
			{GLFW_KEY_8, KeyCode::Keypad8},
			{GLFW_KEY_9, KeyCode::Keypad9},
			{GLFW_KEY_LEFT_CONTROL, KeyCode::LeftControl},
			{GLFW_KEY_RIGHT_CONTROL, KeyCode::RightControl},
			{GLFW_KEY_LEFT_ALT, KeyCode::LeftAlt},
			{GLFW_KEY_RIGHT_ALT, KeyCode::RightAlt},
			{GLFW_KEY_LEFT_SHIFT, KeyCode::LeftShift},
			{GLFW_KEY_RIGHT_SHIFT, KeyCode::RightShift},
			{GLFW_MOUSE_BUTTON_1, KeyCode::MouseLeftButton},
			{GLFW_MOUSE_BUTTON_2, KeyCode::MouseRightButton},
			{GLFW_MOUSE_BUTTON_3, KeyCode::MouseWheelButton}
		};

		auto it = keys.find(key);
		if (it != keys.end())
		{
			return it->second;
		}
		return KeyCode::None;
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