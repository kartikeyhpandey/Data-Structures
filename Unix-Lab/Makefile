HelloWorld.exe: Main.o HelloWorld.o
		g++ -g -o HelloWorld.exe Main.o HelloWorld.o

HelloWorld.o: HelloWorld.h HelloWorld.cpp
		g++ -g -o HelloWorld.o -c HelloWorld.cpp

Main.o: HelloWorld.h Main.cpp
		g++ -g -o Main.o -c Main.cpp

clean:
		rm HelloWorld.o Main.o HelloWorld.exe
