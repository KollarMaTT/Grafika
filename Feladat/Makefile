all:
	gcc -Iinclude/ src/callbacks.c src/camera.c src/init.c src/main.c src/scene.c src/texture.c src/utils.c src/spike.c src/ball.c src/cup.c src/map.c src/skybox.c src/field_element.c -lSOIL -lobj -lopengl32 -lglu32 -lglut32 -lm -o soccerball.exe -Wall -Wextra -Wpedantic 

linux:
	gcc -Iinclude/ src/callbacks.c src/camera.c src/init.c src/main.c src/scene.c src/texture.c src/utils.c src/spike.c src/ball.c src/cup.c src/map.c src/skybox.c src/field_element.c -lSOIL -lobj -lGL -lGLU -lglut -lm -o soccerball -Wall -Wextra -Wpedantic
