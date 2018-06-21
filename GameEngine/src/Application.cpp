#include <iostream>
#include "graphics/Window.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

int main()
{
	using namespace curse;
	using namespace graphics;
	using namespace glm;

	Window window("GameWindow", 1280, 720);

	vec4 a(0.2f, 0.3f, 0.8f, 1.0f);
	vec4 b(0.5f, 0.2f, 0.1f, 1.0f);
	vec4 c = a * b;
	std::cout << c.x << ", " << c.y << ", " << c.z << ", " << c.w << std::endl;

	mat4 position = translate(mat4(1.0f), vec3(2, 3, 4));
	position *= mat4(1.0f);

	vec4 col = position[3];

	while (window.isOpen())
	{
		if (window.isKeyPressed(GLFW_KEY_A))
			std::cout << "A Pressed \n";
		if (window.isButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
			std::cout << "Left mouse button pressed \n";
		
		// #TODO - move to the renderer 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.7f, 0.3f, 0.3f, 1.0f);
		glBegin(GL_TRIANGLES);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(-0.5f, -0.5f);
		glEnd();
		window.update();
	}
	return 0;
}