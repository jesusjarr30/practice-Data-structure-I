#include "Libro.h"
Libro::Libro(){
	titulo="";
	autor="";
	editorial="";
	isbn="";
	disponibles=0;
	precio=0;
	rank=0;
	prestamo=false;
}
Libro::Libro(string _titulo,string _autor, string _editorial,string _isbn,int _disponibles,float _precio,int _rank,bool _prestamo){
	titulo = _titulo;
	autor= _autor;
	editorial = _editorial;
	isbn = _isbn;
	precio = _precio;
	disponibles = _disponibles;
	rank = _rank;
	prestamo = _prestamo;
}
void Libro::print(){	
	cout<<"\tISBN        "<<isbn<<endl;
	cout<<"\tTitulo      "<<titulo<<endl;
	cout<<"\tAutor       "<<autor<<endl;
	cout<<"\tEditorial   "<<editorial<<endl;
	cout<<"\tDispobibles "<<disponibles<<endl;
	cout<<"\tPrecio      "<<precio<<endl;
	cout<<"\tRank        "<<rank<<endl;
	if (prestamo==true)
		cout<<"\tPrestamo     disponible"<<endl;
	else
		cout<<"\tPrestamo     No disponible"<<endl;
	cout<<"-----------------------------------------------------"<<endl;
}
string Libro::recupera_isbn(){
	return isbn;
}
int Libro::recupera_disponibles(){
	return disponibles;
}
void Libro::aumenta_rank(int vendidos){
	rank=rank+vendidos;
}
void Libro::decrementa_disponibles(int decremento){
	disponibles=disponibles-decremento;
}
string Libro::get_titulo(){
	return titulo;
}
bool Libro::getprestamo(){
	return  prestamo;
}
void Libro::set_prestamo(bool cambio){
	prestamo=cambio;
}
int Libro::get_rank(){
	return rank;
}
string Libro::get_autor(){
	return autor;
}
