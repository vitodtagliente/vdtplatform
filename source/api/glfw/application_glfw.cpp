#include <vdtplatform/api/glfw/application_glfw.h>

#include <vdtplatform/api.h>
#include <vdtplatform/api/glfw/window_glfw.h>

namespace platform
{
	Application_GLFW::Application_GLFW(API* const api)
		: Application(api)
	{
	}

	Window* const Application_GLFW::createWindow() const
	{
		return new Window_GLFW();
	}
}