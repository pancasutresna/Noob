#include <Noob.h>

class ExampleLayer : public Noob::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		NB_CORE_INFO("ExampleLayer::Update");
	}

	void OnEvent(Noob::Event& event) override
	{
		NB_TRACE("{0}", event);
	}

};

class Sandbox : public Noob::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {
	}
};

Noob::Application* Noob::CreateApplication() {
	return new Sandbox();
}