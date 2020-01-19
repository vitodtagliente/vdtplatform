#include <vdtplatform/api/glfw/window_glfw.h>

#include <GLFW/glfw3.h>

namespace platform
{
	Window_GLFW::Window_GLFW()
		: Window()
		, m_windowHandler()
		, m_width()
		, m_height()
	{
	}

	void Window_GLFW::setTitle(const std::string& title)
	{
		glfwSetWindowTitle(m_windowHandler, title.c_str());
	}

	void Window_GLFW::resize(const std::uint32_t width, const std::uint32_t height)
	{
		glfwSetWindowSize(m_windowHandler, width, height);
	}

	bool Window_GLFW::open_implementation(const Settings& settings)
	{
		m_windowHandler = glfwCreateWindow(
			settings.width,
			settings.height,
			settings.title.c_str(),
			false, false
		);

		// internal storage
		m_width = settings.width;
		m_height = settings.height;

		if (m_windowHandler != nullptr)
		{
			glfwMakeContextCurrent(m_windowHandler);

			// resize callback
			glfwSetFramebufferSizeCallback(
				m_windowHandler,
				[](GLFWwindow*, int t_width, int t_height)
				{
					/*
					if (Window_GLFW* const window = static_cast<Window_GLFW*>(Window::instance()))
					{
						window->m_size = {
							static_cast<uint32>(t_width),
							static_cast<uint32>(t_height)
						};
					}
					*/
				}
			);
			return true;
		}
		return false;
	}

	void Window_GLFW::close_implementation()
	{
	}

	void Window_GLFW::update_implementation()
	{
		glfwPollEvents();

		// check for closing window
		if (glfwWindowShouldClose(m_windowHandler))
		{
			// #todo
			m_isOpen = false;
		}
		glfwSwapBuffers(m_windowHandler);
	}
}