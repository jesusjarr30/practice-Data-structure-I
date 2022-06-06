#include "Estudiante.h"
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;
Estudiante::Estudiante(){
	 	 codigo=0;
    	 nombre="";
    	 ingreso=0;
    	egresado=0;
}
void Estudiante::set(int codigo_,string nombre_, int ingreso_, bool egresado_){
	this -> codigo=codigo_;
	this ->nombre=nombre_;
	this ->ingreso=ingreso_;
	this ->egresado=egresado_;
}
Estudiante::Estudiante(int codigo_,string nombre_, int ingreso_, bool egresado_)
{
	codigo=codigo_;
	nombre=nombre_;
	ingreso=ingreso_;
	egresado=egresado_;
}
void Estudiante::print(){
	cout<<"-----------------------------------------"<<endl;
	cout<<"Imprimir solo prueba"<<endl;
	cout<<"codigo"<<codigo<<endl;
	cout<<"Nombre"<<nombre<<endl;
	cout<<"ingreso"<<ingreso<<endl;
	cout<<"egreso"<<egresado<<endl;
}
int Estudiante::get_codigo(){
	return codigo;
}
string Estudiante::get_nombre(){
	return nombre;
}
int Estudiante::get_ingreso(){
	return ingreso;
}
bool Estudiante::get_egresado(){
	return egresado;
}
bool Estudiante::operator ==(Estudiante &e){
	
	if(this ->codigo==e.get_codigo())
		if(this ->nombre == e.get_nombre())
		 if(this ->ingreso == e.get_ingreso())
		 	if(this->egresado == e.get_egresado())
		 		return true;
	return false;	 		
	
}

