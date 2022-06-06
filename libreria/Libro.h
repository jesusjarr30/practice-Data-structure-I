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
		void set(string _nombre,string _autor, string _editorial,string _isbn,string _categoria,string  _categoria_secundaria,float _precio,int _disponibles,int _ventas);
		void print();
		int isbn_validacion(string);
		void nombre_set(string);
		void autor_set(string);
		void editorial_set(string);
		void isbn_set(string);
		void categoria_set(string);
		void categoria_secundaria_set(string);
		void disponibles_set(int);
		void precio_set(int);
		int nombre_validacion(char*);
		int recupera_disponibles();
		void ventas_aumento(int);	
};

#endif
