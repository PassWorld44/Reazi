#include "Application.h"

namespace Reazi
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowsResizeEvent e(1280, 720);
		if (e.isInCategory(EventCategory::EventCategoryApp))
		{
			HZ_TRACE(e);
		}
		if (e.isInCategory(EventCategory::EventCategoryInput))
		{
			HZ_TRACE(e);
		}

		bool stop = false;
		while (!stop)
		{

		}
	}
}