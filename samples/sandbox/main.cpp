#include <iostream>
#include <vdtplatform/platform.h>

using namespace std;
using namespace platform;

int main(void)
{
    API* api = API::Factory::get(API::Type::GLFW);
    api->startup();

    auto app = api->createApplication();
    auto window = api->createWindow();

    Window::Settings settings{};
    window->open(settings);

    while (window->isOpen())
    {
        window->update();
    }

    api->shutdown();

    return 0;
}