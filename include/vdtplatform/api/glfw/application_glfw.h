/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include "../../application.h"

namespace platform
{
	class Application_GLFW : public Application
	{
	public:

		Application_GLFW(API* const api);
		virtual ~Application_GLFW() override = default;

	private:

		virtual bool initialize() override;
	};
}