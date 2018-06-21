#include "Window.h"
#include <iostream>

namespace curse { namespace graphics {
	
	
	Window::Window(const char* name, int width, int height)
		:m_Name(name),m_Width(width), m_Height(height), m_Window(nullptr)
	{
		for (unsigned int i = 0; i < MAX_KEYS; i++)
			m_Keys[i] = 0;
		for (unsigned int i = 0; i < MAX_MOUSE_BUTONS; i++)
			m_MouseButton[i] = 0;
		if (!glfwInit())
		{
			std::cout << "GLFW failed to initialize" << std::endl;
			glfwTerminate();
		}

		/* Create a windowed mode window and its OpenGL context */
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);
		if (!m_Window)
		{
			std::cout << "Unable to create window" << std::endl;
			glfwTerminate();
		}


		/* Make the window's context current */
		glfwMakeContextCurrent(m_Window);

		/* Make the window's context current */
		glfwMakeContextCurrent(m_Window);
		// Set a pointer to the current window 
		glfwSetWindowUserPointer(m_Window, this);
		// Limit the framerate to the refresh rate of the monitor
		//glfwSwapInterval(1);

		// Print out the version name
		std::cout << glGetString(GL_VERSION) << std::endl;

		glfwSetWindowSizeCallback(m_Window, window_size_callback);
		// Set a key input callback 
		glfwSetKeyCallback(m_Window, key_callback);
		// Set Mouse Callback 
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		// Set mouse position callback 
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);

		if (glewInit() != GLEW_OK)
			std::cout << "Glew did not initialize!!" << std::endl;
	}


	Window::~Window()
	{
		glfwTerminate();
	}


	bool Window::isOpen()
	{
		return glfwWindowShouldClose(m_Window) == 0;
	}

	void Window::update() const
	{
		

		/* Swap front and back buffers */
		glfwSwapBuffers(m_Window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	
	bool Window::isKeyPressed(const int& key) const
	{
		if (key <= MAX_KEYS)
			return m_Keys[key];
	}

	bool Window::isButtonPressed(const int& button) const
	{
		if (button <= MAX_MOUSE_BUTONS)
			return m_MouseButton[button];
	}

	void Window::getMousePosition(double& outX, double& outY) const
	{
		outX = mx;
		outY = my;
	}

	void Window::window_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_Width = width;
		win->m_Height = height;
	}

	void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key <= MAX_KEYS)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Keys[key] = action == GLFW_PRESS;
		}
		else
			std::cout << "Keyboard key exceeds  the max no of keys" << std::endl;
	}

	void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		if (button <= MAX_MOUSE_BUTONS)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseButton[button] = action == GLFW_PRESS;
		}
		else
			std::cout << "Mouse Button exceeds the max no of buttons" << std::endl;
	}

	void Window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->mx = xpos;
		win->my = ypos;
	}

}}