#pragma once

#include "Core.h"

#include "events/Event.h"
#include "events/ApplicationEvent.h"
#include "Log.h"
#include "rzpch.h"

namespace Reazi {

	class REAZI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}