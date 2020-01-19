/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include "../../api.h"

namespace platform
{
	class API_GLFW : public API
	{
	public:

		API_GLFW();
		virtual ~API_GLFW() override = default;

		virtual bool startup() override;
		virtual void shutdown() override;

		virtual Application* const createApplication() const override;
		virtual Window* const createWindow() const override;

	};
}