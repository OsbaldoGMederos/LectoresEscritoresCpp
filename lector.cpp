#include "lector.h"

using namespace std;

void Lector::iniciar(){
	while(true){
		leer();
	}
}

void Lector::leer(){

	mt19937 generador;
	generador.seed(random_device()());
	uniform_int_distribution<mt19937::result_type> dist10(0, 9);
	int randomNum = dist10(generador);

	if(bufferPtr[randomNum] == 0){
		cm.lock();
		cout << color << "El lector " << nombre << " quizó leer en " << randomNum;
		cout << color << " Pero no había nada escrito " << endl;
		cm.unlock();
	}
	else{
		cm.lock();
		cout << color << "El lector " << nombre << " leyó " << bufferPtr[randomNum] << " en posición " << randomNum << endl;
		cm.unlock();
	}
	this_thread::sleep_for(chrono::milliseconds(randomNum * 100));
}
