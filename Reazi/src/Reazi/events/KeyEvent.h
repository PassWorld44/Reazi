#pragma once

#include "Event.h"

#include "rzpch.h"
//dependencies :
// string
// sstream

namespace Reazi
{
	class REAZI_API KeyEvent : public Event
	{
	private:

	public:
		inline int getKeyCode() { return m_keyCode; }

		EVENT_CLASS_CATEGORY( (int) EventCategory::EventCategoryKeyboard | (int)EventCategory::EventCategoryInput)

	protected:
		KeyEvent(int KeyCode) : m_keyCode(KeyCode) {}

		int m_keyCode;
	};

	class REAZI_API KeyPressedEvent : public KeyEvent
	{
	private:
		int m_repetedCount;
	public:
		KeyPressedEvent(int keyCode, int repetedCount)
			: KeyEvent(keyCode), m_repetedCount(repetedCount) {}

		inline int getRepetedCount() const { return m_repetedCount; }

		virtual std::string to_string() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent : " << m_keyCode << " (" << m_repetedCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	};

	class REAZI_API KeyReleasedEvent : public KeyEvent
	{
	private:

	public:
		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode) {}

		virtual std::string to_string() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent : " << m_keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)

	};
}