/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include <memory>
#include <set>
#include <vector>

#include "fps.h"
#include "input.h"
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
			virtual void onClose() {};
			virtual bool onInitialize() { return true; };
			virtual void onPause() {};
			virtual void onResume() {};
			virtual void onUpdate() {};
		};

		Application(API * const api);
		virtual ~Application() = default;
		
		/// Get the state of the application
		/// @return The ApplicationState
		State getState() const { return m_state; }

		Input* const getInput() const;
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

		inline unsigned int getFPS() const { return m_fps.get(); }

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
		std::unique_ptr<Input> m_input;
		// time system
		std::unique_ptr<Time> m_time;
		// FPS 
		FPS m_fps;
		// listeners
		std::set<IListener*> m_listeners;
		
	};
}