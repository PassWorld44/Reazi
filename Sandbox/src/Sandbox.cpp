#include <Reazi.h>

class Sandbox : public Reazi::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Reazi::Application* Reazi::CreateApplication()
{
	return new Sandbox();
}