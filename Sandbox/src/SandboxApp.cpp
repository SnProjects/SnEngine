#include <SnEngine.h>

#include "imgui/imgui.h"

class ExampleLayer : public SnEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (SnEngine::Input::IsKeyPressed(SN_KEY_TAB))
			SN_TRACE("Tab key is pressed! (polling)");
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World!");
		ImGui::End();
	}

	void OnEvent(SnEngine::Event& event) override
	{
		// SN_TRACE("{0}", event);
		if (event.GetEventType() == SnEngine::EventType::KeyPressed)
		{
			SnEngine::KeyPressedEvent& e = (SnEngine::KeyPressedEvent&)event;
			if (e.GetKeyCode() == SN_KEY_TAB)
				SN_TRACE("Tab key is pressed (event)!");
			SN_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public SnEngine::Application
{
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}
};

SnEngine::Application* SnEngine::CreateApplication()
{
	return new Sandbox();
}