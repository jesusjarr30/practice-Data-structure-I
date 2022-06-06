#ifndef PILAESTATICA_H
#define PILAESTATICA_H
#include "Estudiante.h"
#include <iostream>
using namespace std;
class PilaEstatica
{
	private:
		int tope;
		Estudiante Estatica[10];
	public:
		void inicializar();
		int vacia();
		bool llena();
		void push(Estudiante);
		Estudiante* pop();//Extrae (devuelve y elimina) al “dato” que se encuentra en “tope”
		Estudiante* top();//devuelve el ultimo elemnto
		int get_cont();
};

#endif
