#include <Reazi.h>

class ExampleLayer : public Reazi::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{}

	void onUpdate() override
	{
		RZ_TRACE("ExampleLayer::onUpdate");
	}

	void onEvent(Reazi::Event& e) override
	{
		//RZ_TRACE("{0}", e);
	}

	void onAttach() override {}
	void onDetach() override {}
};

class Sandbox : public Reazi::Application
{
public:
	Sandbox()
	{
		RZ_TRACE("App Created !");
		pushLayer(new ExampleLayer());
		pushOverlay(new Reazi::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Reazi::Application* Reazi::CreateApplication()
{
	return new Sandbox();
}