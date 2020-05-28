#pragma once

#include "Reazi/Window.h"
#include "GLFW/glfw3.h"

namespace Reazi
{
	class WindowsWindow : public Window
	{
	private:
		GLFWwindow* m_window;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool VSync;

			EventCallBackFn eventCallback;
		};

		WindowData m_data;
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		virtual inline unsigned getWidth() const override { return m_data.width; }
		virtual inline unsigned getHeight() const override { return m_data.height; }

		virtual inline void setEventCallBack(const EventCallBackFn& callback) override { m_data.eventCallback = callback; }

		virtual void setVSync(bool enabled) override;
		virtual bool isVSync() const override;

	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();
	};
}