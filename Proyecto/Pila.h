#ifndef PILA_H
#define PILA_H
#include "Libro.h"
#include <iostream>
using namespace std;
class Pila
{
	private:
		Libro pila[20];
		int tope;
	public:
		Pila();
		void push(Libro);//ingresa libro
		Libro* pop();//extrae y elimina
		Libro* top();//devulve el valor que se encuentra en tope
		int get_cont();
};

#endif
