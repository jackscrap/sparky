#include "src/graphic/window.h"

#include <map>

int main() {
	using namespace sparky;
	using namespace graphics;

	std::map<char, int> size = {
		{
			'w', 800
		},
		{
			'h', 600
		}
	};

	Window window("Sparky", size);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	while (!window.closed()) {
		window.clear();

		window.update();
	}

	return 0;
}
