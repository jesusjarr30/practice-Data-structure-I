#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H
#include "Libro.h"
#include <iostream>
#include <sstream>
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
class ListaDinamica
{
	private:
		Nodo* primero;
	public:
		ListaDinamica();
		void ingresalib(Libro *);
		void ingresalibu(Libro *);
		string tostrign();
		~ListaDinamica();
		void elimina_isbn(string);
		void lista_vacia();
		void mostrar_primero();
		void mostrar_ultimo();
		void mostrar_ficha_libro(string);
		int validacion_isbn(string);
		void modificar_libro(string);
		int anterior(int);
		int posicion_siguiente(int);
};
#endif
