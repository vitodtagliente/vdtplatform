/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include "../../api.h"

namespace platform
{
	class API_Null : public API
	{
	public:

		API_Null();
		virtual ~API_Null() override = default;

		virtual void shutdown() override;

	private:

		virtual std::unique_ptr<Application> createApplication() const override;

	};
}