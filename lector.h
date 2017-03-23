#ifndef LECTOR_H_
#define LECTOR_H_

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <random>
#include <ctime>
#include <string>

class Lector{
private:
	const std::string nombre;
	std::mutex& cm;
	int *bufferPtr;

	std::thread trabajador;

public:
	Lector(std::string n, std::mutex& m, int buffer[])
		:nombre(n), cm(m), bufferPtr(buffer), trabajador(&Lector::iniciar, this){}

	~Lector(){
		trabajador.join();
	}

	void iniciar();
	void leer();
};

#endif
