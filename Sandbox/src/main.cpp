#include "Ocean/Application.h"
#include "Ocean/EntryPoint.h"

class Sandbox : public Ocean::Application
{
public:
    Sandbox() = default;
    ~Sandbox() = default;
};

Ocean::Application* Ocean::CreateApplication()
{
    return new Sandbox();
}