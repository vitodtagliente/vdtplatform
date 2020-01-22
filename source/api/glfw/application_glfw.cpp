#include <vdtplatform/api/glfw/application_glfw.h>

#include <vdtplatform/api.h>
#include <vdtplatform/window.h>

namespace platform
{
	Application_GLFW::Application_GLFW(API* const api)
		: Application(api)
	{
	}
	
	bool Application_GLFW::initialize()
	{
		Window* const window = m_api->createWindow();
		if (window != nullptr)
		{
			m_windows.push_back(window);
			return window->open({}) && Application::initialize();
		}
		return false;
	}
}