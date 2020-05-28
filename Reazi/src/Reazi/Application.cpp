#include "rzpch.h"
#include "Application.h"
#include <spdlog/fmt/ostr.h>

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
		WindowsResizeEvent e(1729, 842);
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
