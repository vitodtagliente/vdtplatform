# vdtplatform
 C++ application management library



**vdtplatform** is a small library able to abstract the way in which an application behaves. 

```c++
#include <vdtplatform/platform.h>

int main(void)
{
    API* api = API::Factory::get(API::Type::GLFW);
    api->startup();

    auto app = api->getApplication();
    app->launch();

    while (app->getState() == Application::State::Running)
    {
        app->update();
    }
    app->close();

    api->shutdown();

    return 0;
}
```



The list of available APIs is automatically generated according to the system in which the library is going to be build. At the moment The following list is supported:

- GLFW (Windows, MacOS, Linux)
- Null (Generic cross-platform console application)
- ~~Android~~



If the operating system supports the window rendering, the vdtplatform's application is able to create and show a main window in which we are able to render any king of content.

The goal of this library consists of providing a cross platform API able to create and launch an application, providing also the support for the window, input and time management.

```c++
auto app = api->getApplication();
Window* const window = app->getWindow();

// ....

window->setTitle("test");
```

```c++
auto app = api->getApplication();
Input* const input = app->getInput();

// ....

if(input->isKeyDown(KeyCode::A))
    // do something...
```

```c++
auto app = api->getApplication();
Time* const time = app->getTime();

const double deltaTime = time->getDeltaTime();
const double totalTime = time->getTime();
```



Open the sandbox solution in order to see a working example.