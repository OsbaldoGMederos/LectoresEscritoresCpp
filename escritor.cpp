#include "escritor.h"

using namespace std;

void Escritor::iniciar(){
	while(true){
		escribir();
	}
}

void Escritor::escribir(){

	mt19937 generador;
	generador.seed(random_device()());
	uniform_int_distribution<mt19937::result_type> dist100(0, 100);
	int numero = dist100(generador);
	
	//bloquea para garantizar la exclusión mutua
	cm.lock();
	bufferPtr[producto] = numero;						//escribe en el buffer
	cout << color << "El escritor " << nombre << " escribió " << numero << " en " << producto << endl;
	aumentarContador();									//aumenta el contador para no escribir en un lugar
	cm.unlock();											// ya escrito
	srand(time(0));
	this_thread::sleep_for(chrono::milliseconds(numero *  20));	//duerme el proceso hasta por 2
																	// segundos
}

void Escritor::aumentarContador(){
	if(producto == 9)
		producto = 0;
	else
		producto++;
}
