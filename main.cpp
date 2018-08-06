#include <map>

#include "src/graphic/window.h"
#include "src/math/vec2.h"
#include "src/math/vec3.h"
#include "src/math/mat4.h"
#include "src/graphic/shader.h"

#include "graphic/buff/buff.h"
#include "graphic/buff/idxBuff.h"
#include "graphic/buff/vtxArray.h"

#include "graphic/renderer2d.h"
#include "graphic/simple2drenderer.h"

#include "util/file.h"

int main() {
	using namespace sparky;
	using namespace graphic;
	using namespace math;

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

	/* GLuint vbo; */
	/* glGenBuffers(1, &vbo); */
	/* glBindBuffer(GL_ARRAY_BUFFER, vbo); */
	/* glBufferData(GL_ARRAY_BUFFER, sizeof vert, vert, GL_STATIC_DRAW); */
	/* glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); */
	/* glEnableVertexAttribArray(0); */


	VtxArray sprite1, sprite2;
	Buff* vbo = new Buff(vert, 4 * 3, 3);
	IdxBuff ibo(idc, 0);

	sprite1.addBuff(vbo, 0);
	sprite1.addBuff(colorA, 1);

	sprite1.addBuff(vbo, 0);
	sprite1.addBuff(colorB, 1);


	mat4 orth = mat4::orth(0.0f, 16.0f, 0.0f, -1.0f, 1.0f);

	Shader basic("src/shaders/basic.vert", "src/shaders/basic.frag");
	basic.enable();
	shader.setUniformMat4("pr_matrix", orth);
	shader.setUniformMat4f("ml_matrix", mat4::trans(vec3(2, 2, 0)));

	shader.setUniformMat4("light_pos", vec2(8.0f, 4.5f));
	shader.setUniformMat4f("color", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	Renderable2d sprite(math::vec3(5, 5, 0), math::vec2(4, 4), math4::vec4(1, 0, 1, 1), shader);
	Renderable2d sprite(math::vec3(7, 1, 0), math::vec2(3, 3), math4::vec4(1, 0, 1, 1), shader);
	Simple2dRenderer renderer;

	while (!window.closed()) {
		window.clear();

		double x,
					 y;

		window.mousePos(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f, 900.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		renderer.submit(&sprite1);
		renderer.submit(&sprite2);
		renderer.flush();

		window.update();
	}

	return 0;
}
