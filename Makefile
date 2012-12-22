all:
	g++ *.cpp -std=c++0x -o liveade -lsfml-graphics -lsfml-window -lsfml-system -O3 

windows:
	i486-mingw32-g++ -static-libgcc -static-libstdc++ ./*.cpp -I /usr/include/ -o winfos.exe

