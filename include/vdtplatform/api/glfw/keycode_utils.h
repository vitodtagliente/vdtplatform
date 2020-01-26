/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include "../../keycode.h"

namespace platform
{
	struct KeyUtils_GLFW
	{
		KeyUtils_GLFW() = delete;

		static KeyCode toKeyCode(const int key);
		static KeyState toKeyState(const int action);
	};
}