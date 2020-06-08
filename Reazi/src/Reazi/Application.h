#pragma once

#include "Core.h"

#include "events/Event.h"
#include "events/ApplicationEvent.h"
#include "Window.h"
#include "Log.h"
#include "rzpch.h"


namespace Reazi {

	class REAZI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void onEvent(Event& e);
	private:
		bool OnWindowClose(WindowsClosedEvent& e);

		std::unique_ptr<Window> m_window;
		bool m_runnig = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}