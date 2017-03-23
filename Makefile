all:
	g++ -std=c++11 -pthread -Wall -Wextra lector.h escritor.h lector.cpp escritor.cpp main.cpp -o a
