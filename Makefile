CC=g++
DEPS = main.cpp src/graphic/window.h src/graphic/window.cpp src/math/vec2.h src/math/vec2.cpp src/math/vec3.h src/math/vec3.cpp src/math/mat4.h src/math/mat4.cpp

make: main.cpp
	 $(CC) $(DEPS) -std=c++17 -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lGLEW -lGLU -lm -pthread -ldrm -lXdamage -lXfixes -lX11-xcb -lxcb-glx -lxcb-dri2 -lXxf86vm -lXext -lxcb -lXau -lXdmcp -g

clean:
	rm *.out
