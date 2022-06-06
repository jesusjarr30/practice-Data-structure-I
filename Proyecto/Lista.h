#ifndef LISTA_H
#define LISTA_H
#include "Libro.h"
#include <iostream>
#include <string.h>
#include "Pila.h"
using namespace std;
class Nodo
{
	private:
		Libro *Biblioteca;
		Nodo *sig;
	
	public:
		Nodo();
		Nodo(Libro *,Nodo *);
		void setlibro(Libro *);
		void setsiguiente(Nodo *);
		Nodo *getsiguiente();
		Libro *getlibro();
};
class Lista
{
	private:
		Nodo* primero;
	public:
		Lista();
		~Lista();
		void inserta(Libro *);
		void inserta_alfinal(Libro *);
		int validacion_isbn(string);
		string tostring();
		void ventas_isbn(string);
		void busqueda_titulo(string);
		void venta(Nodo *);
		void prestamo_isbn(string);
		void prestamo_titulo(string);
		void acomodar_libro(string cadena);
		void devolver_libro(string,Pila&);
		void acomodar_todo(Pila&);
		void bubblesort();
		void selectionsort();
		void insertionsort();
		void acomodo_titulo(string [],int);
		void acomodo_autor(string[],int);
};

#endif
