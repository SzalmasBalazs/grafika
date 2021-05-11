all:
	gcc -Iinclude/ src/scene.c src/callbacks.c src/asteroid.c src/camera.c src/init.c src/main.c  src/texture.c src/utils.c src/modelobject.c src/pcg_basic.c -lSOIL -lobj -lopengl32 -lglu32 -lglut32 -lm -o cube.exe -W

linux:
	gcc -Iinclude/ src/callbacks.c src/camera.c src/asteroid.c src/init.c src/main.c src/scene.c src/texture.c src/utils.c src/modelobject.c src/pcg_basic.c -lSOIL -lobj -lGL -lGLU -lglut -lm -o cube -W
