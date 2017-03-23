#include "lector.h"

using namespace std;

void Lector::iniciar(){
	lock_guard<std::mutex> bloqueoConsola(cm);
	cout << "Hola mundo" << endl;
}
