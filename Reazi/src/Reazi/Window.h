#pragma once

#include "rzpch.h"
#include "Core.h"
#include "Reazi/events/event.h"

namespace Reazi
{
	struct WindowProps
	{
		std::string title;
		unsigned width;
		unsigned height;

		WindowProps(std::string g_title = "ReaziApp", unsigned g_width = 1200, unsigned g_height = 780)
			: title(g_title), width(g_width), height(g_height)
		{}
	};


	// a base class for a Window, implemented per platform
	class REAZI_API Window
	{
	public:
		using EventCallBackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual inline unsigned getWidth() const = 0;
		virtual inline unsigned getHeight() const = 0;

		virtual void setEventCallBack(const EventCallBackFn& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		static Window* create(const WindowProps & = WindowProps());
	};
}