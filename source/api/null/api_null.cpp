#include <vdtplatform/api/null/api_null.h>

#include <vdtplatform/api/null/application_null.h>

namespace platform
{
	API_Null::API_Null()
		: API(API::Type::Null)
	{

	}

	void API_Null::shutdown()
	{
	}

	std::unique_ptr<Window> API_Null::createWindow()
	{
		return {};
	}

	std::unique_ptr<Application> API_Null::createApplication()
	{
		return std::make_unique<Application_Null>(this);
	}
}