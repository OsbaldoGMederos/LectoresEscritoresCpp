#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

#include "lector.h"
#include "escritor.h"

using namespace std;

mutex coutMutex;

int main(){

	int a[10];
	int contador = 0;

	for(int& i : a){
		i = 0;
	}

	Escritor osba(coutMutex, contador, a);

	this_thread::sleep_for(chrono::seconds(1));

	for(int& i : a){
		cout << i << endl;
	}
	return 0;
}


