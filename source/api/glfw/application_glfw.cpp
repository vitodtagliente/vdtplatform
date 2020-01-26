#include <vdtplatform/api/glfw/application_glfw.h>

#include <vdtplatform/api.h>
#include <vdtplatform/api/glfw/window_glfw.h>

namespace platform
{
	Application_GLFW::Application_GLFW(API* const api)
		: Application(api)
	{
	}

	std::unique_ptr<Window> Application_GLFW::createWindow() const
	{
		return std::make_unique<Window_GLFW>();
	}
}