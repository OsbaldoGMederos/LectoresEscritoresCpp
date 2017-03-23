#ifndef LECTOR_H_
#define LECTOR_H_

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <ctime>
#include <string>
#include <random>

class Lector{
private:
	const std::string nombre;
	const std::string color;
	std::mutex& cm;
	int *bufferPtr;

	std::thread trabajador;

public:
	Lector(std::string n, std::string col, std::mutex& m, int buffer[])
		:nombre(n), color(col), cm(m), bufferPtr(buffer), trabajador(&Lector::iniciar, this){}

	~Lector(){
		trabajador.join();
	}

	void iniciar();
	void leer();
};

#endif
