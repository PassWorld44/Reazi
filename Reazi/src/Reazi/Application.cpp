#include "rzpch.h"
#include "Application.h"
#include <spdlog/fmt/ostr.h>
#include <GLFW/glfw3.h>

namespace Reazi
{

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_window = std::unique_ptr<Window>(Window::create());
		m_window->setEventCallBack(BIND_EVENT_FN(Application::onEvent));
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
	void Application::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowsClosedEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		HZ_CORE_TRACE("{0}", e);

	}
	bool Application::OnWindowClose(WindowsClosedEvent& e)
	{
		m_runnig = false;
		return true;
	}
}
