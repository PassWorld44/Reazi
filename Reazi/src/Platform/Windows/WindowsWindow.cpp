#include "rzpch.h"
#include "WIndowsWindow.h"
#include "Reazi/Core.h"

namespace Reazi
{
	Window* Window::create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) : m_window(nullptr)
	{
		init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		shutdown();
	}

	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void WindowsWindow::setVSync(bool enabled)
	{
		m_data.VSync = enabled;

		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}

	bool WindowsWindow::isVSync() const
	{
		return m_data.VSync;
	}

	void WindowsWindow::init(const WindowProps& props)
	{
		m_data.title = props.title;
		m_data.height = props.height;
		m_data.width = props.width;

		HZ_CORE_INFO("Creating WindowsWIndow {0} ({1}, {2})", m_data.title, m_data.width, m_data.height);

		static bool s_glfwInit = false;

		if (!s_glfwInit)
		{
			int sucess = glfwInit();
			RZ_CORE_ASSERT(sucess, "Could not initialise GLFW !");

			s_glfwInit = true;
		}

		m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_data);
		setVSync(true);
	}

	void WindowsWindow::shutdown()
	{
		glfwDestroyWindow(m_window);
	}

}