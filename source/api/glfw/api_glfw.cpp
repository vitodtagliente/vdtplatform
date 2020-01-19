#include <vdtplatform/api/glfw/api_glfw.h>

namespace platform
{
	API_GLFW::API_GLFW()
		: API(API::Type::GLFW)
	{

	}

	bool API_GLFW::startup()
	{
		return true;
	}

	void API_GLFW::shutdown()
	{
	}
}