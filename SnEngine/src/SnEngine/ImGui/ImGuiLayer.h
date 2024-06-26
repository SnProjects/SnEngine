#pragma once
#include "SnEngine/Layer.h"

#include "SnEngine/Events/ApplicationEvent.h"
#include "SnEngine/Events/KeyEvent.h"
#include "SnEngine/Events/MouseEvent.h"

namespace SnEngine
{
    class SN_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();
        
    private:
        float m_Time = 0.0f;
    };
}
