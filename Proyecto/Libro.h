#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>
#include <sstream>
using namespace std;

class Libro
{
	private:
		string titulo;
		string autor;
		string editorial;
		string isbn;
		int disponibles;
		float precio;
		int rank;
		bool prestamo;
	public:
		Libro();
		Libro(string,string,string,string,int,float,int,bool);
		void print();
		string recupera_isbn();
		int recupera_disponibles();
		void aumenta_rank(int);
		void decrementa_disponibles(int);
		string get_titulo();
		bool getprestamo();
		void set_prestamo(bool);
		int get_rank();
		string get_autor();
};
#endif
