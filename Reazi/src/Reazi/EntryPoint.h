#pragma once

#ifdef RZ_PLATFORM_WINDOWS

extern Reazi::Application* Reazi::CreateApplication();

int main(int argc, char** argv)
{
	Reazi::Log::Init();
	HZ_CORE_WARN("Initialized Log!");
	int a = 5;
	HZ_INFO("Hello! Var={0}", a);

	auto app = Reazi::CreateApplication();
	app->Run();
	delete app;
}

#endif