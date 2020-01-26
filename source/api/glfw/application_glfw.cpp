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
				[](GLFWwindow*, const int key, const int, const int action, const int)
				{
					auto key_state = KeyState::Down;
					if (action == GLFW_PRESS)
						key_state = KeyState::Pressed;
					else if (action == GLFW_RELEASE)
						key_state = KeyState::Released;

					if (InputSystem* const input = InputSystem::instance())
					{
						//input->setKeyState(key, key_state);
					}
				}
			);

			glfwSetMouseButtonCallback(
				window_handler,
				[](GLFWwindow*, const int button, const int action, int)
				{
					auto key_state = KeyState::Down;
					if (action == GLFW_PRESS)
						key_state = KeyState::Pressed;
					else if (action == GLFW_RELEASE)
						key_state = KeyState::Released;

					if (InputSystem* const input = InputSystem::instance())
					{
						// input->setKeyState(button, key_state);
					}
				}
			);

			glfwSetCursorPosCallback(
				window_handler,
				[](GLFWwindow*, const double x, const double y)
				{
					if (InputSystem* const input = InputSystem::instance())
					{
						input->setMousePosition(static_cast<float>(x), static_cast<float>(y));
					}
				}
			);

			glfwSetCursorEnterCallback(
				window_handler,
				[](GLFWwindow*, const int isEntered)
				{
					if (InputSystem* const input = InputSystem::instance())
					{
						input->setMousePositionValid(static_cast<bool>(isEntered));
					}
				}
			);
		}
	}
}