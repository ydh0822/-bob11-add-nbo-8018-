CC=g++

add-nbo.exe : add-nbo.o
	$(CC) -g add-nbo.o -o add-nbo.exe

add-nbo.o: add-nbo.cpp
	$(CC) -c add-nbo.cpp


