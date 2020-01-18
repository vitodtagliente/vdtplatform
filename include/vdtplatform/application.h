/// Copyright (c) Vito Domenico Tagliente

#pragma once

namespace platform
{
	class API;
	class Window;

	class Application
	{
	public:

		Application(const API& api);
		virtual ~Application();

		virtual bool initialize();
		virtual void update();
		virtual void close();

		const Window& getWindow() const { return *m_window; }

	protected:

		// api 
		const ApplicationModule::API& m_api;
		// window
		std::unique_ptr<Window> m_window;
	};
}