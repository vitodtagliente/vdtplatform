#include <iostream>
#include <vdtplatform/platform.h>

using namespace std;
using namespace platform;

int main(void)
{
    API* api = API::Factory::get(API::Type::GLFW);

    return 0;
}