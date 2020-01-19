#include <vdtplatform/api/glfw/api_glfw.h>

#include <GLFW/glfw3.h>
#include <vdtplatform/api/glfw/application_glfw.h>
#include <vdtplatform/api/glfw/window_glfw.h>

namespace platform
{
	API_GLFW::API_GLFW()
		: API(API::Type::GLFW)
	{

	}

	bool API_GLFW::startup()
	{
		return glfwInit();
	}

	void API_GLFW::shutdown()
	{
	}

	Application* const API_GLFW::createApplication() const
	{
		return new Application_GLFW((API*)this);
	}

	Window* const API_GLFW::createWindow() const
	{
		return new Window_GLFW();
	}
}