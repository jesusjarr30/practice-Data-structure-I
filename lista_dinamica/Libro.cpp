#include "Libro.h"
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;
Libro::Libro(){
	nombre="";
	nombre;
	autor="";
	editorial="";
	isbn="";
	categoria="";
	categoria_secundaria="";
	disponibles=0;
	precio=0;
	ventas=0;
}
Libro::Libro(string _nombre,string _autor, string _editorial,string _isbn,string _categoria,string _categoria_secundaria,int _disponibles,float _precio,int _ventas){
	nombre = _nombre;
	autor= _autor;
	editorial = _editorial;
	isbn = _isbn;
	categoria = _categoria;
	categoria_secundaria =_categoria_secundaria;
	precio = _precio;
	disponibles = _disponibles;
	ventas = _ventas;
}
void Libro::print(){
	cout<<"\t\tNombre libro:        "<<nombre<<endl;
	cout<<"\t\tAutor:               "<<autor<<endl;
	cout<<"\t\tEditorial:           "<<editorial<<endl;
	cout<<"\t\tISBN:                "<<isbn<<endl;
	cout<<"\t\tCategoria:           "<<categoria<<endl;
	cout<<"\t\tCategoria secundaria:"<<categoria_secundaria<<endl;
	cout<<"\t\tPrecio:              "<<precio<<endl;
	cout<<"\t\tDisponibles:         "<<disponibles<<endl;
	cout<<"\t\tRank:                "<<ventas<<endl;
	cout<<"-----------------------------------------------------"<<endl;
}
void Libro::print_m(){
	cout<<"\t\t1. Nombre libro:        "<<nombre<<endl;
	cout<<"\t\t2. Autor:               "<<autor<<endl;
	cout<<"\t\t3. Editorial:           "<<editorial<<endl;
	cout<<"\t\t4. Categoria:           "<<categoria<<endl;
	cout<<"\t\t5. Categoria secundaria:"<<categoria_secundaria<<endl;
	cout<<"\t\t6. Precio:              "<<precio<<endl;
	cout<<"\t\t7. Disponibles:         "<<disponibles<<endl;
	cout<<"-----------------------------------------------------"<<endl;
}


void Libro::nombre_set(string cadena){
	nombre = cadena;
}
void Libro::editorial_set(string cadena){
	editorial = cadena;
}
void Libro::categoria_set(string cadena){
	categoria = cadena;
}
void Libro::categoria_secundaria_set(string cadena){
	categoria_secundaria = cadena;
}
void Libro::disponibles_set(int numero){
	disponibles = numero;
}
void Libro::precio_set(float numero){
	precio = numero;
}
void Libro::autor_set(string cadena){
	autor = cadena;
}
int Libro::nombre_validacion(char cadena[100]){
	int z,longitud,i,longitud2;
	char buffer[100];
	char primero;
	longitud=strlen(cadena);
	strcpy(buffer,nombre.c_str());
	longitud2=strlen(buffer);
	
	i=0;
	primero=cadena[0];
	while(i<longitud2)
	{
		if(buffer[i]==primero)
		{
			if(strncmp(buffer,cadena,longitud)==0)
			return 0;
		}
		i++;
	}
	return 1;
}
int Libro::isbn_validacion(string cadena){
	 int x;
	 x=isbn.compare(cadena);
	 return x;
}
int Libro::recupera_disponibles()
{
	return disponibles;
}
void Libro::ventas_aumento(int venta){
	disponibles=disponibles-venta;
	ventas=ventas+venta;
}
string Libro::recupera_isbn(){
	return isbn;
}





