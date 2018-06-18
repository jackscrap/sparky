#pragma once

#include "vec3.h"

namespace sparky {
	namespace math {
		struct mat4 {
			float el[4 * 4];

			mat4();
			mat4(float diag);

			static mat4 id();

			mat4& mult(const mat4& other);
			friend mat4 operator*(mat4 left, const mat4& right);
			mat4 operator*=(const mat4& other);

			static mat4 orth(float left, float right, float top, float bottom, float near, float far);
			static mat4 persp(float fov, float aspectRatio, float near, float far);

			static mat4 trans(const vec3& trans);
			static mat4 rot(float angle, const vec3& axis);
			static mat4 scale(const vec3& scale);
		};
	}
}
