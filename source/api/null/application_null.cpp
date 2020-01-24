#include <vdtplatform/api/null/application_null.h>

#include <vdtplatform/api.h>

namespace platform
{
	Application_Null::Application_Null(API* const api)
		: Application(api)
	{
	}

	bool Application_Null::supportsWindows() const
	{
		return false;
	}

	Window* const Application_Null::createWindow() const
	{
		return nullptr;
	}
}