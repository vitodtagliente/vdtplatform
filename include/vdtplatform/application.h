/// Copyright (c) Vito Domenico Tagliente

#pragma once

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
			virtual bool initialize() = 0;
			virtual void update() = 0;
			virtual void close() = 0;
		};

		Application(API * const api);
		virtual ~Application() = default;

		State getState() const { return m_state; }

		virtual bool initialize();
		virtual void update();
		virtual void close();

		const Window& getWindow() const { return *m_window; }

	protected:

		// api 
		API* m_api;
		// state
		State m_state;
		// window
		Window* m_window;
		// listeners
		std::vector<IListener*> m_listeners;
		
	};
}