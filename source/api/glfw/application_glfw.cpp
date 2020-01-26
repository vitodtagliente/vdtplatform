#include <vdtplatform/api/glfw/application_glfw.h>
#include <GLFW/glfw3.h>
#include <vdtplatform/api.h>
#include <vdtplatform/api/glfw/window_glfw.h>

namespace platform
{
	Application_GLFW::Application_GLFW(API* const api)
		: Application(api)
	{
	}

	std::unique_ptr<Window> Application_GLFW::createWindow() const
	{
		return std::make_unique<Window_GLFW>();
	}

	void Application_GLFW::bindEvents()
	{
		if (Window_GLFW* window = static_cast<Window_GLFW*>(getWindow()))
		{
			GLFWwindow* const window_handler = window->getWindowHandler();
			if (window_handler == nullptr)
			{
				return;
			}

			glfwSetKeyCallback(
				window_handler,
				[](GLFWwindow*, const int t_key, const int, const int t_action, const int)
				{
					auto key_state = KeyState::Down;
					if (t_action == GLFW_PRESS)
						key_state = KeyState::Pressed;
					else if (t_action == GLFW_RELEASE)
						key_state = KeyState::Released;

					// if (Input* const input = Input::instance())
					// {
					// 	input->setKeyState(t_key, key_state);
					// }
				}
			);

			glfwSetMouseButtonCallback(
				window_handler,
				[](GLFWwindow*, const int t_button, const int t_action, int)
				{
					auto key_state = KeyState::Down;
					if (t_action == GLFW_PRESS)
						key_state = KeyState::Pressed;
					else if (t_action == GLFW_RELEASE)
						key_state = KeyState::Released;

					// if (Input* const input = Input::instance())
					// {
					// 	input->setKeyState(t_button, key_state);
					// }
				}
			);

			glfwSetCursorPosCallback(
				window_handler,
				[](GLFWwindow*, const double t_x, const double t_y)
				{
					// if (Input* const input = Input::instance())
					// {
					// 	input->setMousePosition(static_cast<float>(t_x), static_cast<float>(t_y));
					// }
				}
			);

			glfwSetCursorEnterCallback(
				window_handler,
				[](GLFWwindow*, const int t_entered)
				{
					// if (Input* const input = Input::instance())
					// {
					// 	input->setMousePositionValid(t_entered);
					// }
				}
			);
		}
	}
}