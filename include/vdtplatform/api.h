/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include <vector>

namespace platform
{
	class Application;
	class Window;

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
		virtual ~API();

		virtual bool startup() = 0;
		virtual void shutdown() = 0;

		inline Type getType() const { return m_type; }
		inline Application* const getApplication() const { return m_application; };
		
	protected:

		virtual Application* const createApplication() const = 0;

	private:

		// api type
		Type m_type;
		// application
		Application* m_application;
	};
}