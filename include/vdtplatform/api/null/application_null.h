/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include "../../application.h"

namespace platform
{
	class Application_Null : public Application
	{
	public:

		Application_Null(API* const api);
		virtual ~Application_Null() override = default;

		virtual bool supportsWindows() const override;

	private:

		virtual std::unique_ptr<Window> createWindow() const override;
	};
}