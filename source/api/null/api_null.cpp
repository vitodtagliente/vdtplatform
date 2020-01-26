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

	std::unique_ptr<Application> API_Null::createApplication() const
	{
		return std::make_unique<Application_Null>((API*)this);
	}
}