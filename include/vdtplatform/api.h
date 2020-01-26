/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include <memory>
#include <vector>

#include "application.h"
#include "time.h"
#include "window.h"

namespace platform
{
	class API
	{
	public:

		enum class Type
		{
			Null,
			GLFW
		};

		class Factory
		{
		public:

			static API* const get();
			static API* const get(const Type type);
			static const std::vector<Type>& getAvailableTypes() { return s_availableTypes; }

		private:

			static std::vector<Type> s_availableTypes;
			static API::Type s_platformDefaultType;
			static API* s_instance;
		};

		API(const Type type);
		virtual ~API() = default;

		virtual bool startup();
		virtual void shutdown() = 0;

		inline Type getType() const { return m_type; }
		
		Application* const getApplication() const;

		virtual std::unique_ptr<Window> createWindow() = 0;
		virtual std::unique_ptr<Time> createTime();

	protected:

		virtual std::unique_ptr<Application> createApplication() = 0;

	private:

		// api type
		Type m_type;
		// application
		std::unique_ptr<Application> m_application;
	};
}