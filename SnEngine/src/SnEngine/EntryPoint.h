#pragma once

#ifdef SN_PLATFORM_WINDOWS

namespace SnEngine
{
    class Application;
}

extern SnEngine::Application* SnEngine::CreateApplication();

int main(int argc, char** argv)
{
    SnEngine::Log::Init();
    SN_CORE_WARN("Initialized Log!");
    int a = 5;
    SN_INFO("Hello! Var={0}", a);
    auto app = SnEngine::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
#endif
