#pragma once

#include <iostream>

namespace sparky {
	namespace math {
		struct vec3 {
			float x,
						y,
						z;

			vec3();
			vec3(float& x, float& y, float& z);

			vec3& add(const vec3& other);
			vec3& sub(const vec3& other);
			vec3& mult(const vec3& other);
			vec3& div(const vec3& other);

			friend vec3 operator +(vec3 left, const vec3& right);
			friend vec3 operator -(vec3 left, const vec3& right);
			friend vec3 operator *(vec3 left, const vec3& right);
			friend vec3 operator /(vec3 left, const vec3& right);

			bool operator ==(const vec3& other);
			bool operator !=(const vec3& other);

			vec3& operator +=(const vec3& other);
			vec3& operator -=(const vec3& other);
			vec3& operator *=(const vec3& other);
			vec3& operator /=(const vec3& other);

			/* friend std::ostream& operator<<(std::ostream& stream, const vec3& vec); */
		};
	}
}
