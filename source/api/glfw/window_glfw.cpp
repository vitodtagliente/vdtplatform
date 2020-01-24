#include <vdtplatform/api/glfw/window_glfw.h>

#include <GLFW/glfw3.h>
#include <vdtplatform/application.h>

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
		Window::resize(width, height);
	}

	bool Window_GLFW::openImplementation(const Settings& settings)
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
				[](GLFWwindow*, int width, int height)
				{
					Application* const app = Application::instance();
					Window* const window = app ? app->getWindow() : nullptr;
					
					if (Window_GLFW* const windowGLFW = static_cast<Window_GLFW*>(window))
					{
						windowGLFW->m_width = static_cast<std::uint32_t>(width);
						windowGLFW->m_height = static_cast<std::uint32_t>(height);
					}
				}
			);
			return true;
		}
		return false;
	}

	void Window_GLFW::closeImplementation()
	{
		glfwDestroyWindow(m_windowHandler);
	}

	void Window_GLFW::updateImplementation()
	{
		glfwPollEvents();

		// check for closing window
		if (glfwWindowShouldClose(m_windowHandler))
		{
			m_state = State::Closing;
			return;
		}
		glfwSwapBuffers(m_windowHandler);
	}
}