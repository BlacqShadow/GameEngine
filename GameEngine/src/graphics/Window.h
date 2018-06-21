#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"


namespace curse { namespace graphics {
# define MAX_KEYS		1024
# define MAX_MOUSE_BUTONS 32
	// Class to create a glfw window
	// #TODO: Make key and mouse functions static, so that they are available throughout the program;
	class Window
	{
	private:
		const char* m_Name;
		int m_Width;
		int m_Height;
		GLFWwindow* m_Window;
		bool m_Keys[MAX_KEYS];
		bool m_MouseButton[MAX_MOUSE_BUTONS];
		double mx, my;


	public:
		Window(const char* name, int width, int height);
		~Window();
		bool isOpen();
		void update() const;
		bool isKeyPressed(const int& key) const; 
		bool isButtonPressed(const int& button) const;
		void getMousePosition(double& outX, double& outY) const;

	private:
		// Declaration of the window callback 
		static void window_size_callback(GLFWwindow* window, int width, int height);
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	};


}}


