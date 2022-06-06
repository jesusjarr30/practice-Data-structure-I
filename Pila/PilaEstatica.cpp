#include "PilaEstatica.h">
#include <conio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
void PilaEstatica::inicializar(){
	tope=-1;
}
int PilaEstatica::vacia(){
	return tope==-1;
}

bool PilaEstatica::llena(){
	return tope==9;
}
void PilaEstatica::push(Estudiante e){
	int pos=0;
	if( llena() )
		return;
	tope++;
	for(int i=tope;i>pos;i--)
		Estatica[i]=Estatica[i-1];
	Estatica[pos]=e;	
}

Estudiante* PilaEstatica::pop(){
	Estudiante *aux;
	aux=new Estudiante;
	aux=&Estatica[0];
	for(int i=0;i<tope;i++)
	{
		Estatica[i]=Estatica[i+1];
	}
	tope--;
	return aux;
}
Estudiante* PilaEstatica::top(){
	Estudiante* aux;
	aux =new Estudiante;
	aux=&Estatica[0];
	return aux;
}

int PilaEstatica::get_cont(){
	return tope;
}
