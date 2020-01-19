#include <vdtplatform/api.h>

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(__MINGW32__)
#define PLATFORM_WINDOWS 1
#elif defined( __linux__ )
#define PLATFORM_LINUX 1
#elif defined( __APPLE__ )
#define PLATFORM_OSX 1
#endif

#define USE_GLFW PLATFORM_WINDOWS | PLATFORM_LINUX | PLATFORM_OSX

#if USE_GLFW
#include <vdtplatform/api/glfw/api_glfw.h>
#endif

namespace platform
{
	API* const API::Factory::get()
	{
		return get(s_platformDefaultType);
	}

	API* const API::Factory::get(const Type type)
	{
		if (std::find(s_availableTypes.begin(), s_availableTypes.end(), type) != s_availableTypes.end())
		{
			// create and cache the new requested api and cache
			switch (type)
			{
#ifdef USE_GLFW
			case API::Type::GLFW:
			{
				API_GLFW* const api = new API_GLFW();
				return api;
			}
			break;
#endif 
			case API::Type::Null:
			default:
				return nullptr;
				break;
			}
		}
		return nullptr;
	}

	std::vector<API::Type> API::Factory::s_availableTypes{
		API::Type::Null
#ifdef USE_GLFW
		, API::Type::GLFW
#endif
	};

	API::Type API::Factory::s_platformDefaultType =
#ifdef USE_GLFW
		API::Type::GLFW
#else 
		API::Type::Null
#endif
		;
}