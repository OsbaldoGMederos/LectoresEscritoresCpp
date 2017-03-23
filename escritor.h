#ifndef ESCRITOR_H_
#define ESCRITOR_H_

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>
#include <random>
#include <ctime>


class Escritor{

private:

	const std::string nombre;
	std::mutex& cm;
	int& producto;
	int *bufferPtr;
	std::thread trabajador;

public:
	Escritor(std::string n, std::mutex& c, int& p, int buffer[])
		:nombre(n), cm(c), producto(p), bufferPtr(buffer), trabajador(&Escritor::iniciar, this){}

	~Escritor(){
		trabajador.join();
	}

	void iniciar();
	void escribir();
	void aumentarContador();
};

#endif
