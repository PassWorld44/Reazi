#pragma once

#include "Core.h"

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