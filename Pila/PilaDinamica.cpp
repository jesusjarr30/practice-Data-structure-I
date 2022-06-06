#include "PilaDinamica.h"
#include "Estudiante.h"
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;
Nodo::Nodo()
{
	Dinamica = NULL;
	sig = NULL;
}
Nodo::Nodo(Estudiante * e,Nodo *Sig)
{
	Dinamica = e;
	sig =Sig;
}
void Nodo::set_estudiante(Estudiante *e)
{
	Dinamica =e;	
}
void Nodo::set_siguiente(Nodo *Sig)
{
	sig = Sig;
}
Nodo *Nodo::get_siguiente()
{
	return sig;
}
Estudiante *Nodo::get_estudiante()
{
	return Dinamica;	
}
PilaDinamica::PilaDinamica()
{
	tope=NULL;
}
void PilaDinamica::push(Estudiante *e)
{
	tope=new Nodo(e,tope);
}
Estudiante *PilaDinamica::top(){

		if(tope!=NULL)
		{
		Estudiante* aux;
		aux=tope->get_estudiante();
		return aux;
	}
	Estudiante* b;
	b=new Estudiante;
	return b;
}
Estudiante *PilaDinamica::pop(){
	Estudiante* b;
	b=new Estudiante;
	Nodo *p=tope;
	Nodo *aux;
	
	if(p!=NULL){
			tope=p->get_siguiente();
		delete p;
	}
	return b;
}


int PilaDinamica::get_cont(){
	int cont=-1;
	Nodo *p=tope;
	while(p!=NULL)
	{
		cont++;
		p->get_estudiante();
		p=p->get_siguiente();
	}
	return cont;
}
