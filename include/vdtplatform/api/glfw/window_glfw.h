/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include "../../window.h"

struct GLFWwindow;

namespace platform
{
	class Window_GLFW : public Window
	{
	public:

		Window_GLFW();
		virtual ~Window_GLFW() override = default;

		virtual void setTitle(const std::string& title) override;
		virtual void resize(const std::uint32_t width, const std::uint32_t height) override;
		inline virtual std::uint32_t getWidth() const override { return m_width; }
		inline virtual std::uint32_t getHeight() const override { return m_height; }

		inline GLFWwindow* getWindowHandler() const { return m_windowHandler; }

	private:

		// open implementation
		virtual bool open_implementation(const Settings& settings) override;
		// close implementation
		virtual void close_implementation() override;

		// module update
		virtual void update_implementation() override;

		// GLFW window handler
		GLFWwindow* m_windowHandler;
		// window size
		std::uint32_t m_width, m_height;
	};
}