#ifndef LISTA_H
#define LISTA_H
#include "Libro.h"
class Lista
{
private:
	Libro Libros[100];
	int ultimo;
	public:
			void inicializar();
			bool vacia();
			bool llena();
			void print();
			void agregar(Libro,int);
			int comparar_isbn(string);
			int comparar_nombre(char*);
			int busqueda(string);
			void modificar(int,string,int,int);
			void print_modificar(int);
			void ventas_isbn(string);
			void vender_por_nombre(char*);
};

#endif
