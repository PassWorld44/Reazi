#include "rzpch.h"
#include "Application.h"
#include <spdlog/fmt/ostr.h>
#include <GLFW/glfw3.h>

namespace Reazi
{

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application* Application::s_instance = nullptr;

	Application::Application()
	{
		RZ_CORE_ASSERT(!s_instance, "application already exists !");

		s_instance = this;

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

			for (Layer* layer : m_layerStack)
			{
				layer->onUpdate();
			}
		}
	}

	void Application::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowsClosedEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		RZ_TRACE("{0}", e);

		for (auto it = m_layerStack.end(); it != m_layerStack.begin();)
		{
			(*--it)->onEvent(e);

			if (e.isHandled()) 
			//then this is the layer witch has handel the event
			{
				break;
			}
		}
	}

	void Application::pushLayer(Layer* layer)
	{
		m_layerStack.pushLayer(layer);
		layer->onAttach();
	}

	void Application::pushOverlay(Layer* overlay)
	{
		m_layerStack.pushLayer(overlay);
	}

	bool Application::OnWindowClose(WindowsClosedEvent& e)
	{
		m_runnig = false;
		return true;
	}
}
