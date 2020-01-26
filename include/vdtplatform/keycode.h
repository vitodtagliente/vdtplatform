/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include <cstdint>

namespace platform
{
	// describes the key state
	enum class KeyState
	{
		Down,
		Pressed,
		Released
	};

	// collection of keys
	enum class KeyCode : std::uint32_t
	{
		None,
		Q,
		W,
		E,
		R,
		T,
		Y,
		U,
		I,
		O,
		P,
		A,
		S,
		D,
		F,
		G,
		H,
		J,
		K,
		L,
		Z,
		X,
		C,
		V,
		B,
		N,
		M,
		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,
		Enter,
		Space,
		Escape,
		UpArrow,
		DownArrow,
		RightArrow,
		LeftArrow,
		Keypad0,
		Keypad1,
		Keypad2,
		Keypad3,
		Keypad4,
		Keypad5,
		Keypad6,
		Keypad7,
		Keypad8,
		Keypad9,
		LeftControl,
		RightControl,
		LeftAlt,
		RightAlt,
		LeftShift,
		RightShift,

		MouseLeftButton,
		MouseRightButton,
		MouseWheelButton
	};
}