#include <map>
#include <iostream>

#include "window.h"

namespace sparky {
	namespace graphics {
		Window::Window(const char* title, std::map<char, int> size) {
			m_Title = title;
			m_Size = size;

			if (!init()) {
				std::cout << "Failed to initialize" << std::endl;

				glfwTerminate();

				return;
			}

			for (int i = 0; i < MAX_KEY; i++) {
				m_Key[i] = false;
			}

			for (int i = 0; i < MAX_BTN; i++) {
				m_Btn[i] = false;
			}
		}

		Window::~Window() {
			glfwTerminate();
		}

		void resize_callback(GLFWwindow *window, int w, int h) {
			glViewport(0, 0, w, h);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			Window* win = (Window*) glfwGetWindowUserPointer(window);

			win->m_Key[key] = action != GLFW_RELEASE;
		}

		void btn_callback(GLFWwindow* window, int btn, int action, int mods) {
			Window* win = (Window*) glfwGetWindowUserPointer(window);

			win->m_Btn[btn] = action != GLFW_RELEASE;
		}

		void cursor_pos_callback(GLFWwindow* window, double posX, double posY) {
			Window *win = (Window*) glfwGetWindowUserPointer(window);

			win->m_Curs['x'] = posX;
			win->m_Curs['y'] = posY;
		}

		bool Window::init() {
			if (!glfwInit()) {
				std:: cout << "Failed to initialize GLFW" << std::endl;

				return false;
			}

			m_Window = glfwCreateWindow(m_Size['w'], m_Size['h'], m_Title, NULL, NULL);

			if (!m_Window) {
				std::cout << "Failed to create window" << std::endl;
				glfwTerminate();

				return false;
			}

			glfwMakeContextCurrent(m_Window);

			glfwSetWindowUserPointer(m_Window, this);

			glfwSetWindowSizeCallback(m_Window, resize_callback);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, btn_callback);
			glfwSetCursorPosCallback(m_Window, cursor_pos_callback);

			if (glewInit() != GLEW_OK) {
				std::cout << "Failed to initialize GLEW" << std::endl;

				return false;
			}

			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

			return true;
		}

		bool Window::pressedKey(unsigned int code) {
			return m_Key[code];
		}

		bool Window::pressedBtn(unsigned int btn) {
			return m_Btn[btn];
		}

		void Window::mousePos(unsigned int& x, unsigned int& y) {
			m_Curs['x'] = x;
			m_Curs['y'] = y;
		}

		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update() {
			glfwPollEvents();

			glfwGetFramebufferSize(m_Window, &m_Size['w'], &m_Size['h']);

			glViewport(0, 0, m_Size['w'], m_Size['h']);

			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const {
			return glfwWindowShouldClose(m_Window);
		}
	}
}
