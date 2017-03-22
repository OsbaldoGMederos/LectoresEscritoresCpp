#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex coutMutex;

class Lector{
private:
	mutex& cm;
	thread trabajador;

public:
	Lector(mutex& c)
		:cm(c), trabajador(&Lector::iniciar, this){}

	~Lector(){
		trabajador.join();
	}

	void iniciar();
	
};


void Lector::iniciar(){
	lock_guard<mutex> cm(coutMutex);
	cout << "Hola mundo" << endl;
}

int main(){

	
	Lector osbaldo(coutMutex);

	return 0;
}

