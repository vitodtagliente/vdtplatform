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
		};

		API(const Type type)
			: m_type(type)
		{

		}
		virtual ~API() = default;

		virtual bool startup() = 0;
		virtual void shutdown() = 0;

		inline Type getType() const { return m_type; }

		virtual Application* const createApplication() const = 0;
		virtual Window* const createWindow() const = 0;

	protected:

		// api type
		Type m_type;
	};
}