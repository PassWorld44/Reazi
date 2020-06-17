#pragma once

#include "Window.h"


#include "rzpch.h"
#include "Core.h"

#include "LayerStack.h"
#include "events/Event.h"
#include "events/ApplicationEvent.h"



namespace Reazi {

	class REAZI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void onEvent(Event& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowsClosedEvent& e);

		std::unique_ptr<Window> m_window;
		bool m_runnig = true;
		LayerStack m_layerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}