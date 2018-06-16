#include "window.h"
#include <iostream>

namespace sparky {
	namespace graphics {
		Window::Window(const char* name, int w, int h) {
			m_Name = name;
			m_W = w;
			m_H = h;

			if (!init()) {
				std::cout << "Failed to initialize" << std::endl;

				glfwTerminate();
				return;
			}
		}

		Window::~Window() {
			glfwTerminate();
		}

		void resize(GLFWwindow *window, int w, int h) {
			glViewport(0, 0, w, h);
		}

		bool Window::init() {
			if (!glfwInit()) {
				std:: cout << "Failed to initialize GLFW" << std::endl;

				return false;
			}

			m_Window = glfwCreateWindow(m_W, m_H, m_Name, NULL, NULL);

			if (!m_Window) {
				std::cout << "Failed to create window" << std::endl;
				glfwTerminate();

				return false;
			}

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowSizeCallback(m_Window, resize);

			return true;
		}

		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update() const {
			glfwPollEvents();
			int asdf1 = 600,
					asdf2 = 800;
			glfwGetFramebufferSize(m_Window, &asdf1, &asdf2);
			glViewport(0, 0, m_W, m_H);
			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const {
			return glfwWindowShouldClose(m_Window);
		}
	}
}
