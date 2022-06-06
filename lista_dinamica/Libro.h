#ifndef LIBRO_H
#define LIBRO_H
#include<iostream> 
using namespace std;
class Libro
{
	private:
		string nombre;
		string autor;
		string editorial;
		string isbn;
		string categoria;
		string categoria_secundaria;
		int disponibles;
		float precio;
		int ventas;
	public:
		Libro();
		Libro(string,string,string,string,string ,string,int,float,int);
		void print();
		int isbn_validacion(string);
		void nombre_set(string);
		void autor_set(string);
		void editorial_set(string);
		void isbn_set(string);
		void categoria_set(string);
		void categoria_secundaria_set(string);
		void disponibles_set(int);
		void precio_set(float);
		int nombre_validacion(char*);
		int recupera_disponibles();
		void ventas_aumento(int);
		string recupera_isbn();	
		void print_m();
};

#endif
