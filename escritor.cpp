#include "escritor.h"

using namespace std;

void Escritor::iniciar(){
	while(true){
		escribir();
	}
}

void Escritor::escribir(){

	//bloquea para garantizar la exclusión mutua
	cm.lock();
	bufferPtr[producto] = 1;					//escribe en el buffer
	cout << "El escritor " << nombre << " escribió en " << producto << endl;
	aumentarContador();									//aumenta el contador para no escribir en un lugar
	cm.unlock();											// ya escrito
	srand(time(0));
	this_thread::sleep_for(chrono::milliseconds(rand() % 2000));	//duerme el proceso hasta por 2
																	// segundos
}

void Escritor::aumentarContador(){
	if(producto == 9)
		producto = 0;
	else
		producto ++;
}
