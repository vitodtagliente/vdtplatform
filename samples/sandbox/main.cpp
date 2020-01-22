#include <iostream>
#include <vdtplatform/platform.h>

using namespace std;
using namespace platform;

int main(void)
{
    API* api = API::Factory::get(API::Type::GLFW);
    api->startup();

    auto app = api->getApplication();

    while (app->getState() == Application::State::Running)
    {
        app->update();
    }

    api->shutdown();

    return 0;
}