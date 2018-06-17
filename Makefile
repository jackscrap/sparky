CC=g++
DEPS = main.cpp src/graphic/window.h src/graphic/window.cpp

make: main.cpp
	 $(CC) $(DEPS) -std=c++11 -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lGLEW -lGLU -lm -pthread -ldrm -lXdamage -lXfixes -lX11-xcb -lxcb-glx -lxcb-dri2 -lXxf86vm -lXext -lxcb -lXau -lXdmcp -g

clean:
	rm *.out
