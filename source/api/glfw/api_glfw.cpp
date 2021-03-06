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
		return glfwInit() 
			&& API::startup();
	}

	void API_GLFW::shutdown()
	{
	}

	std::unique_ptr<Window> API_GLFW::createWindow()
	{
		return std::make_unique<Window_GLFW>();
	}

	std::unique_ptr<Application> API_GLFW::createApplication()
	{
		return std::make_unique<Application_GLFW>(this);
	}
}