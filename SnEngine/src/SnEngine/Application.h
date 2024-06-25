#pragma once

#include "Core.h"

#include "Window.h"
#include "SnEngine/LayerStack.h"
#include "SnEngine/Events/Event.h"
#include "SnEngine/Events/ApplicationEvent.h"

namespace SnEngine
{
    class SN_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

    private:
        bool OnWindowClose(WindowCloseEvent& e);
        
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    
    // This function will be defined in the client
    Application* CreateApplication();
}
