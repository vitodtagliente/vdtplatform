/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include <set>
#include <vector>

namespace platform
{
	class API;
	class Window;

	class Application
	{
	public:

		enum class State
		{
			Created,
			Closed,
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
			virtual void onWindowClose() = 0;
			virtual void onWindowResize(Window* const window) = 0;
		};

		Application(API * const api);
		virtual ~Application();
		
		/// Get the state of the application
		/// @return The ApplicationState
		State getState() const { return m_state; }

		/// Launch the application
		State launch();
		/// Update the application
		void update();
		/// Close the application
		void close();

		/// Check if the application supports multiple windows
		/// @return true/false
		virtual bool supportsMultipleWindows() const;

		Window* const getWindow(const int index = 0) const;
		Window* const getMainWindow() const;
		const std::vector<Window*>& getWindows() const { return m_windows; }

		//listeners management
		void registerListener(IListener* const listener);
		void unregisterListener(IListener* const listener);

		static Application* const instance();

	protected:

		/// Initialize the application
		/// @return true if it is successful
		virtual bool initialize();
		virtual Window* const createWindow() const = 0;

		// api 
		API* m_api;
		// state
		State m_state;
		// windows
		std::vector<Window*> m_windows;
		// listeners
		std::set<IListener*> m_listeners;
		
	};
}