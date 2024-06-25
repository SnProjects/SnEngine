#include <SnEngine.h>

class ExampleLayer : public SnEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		SN_INFO("ExampleLayer::Update");
	}

	void OnEvent(SnEngine::Event& event) override
	{
		SN_TRACE("{0}", event);
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