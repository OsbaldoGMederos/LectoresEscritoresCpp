#ifndef ESCRITOR_H_
#define ESCRITOR_H_

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>

class Escritor{

private:

	const std::string nombre;
	std::mutex& cm;
	int& producto;
	int *bufferPtr;
	std::thread trabajador;

public:
	Escritor(std::mutex& c, int& p, int buffer[])
		:cm(c), producto(p), bufferPtr(buffer), trabajador(&Escritor::iniciar, this){}

	~Escritor(){
		trabajador.join();
	}

	void iniciar();
};

#endif
