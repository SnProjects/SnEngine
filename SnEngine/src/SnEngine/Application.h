#pragma once
#include "snpch.h"

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

        inline static Application& Get() { return *s_Instance; } 
        inline Window& GetWindow() { return *m_Window; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;

    private:
        static Application* s_Instance;
    };

    
    // This function will be defined in the client
    Application* CreateApplication();
}
