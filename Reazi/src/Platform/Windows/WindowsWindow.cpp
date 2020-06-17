#include "rzpch.h"
#include "WIndowsWindow.h"
#include "Reazi/Core.h"

namespace Reazi
{
	static void GLFWErrorCallBack(int error, const char* description)
	{
		RZ_CORE_ERROR("GLFW error : ({0}) {1}", error, description);
	}

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

		RZ_CORE_INFO("Creating WindowsWIndow {0} ({1}, {2})", m_data.title, m_data.width, m_data.height);

		static bool s_glfwInit = false;

		if (!s_glfwInit)
		{
			int sucess = glfwInit();
			RZ_CORE_ASSERT(sucess, "Could not initialise GLFW !");

			glfwSetErrorCallback(GLFWErrorCallBack);
			s_glfwInit = true;
		}

		m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_data);
		setVSync(true);

		//init GLFW events

		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;
			
			WindowsResizeEvent event((float)width, (float)height);
			data.eventCallback(event);
		});

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowsClosedEvent event;
			data.eventCallback(event);
		});

		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int glfwGetKeyScancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			switch (action)
			{
			case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.eventCallback(event);
				}
				break;
			case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.eventCallback(event);
				}
				break;
			case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.eventCallback(event);
				}
				break;
			}
		});

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mode)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			switch (action)
			{
			case GLFW_PRESS:
				{
					MousePressedButton event(button);
					data.eventCallback(event);
				}
				break;
			case GLFW_RELEASE:
				{
					MouseReleasedButton event(button);
					data.eventCallback(event);
				}
				break;
			}
		});

		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScolledEvent event((float)xOffset, (float)yOffset);
			data.eventCallback(event);
		});

		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xpos, (float)ypos);
			data.eventCallback(event);
		});
	}

	void WindowsWindow::shutdown()
	{
		glfwDestroyWindow(m_window);
	}

}