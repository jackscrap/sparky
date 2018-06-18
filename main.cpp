#include <map>

#include "src/graphic/window.h"
#include "src/math/vec2.h"
#include "src/math/vec3.h"
#include "src/math/mat4.h"

int main() {
	using namespace sparky;
	using namespace graphics;
	using namespace math;

	std::map<char, int> size = {
		{
			'w', 800
		},
		{
			'h', 600
		}
	};

	float av[3] = {0.2f, 0.3f, 0.8f};
	vec3 a(av[0], av[1], av[2]);

	/* float bv[3] = {0.3f, 0.7f, 0.4f}; */
	/* vec3 b(bv[0], bv[1], bv[2]); */

	/* vec3 c = a * b; */

	Window window("Sparky", size);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	while (!window.closed()) {
		window.clear();

		window.update();
	}

	return 0;
}
