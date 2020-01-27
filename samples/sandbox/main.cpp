#include <iostream>
#include <sstream>
#include <vdtplatform/platform.h>

using namespace std;
using namespace platform;

class FPSListener : public Application::IListener
{
public:

    FPSListener()
        : Application::IListener()
        , m_app()
        , m_window()
    {
        m_app = Application::instance();
        m_window = m_app->getWindow();
    }

    virtual void onUpdate() override
    {
        std::stringstream ss;
        ss << "vdtplatform" << " " << "1.0" << " [" << m_app->getFPS() << " FPS]";
        m_window->setTitle(ss.str());
    }

private:

    Application* m_app;
    Window* m_window;
};

int main(void)
{
    API* api = API::Factory::get(API::Type::GLFW);
    api->startup();

    auto app = api->getApplication();
    app->launch();

    Application::IListener* listener = new FPSListener();
    app->registerListener(listener);

    Window* const window = app->getWindow();

    while (app->getState() == Application::State::Running)
    {
        app->update();
    }
    app->close();

    api->shutdown();

    return 0;
}