#ifndef TOOL_H_
#define TOOL_H_

#include <random>

int generarNumeroRandom();

int generarNumeroRandom(){

	std::mt19937 generadorRandom;
	generadorRandom.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist100(1, 100);
	int numero = dist100(generadorRandom);

	return numero;
}


#endif
