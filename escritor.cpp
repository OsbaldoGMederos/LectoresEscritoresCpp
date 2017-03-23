#include "escritor.h"

using namespace std;

void Escritor::iniciar(){
	lock_guard<mutex> bloqueoConsola(cm);
	cout << "Hola" << endl;
	bufferPtr[producto] = 1;
	producto++;
}
