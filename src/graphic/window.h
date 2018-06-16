#pragma once

#include "../../dep/glfw/glfw3.h"
#include <iostream>

namespace sparky {
	namespace graphics {
		class Window {
			private:
				const char* m_Name;
				int m_W, m_H;

				GLFWwindow *m_Window;

				bool m_Closed;

				bool init();

			public:
				Window(const char* name, int w, int h);

				~Window();

				void clear() const;
				void update() const;
				bool closed() const;

				inline int getW() const {
					return m_W;
				}

				inline int getH() const {
					return m_H;
				}
		};
	}
}
