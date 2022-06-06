#include "DynamicQueue.h"

using namespace std;
Nodo::Nodo()
{
	Catalogo = NULL;
	sig = NULL;
}
Nodo::Nodo(Song * s,Nodo *Sig)
{
	Catalogo = s;
	sig =Sig;
}
void Nodo::set_song(Song *s)
{
	Catalogo =s;	
}
void Nodo::set_siguiente(Nodo *Sig)
{
	sig = Sig;
}
Nodo *Nodo::get_siguiente()
{
	return sig;
}
Song *Nodo::get_song()
{
	return Catalogo;	
}
DynamicQueue::DynamicQueue(){
	primero=NULL;
}
void DynamicQueue::enqueue(Song &s){

	string name;
    string interpreter;
    string album;
    float time;
    name=s.get_name();
    interpreter=s.get_interpreter();
    album=s.get_album();
    time=s.get_time();
    Song *so;
    so=new Song(name,interpreter,album,time);
	Nodo *p = primero;
	Nodo *nuevo;
	if(p==NULL)
	{
	primero=new Nodo(so, primero);
			}
	else{
		while(p->get_siguiente() !=NULL){
			p=p->get_siguiente();
		}
		nuevo=new Nodo(so,NULL);
		p->set_siguiente(nuevo);
	}
}
void DynamicQueue::tostrign(){
	Nodo *p = primero;
	while(p!=NULL){
			cout<<"\t\tDireccion de memoria \t"<<p<<endl;
		cout<<"."<<p->get_song()->toString()<<endl; 
			p=p->get_siguiente();
		}
}
Song *DynamicQueue::first(){
	Nodo* p;
	Song* s;
	p=new Nodo();
	if(primero!=NULL){
		p=primero;
	s=p->get_song();
	}
	return s;
}
Nodo *DynamicQueue::get_primero(){
	return primero;
}
Song* DynamicQueue::dequeue(){
	Nodo* p;
	Song* s;
	p=new Nodo();
	if(primero!=NULL){
		p=primero;
		s=p->get_song();
		primero=p->get_siguiente();
	}	
		return s;
}
