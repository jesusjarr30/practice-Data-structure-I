#include "Pila.h"

Pila::Pila(){
	tope=-1;
}
void Pila::push(Libro e){
	int pos=0;
	if(tope==99)//revisar si esta llena
		return;
	tope++;
	for(int i=tope;i>pos;i--)
		pila[i]=pila[i-1];
	pila[pos]=e;
	
}
Libro* Pila::pop(){
	Libro *aux;
	aux=new Libro();
	
	if(tope==-1){
		cout<<"no hay nada en la pila"<<endl;
		return aux;
	}
	*aux=pila[0];
	for(int i=0;i<tope;i++){
		pila[i]=pila[i+1];
	}
	tope--;
	return aux;
}

Libro* Pila::top(){
	Libro* aux;
	aux =new Libro;
	if(tope==-1)//revisar si esta vacia
	{
		cout<<"La pila esta vacia"<<endl;
		return aux;
	}
	aux=&pila[0];
	return aux;
}
int Pila::get_cont(){
	return tope;
}

