#include "lector.h"

using namespace std;

void Lector::iniciar(){
	while(true){
		leer();
	}
}

void Lector::leer(){
	
	std::mt19937 generadorRandom;
	generadorRandom.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist10(0,9);
	int randomNum = dist10(generadorRandom);

	if(bufferPtr[randomNum] == 0){
		cm.lock();
		cout << "El lector " << nombre << " quizó leer en " << randomNum;
		cout << " Pero no había nada escrito " << endl;
		cm.unlock();
	}
	else{
		cm.lock();
		cout << "El lector " << nombre << " leyó " << bufferPtr[randomNum] << " en posición " << randomNum << endl;
		cm.unlock();
	}
	this_thread::sleep_for(chrono::milliseconds(randomNum * 100));
}
