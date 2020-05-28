#pragma once

#include "event.h"

#include "rzpch.h"
//dependencies :
// string
// sstream

namespace Reazi
{
	class REAZI_API WindowsResizeEvent : public Event
	{
	private:
		float m_x, m_y;
	public:

		WindowsResizeEvent(float x, float y) : m_x(x), m_y(y) {}

		inline float getX() { return m_x; }
		inline float getY() { return m_y; }

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "WindowsResizeEvent : x(" << m_x << "), y(" << m_y << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApp)
	};

	class REAZI_API WindowsClosedEvent : public Event
	{
	public:

		WindowsClosedEvent() {}

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "WindowsClosedEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApp)
	};

	class REAZI_API AppTickEvent : public Event
	{
	public:

		AppTickEvent() {}

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "AppTickEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApp)
	};

	class REAZI_API AppUpdateEvent : public Event
	{
	public:

		AppUpdateEvent() {}

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "AppUpdateEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppUpdate)
			EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApp)
	};

	class REAZI_API AppRenderEvent : public Event
	{
	public:

		AppRenderEvent() {}

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "AppRenderEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppRender)
			EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApp)
	};
}