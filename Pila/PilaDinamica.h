#ifndef PILADINAMICA_H
#define PILADINAMICA_H
#include "Estudiante.h"
#include <iostream>
using namespace std;
class Nodo
{
	private:
		Estudiante *Dinamica;
		Nodo *sig;
	
	public:
		Nodo();
		Nodo(Estudiante *,Nodo *);
		void set_estudiante(Estudiante *);
		void set_siguiente(Nodo *);
		Nodo *get_siguiente();
		Estudiante *get_estudiante();
};
class PilaDinamica
{
	private:
		Nodo *tope;
	public:
		PilaDinamica();
		void push(Estudiante *);
		Estudiante* pop();//Extrae (devuelve y elimina) al “dato” que se encuentra en “tope”
		Estudiante* top();//devuelve el ultimo elemnto
		int get_cont();
};

#endif

