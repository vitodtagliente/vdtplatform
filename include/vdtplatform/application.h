/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include <memory>
#include <set>
#include <vector>

#include "input_system.h"
#include "time.h"
#include "window.h"

namespace platform
{
	class API;

	class Application
	{
	public:

		enum class State
		{
			Created,
			Closed,
			Closing,
			Error,
			Running
		};

		class IListener
		{
		public:
			virtual void onClose() = 0;
			virtual bool onInitialize() = 0;
			virtual void onPause() = 0;
			virtual void onResume() = 0;
			virtual void onUpdate() = 0;
		};

		Application(API * const api);
		virtual ~Application() = default;
		
		/// Get the state of the application
		/// @return The ApplicationState
		State getState() const { return m_state; }

		InputSystem& getInputSystem() { return m_inputSystem; }
		const InputSystem& getInputSystem() const { return m_inputSystem; }

		Time* const getTime() const;

		/// Launch the application
		State launch();
		/// Update the application
		State update();
		/// Close the application
		void close();
		
		virtual bool supportsWindows() const;

		Window* const getWindow() const;
		Window* const getMainWindow() const;

		/// listeners management
		void registerListener(IListener* const listener);
		void unregisterListener(IListener* const listener);

		static Application* const instance();

	protected:

		/// Initialize the application
		/// @return true if it is successful
		virtual bool initialize();
		virtual void bindEvents();
		virtual void unbindEvents();

		// api 
		API* m_api;
		// state
		State m_state;
		// windows
		std::unique_ptr<Window> m_window;
		// input system
		InputSystem m_inputSystem;
		// time system
		std::unique_ptr<Time> m_time;
		// listeners
		std::set<IListener*> m_listeners;
		
	};
}