#pragma once

#include "Core.h"

#include "Window.h"
#include "SnEngine/LayerStack.h"
#include "SnEngine/Events/Event.h"
#include "SnEngine/Events/ApplicationEvent.h"

#include "SnEngine/ImGui/ImGuiLayer.h"

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
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }

        inline static Application& Get() { return *s_Instance; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
    private:
        static Application* s_Instance;
    };

    
    // This function will be defined in the client
    Application* CreateApplication();
}
