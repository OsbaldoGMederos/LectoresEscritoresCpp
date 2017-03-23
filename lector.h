#ifndef LECTOR_H_
#define LECTOR_H_

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

class Lector{
private:
	std::mutex& cm;

	std::thread trabajador;

public:
	Lector(std::mutex& c)
		:cm(c), trabajador(&Lector::iniciar, this){}

	~Lector(){
		trabajador.join();
	}

	void iniciar();
};

#endif
