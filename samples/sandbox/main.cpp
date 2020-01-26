#include <iostream>
#include <sstream>
#include <vdtplatform/platform.h>

using namespace std;
using namespace platform;

int main(void)
{
    API* api = API::Factory::get(API::Type::GLFW);
    api->startup();

    auto app = api->getApplication();
    app->launch();

    Window* const window = app->getWindow();

    while (app->getState() == Application::State::Running)
    {
        app->update();

        std::stringstream ss;
        ss << "vdtgraphics" << " " << "1.0" << " [" << app->getFPS() << " FPS]";
        window->setTitle(ss.str());
    }
    app->close();

    api->shutdown();

    return 0;
}