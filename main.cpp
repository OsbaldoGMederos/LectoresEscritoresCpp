#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

#include "lector.h"
#include "escritor.h"

#define ROJO "\033[1;31m"
#define VERDE "\033[1;32m"
#define AMARILLO "\033[1;33m"
#define CYAN "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define BLANCO "\033[1;37m"

using namespace std;

mutex escritorMutex;

int main(){

	int a[10];
	int contador = 0;

	for(int& i : a){
		i = 0;
	}

	Escritor osba("osbaldo", ROJO, escritorMutex, contador, a);
	Escritor marco("marco", VERDE, escritorMutex, contador, a);
	Escritor sunny("sunny", AMARILLO, escritorMutex, contador, a);

	Lector desiree("desiree", CYAN, escritorMutex, a);
	Lector maribel("maribel", MAGENTA, escritorMutex, a);
	Lector dani("dani", BLANCO, escritorMutex, a);

	return 0;
}


