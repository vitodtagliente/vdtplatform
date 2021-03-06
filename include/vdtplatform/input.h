/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include <map>
#include <set>
#include "keycode.h"

namespace platform
{
	class API; 

	class Input
	{
	public:

		class IListener
		{
		public:
			virtual void onKeyDown(const KeyCode key) {};
			virtual void onKeyPressed(const KeyCode key) {};
			virtual void onKeyReleased(const KeyCode key) {};
		};

		Input(API* const api);
		virtual ~Input() = default;

		// update the input state
		void update();

		bool isKeyDown(const KeyCode key) const;
		bool isKeyPressed(const KeyCode key) const;
		bool isKeyReleased(const KeyCode key) const;
		bool hasKeyState(const KeyCode key, const KeyState state) const;

		void setKeyState(const KeyCode key, const KeyState state);
		void setMousePosition(const float x, const float y);
		void setMousePosition(const std::uint32_t x, const std::uint32_t y);
		void setMousePositionValid(const bool valid);

		const std::pair<std::uint32_t, std::uint32_t>& getMousePosition() const;
		const std::pair<std::uint32_t, std::uint32_t>& getDeltaMousePosition() const;
		bool isMousePositionValid() const;

		// reset the input state
		void clear();


		/// listeners management
		void registerListener(IListener* const listener);
		void unregisterListener(IListener* const listener);

		static Input* const instance();

	private:

		// api
		API* m_api;
		// last keys states
		std::map<KeyCode, KeyState> m_lastKeysState;
		// keys states
		std::map<KeyCode, KeyState> m_keysState;
		// last mouse position
		std::pair<std::uint32_t, std::uint32_t> m_lastMousePosition;
		// mouse position
		std::pair<std::uint32_t, std::uint32_t> m_mousePosition;
		// delta mouse position
		std::pair<std::uint32_t, std::uint32_t> m_deltaMousePosition;
		// is mouse over window?
		bool m_isMousePositionValid;
		// listeners
		std::set<IListener*> m_listeners;
	};
}