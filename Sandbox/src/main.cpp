#include <Reazi.h>
#include <memory>

class Sandbox : public Reazi::Application
{
private:

public:
	Sandbox() {}
	~Sandbox() {}
};

Reazi::Application* CreateApplication()
{
	return new Sandbox();
}

int main()
{
	auto app = CreateApplication();
	app->run();
	delete app;
}