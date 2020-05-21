#pragma once

#include "Core.h"

namespace Reazi
{

	class REAZI_API Application
	{
	private:

	public:
		Application();
		virtual ~Application();

		void run();
	};

	//To be defined in Client
	Application* CreateApplication();

}