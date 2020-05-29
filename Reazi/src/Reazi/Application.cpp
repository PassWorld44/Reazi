#include "rzpch.h"
#include "Application.h"
#include <spdlog/fmt/ostr.h>
#include <GLFW/glfw3.h>

namespace Reazi
{
	Application::Application()
	{
		m_window = std::unique_ptr<Window>(Window::create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_runnig)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_window->onUpdate();
		}
	}
}
