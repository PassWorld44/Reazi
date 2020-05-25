#pragma once

#include "../Core.h"

#include <string>
#include <functional>

namespace Reazi
{
	//Currently, the event system is blocking the app, resolving the event, and resume.
	//A bus or buffer design will be implemented (may be)

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowMoved, WindowFocus, WindowLostFocus,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseScrolled, MouseMoved,
		AppTick, AppUpdate, AppRender
	};

	enum class EventCategory
	{
		None = 0,
		EventCategoryApp = BIT(1),
		EventCategoryInput = BIT(2),
		EventCategoryKeyboard = BIT(3),
		EventCategoryMouse = BIT(4),
		EventCategoryMouseButton = BIT(5)
	};

#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::##type; }\
							   virtual EventType getEventType() const override { return getStaticType(); }\
							   virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	class REAZI_API Event
	{
	private:
		friend class EventDispatcher;

	protected:
		bool m_handled = false;

	public:
		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string to_string() const { return getName(); }

		inline bool isInCategory(EventCategory category)
		{
			return (int)getCategoryFlags() & (int)category;
		}

	};
}
