all:

build:
	g++ source/*.c++ source/classes/*.c++ -std=c++17 -I include -L lib -o bin/TeamFortress2D.exe -mwindows -fpermissive -lsfml-graphics -lsfml-window -lsfml-system