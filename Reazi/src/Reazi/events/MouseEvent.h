#pragma once


#include "Event.h"

#include "rzpch.h"
//dependencies :
// string
// sstream

namespace Reazi
{
	class REAZI_API MouseMovedEvent : public Event
	{
	private:
		float m_x, m_y;
	public:

		MouseMovedEvent(int x, int y) : m_x(x), m_y(y) {}
		
		inline float getX() { return m_x; }
		inline float getY() { return m_y; }

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent : x(" << m_x << "), y(" << m_y << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY( (int)EventCategory::EventCategoryMouse |(int) EventCategory::EventCategoryInput)
	};

	class REAZI_API MouseScolledEvent : public Event
	{
	private:
		float m_xOffest, m_yOffset;
	public:

		MouseScolledEvent(int x, int y) : m_xOffest(x), m_yOffset(y) {}

		inline float getXOffset() { return m_xOffest; }
		inline float getY() { return m_yOffset; }

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "MouseScolledEvent : x offset(" << m_xOffest << "), y offset(" << m_yOffset << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryMouse | (int)EventCategory::EventCategoryInput)
	};

	class REAZI_API MouseButtonEvent : public Event
	{
	protected:
		int m_button;
	public:

		MouseButtonEvent(int button) : m_button(button) {}

		inline float getButton() { return m_button; }

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "MouseButtonEvent : " << m_button;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryMouse | (int)EventCategory::EventCategoryInput)
	};

	class REAZI_API MousePressedButton : public MouseButtonEvent
	{
	public:
		MousePressedButton(int button) : MouseButtonEvent(button) {}

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "MousePressedButton : " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class REAZI_API MouseReleasedButton : public MouseButtonEvent
	{
	public:
		MouseReleasedButton(int button) : MouseButtonEvent(button) {}

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "MouseReleasedButton : " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
