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

	Application* const API_Null::createApplication() const
	{
		return new Application_Null((API*)this);
	}
}