#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

#include "lector.h"
#include "escritor.h"

using namespace std;

mutex escritorMutex;

int main(){

	int a[10];
	int contador = 0;

	for(int& i : a){
		i = 0;
	}

	Escritor osba("osbaldo", escritorMutex, contador, a);
	Escritor marco("marco", escritorMutex, contador, a);
	Escritor sunny("sunny", escritorMutex, contador, a);

	Lector desiree("desiree", escritorMutex, a);
	Lector maribel("maribel", escritorMutex, a);
	Lector dani("dani", escritorMutex, a);


	this_thread::sleep_for(chrono::seconds(1));
}


