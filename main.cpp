#include "dep/glfw/glfw3.h"
#include <iostream>

#include "src/graphic/window.h"

int main() {
	using namespace sparky;
	using namespace graphics;

	Window window("Sparky", 800, 600);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	while (!window.closed()) {
		window.clear();

		window.update();
	}

	return 0;
}
