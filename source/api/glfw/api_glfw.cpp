#include <vdtplatform/api/glfw/api_glfw.h>

#include <GLFW/glfw3.h>
#include <vdtplatform/api/glfw/application_glfw.h>

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

	std::unique_ptr<Application> API_GLFW::createApplication() const
	{
		return std::make_unique<Application_GLFW>((API*)this);
	}
}