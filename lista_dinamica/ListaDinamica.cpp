#include "ListaDinamica.h"
#include "Libro.h"
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
using namespace std;
Nodo::Nodo()
{
	Biblioteca = NULL;
	sig = NULL;
}
Nodo::Nodo(Libro * lib,Nodo *Sig)
{
	Biblioteca = lib;
	sig =Sig;
}
void Nodo::setlibro(Libro *lib)
{
	Biblioteca = lib;	
}
void Nodo::setsiguiente(Nodo *Sig)
{
	sig = Sig;
}
Nodo *Nodo::getsiguiente()
{
	return sig;
}
Libro *Nodo::getlibro()
{
	return Biblioteca;	
}
ListaDinamica::ListaDinamica()
{
	primero=NULL;
}
void ListaDinamica::ingresalib(Libro *lib)
{
	primero=new Nodo(lib, primero);
}
string ListaDinamica::tostrign()
{
	Nodo *p = primero;
	while(p!=NULL){
			cout<<"\t\tDireccion de memoria \t"<<p<<endl;
			p-> getlibro() -> print();
			p=p->getsiguiente();
		}
		return ".";
}
void ListaDinamica::ingresalibu(Libro *lib){
	Nodo *p = primero;
	Nodo *nuevo;
	if(p==NULL)
	{
		ingresalib(lib);
			}
	else{
		while(p->getsiguiente() !=NULL){
			p=p->getsiguiente();
		}
		nuevo=new Nodo(lib,NULL);
		p->setsiguiente(nuevo);
	}
}
ListaDinamica::~ListaDinamica()
{
	Nodo *p=primero;
	Nodo *ac;
	while(p != NULL){
		ac = p->getsiguiente();
		delete p;
		p=ac;
	}
	primero = NULL;
}
void ListaDinamica::elimina_isbn(string cadena){
	Nodo *p = primero;
	Nodo *aux=NULL;
	if(p != NULL){
		while(p!= NULL && p->getlibro()->recupera_isbn()!=cadena){
			aux=p;
			p=p->getsiguiente();
			cout<<"Registro eliminado con exito"<<endl;
			system("pause");
		}
		if(p==NULL){
			cout<<"No se encontro el isbn intente de nuevo"<<endl;
			system("pause");
		}
		else{
			if(aux==NULL){
					primero=p->getsiguiente();
				}
				else{
					aux->setsiguiente(p->getsiguiente());	
				}
				delete p;	
		}
	}
}
void ListaDinamica::lista_vacia(){
	Nodo *aux=primero;
	if(aux == NULL)
	{
		system("cls");
		cout<<"La lista se encuentra vacia"<<endl;
		system("pause");
	}
	else{
		cout<<"\n\t\tLa lista no se encuentra vacia"<<endl;
		system("pause");
	}
}
void ListaDinamica::mostrar_primero(){
		Nodo *p = primero;
	if(p!=NULL){
		cout<<"\n\t\tEl pirmer el elemto de la lista es:"<<endl;
		cout<<"\t\tDireccion de memoria \t"<<p<<endl;
			p-> getlibro() -> print();
			system("pause");
		}
	else 
	{
		cout<<"\n\t\tNo existen elementos en la lista"<<endl;
		system("pause");
		}
}
void ListaDinamica::mostrar_ultimo(){
	int band=0;
	Nodo *p = primero;
	while(p!=NULL){
		system("cls");
			cout<<"\t\tDireccion de memoria \t"<<&p<<endl;
			p-> getlibro() -> print();
			p=p->getsiguiente();
			band=1;
		}
		if(band==0)
		cout<<"\n\t\tNo hay elementos en la lista"<<endl;
		system("pause");
}
void ListaDinamica::mostrar_ficha_libro(string cadena){
	Nodo *p=primero;
	Nodo *aux=NULL;
	int band;
	band=0;
	if(p != NULL){
		while(p!= NULL && p->getlibro()->recupera_isbn()==cadena){
			aux=p;
			p=p->getsiguiente();
			band=1;
			
		}
		if(band==1){
			aux->getlibro()->print();
		}
		if(band==0){
			cout<<"NO se encontro el libro "<<endl;
			
		}
		system("pause");
	}
}
int ListaDinamica::validacion_isbn(string cadena){
	Nodo *p=primero;
	int band=0;
	if(p==NULL)
	return 0;
	while(p!=NULL){
		if(p->getlibro()->recupera_isbn()==cadena)
		{
			band=1;
		}
		p=p->getsiguiente();
		}
	return band;
}
void ListaDinamica::modificar_libro(string cadena){
	Nodo *p=primero;
	Nodo *aux=NULL;//almacena la dirrecion de memoria en dado caso de encontrar el objeto
	int band=0;
	string aux_cadena;
	int aux_num;
	float num2;
	int opc;
	if(p != NULL){
		while(p!= NULL && p->getlibro()->recupera_isbn()==cadena){
			aux=p;
			p=p->getsiguiente();
			band=1;
			
		}
		if(band==1){
			system("cls");
			cout<<"\t\tDireccion de memoria"<<aux<<endl;
			aux->getlibro()->print_m();
			cout<<"\n\tIngrese la opcion que desea modificar"<<endl;
			cin>>opc;
			switch (opc)
				{
				case 1://Modifica nombre
				fflush(stdin);
					cout<<"\t\tIngrese correcion el nombre\n\t\t";
					getline(cin,aux_cadena);
					aux->getlibro()->nombre_set(aux_cadena);
					break;
				case 2://modifica autor
				fflush(stdin);
					cout<<"\t\t Ingrese autor\n\t\t";
					getline(cin,aux_cadena);
					aux->getlibro()->autor_set(aux_cadena);
				break;
				
				case 3://modifica editorial
						fflush(stdin);
						cout<<"\t\t Ingrese editorial\n\t\t";
						getline(cin,aux_cadena);
						aux->getlibro()->editorial_set(aux_cadena);
				break;
				
				case 4://modifica categoria
					fflush(stdin);
					cout<<"\t\t Ingrese categoria\n\t\t";
					getline(cin,aux_cadena);
					aux->getlibro()->categoria_set(aux_cadena);
				break;
				case 5://modificar categoria secudaria
					fflush(stdin);			
					cout<<"\t\t Ingrese categoria secundaria\n\t\t";
					getline(cin,aux_cadena);
					aux->getlibro()->categoria_secundaria_set(aux_cadena);
				break;
				case 6://modificar precio
					fflush(stdin);
					cout<<"\t\t Ingrese precio\n\t\t";
					cin>>num2;
					aux->getlibro()->precio_set(num2);
				break;
				case 7://modificar ejemplares disponibles
					fflush(stdin);
					cout<<"\t\t Ingrese numero de ejemplares\n\t\t";
					cin>>aux_num;
					aux->getlibro()->disponibles_set(aux_num);
				break;
			}
			cout<<"\n\t\t Cambio realizado con exito"<<endl;
		}
		if(band==0){
			cout<<"NO se encontro el libro "<<endl;		
		}
		system("pause");
	}
}
int ListaDinamica::anterior(int pos)
{
	int x=-1;
	Nodo *p;
	Nodo *aux=NULL;
	int cont=-1;
	p=primero;
	if(p==NULL || pos==0)
	{
		cout<<"No hay elemnto anterior"<<endl;
		system("pause");
		return 0;
	}
	while(p!=NULL){
		cont++;
		p=p->getsiguiente();
		}
		p=primero;	
	if(pos>=1 && pos<=cont)
	{pos--;
	cout<<"Segundo if"<<endl;
			if(pos<=cont)
			{
				p=primero;
				while(x<pos)
				{
				p->getlibro();
				aux=p;
				cout<<"aux"<<aux<<endl;
				p=p->getsiguiente();
				x++;
				}
				cout<<"Termino segundo bucle while"<<endl;
				aux->getlibro()->print();
				cout<<"Impresio"<<endl;
				}
		}
	else
	cout<<"No hay tantos elementos"<<endl;
	system("pause");
}
int ListaDinamica::posicion_siguiente(int pos){
	int x=-1;
	Nodo *p=primero;
	Nodo *aux=NULL;
	int cont=-1;
	while(p!=NULL)
	{
		p->getlibro();
		p=p->getsiguiente(); 
		aux=p;
		cont++;
	}
	p=primero;
	if(pos<=cont)
	while(x<=pos)
	{
		p->getlibro();
		aux=p;
		p=p->getsiguiente(); 
		x++;
	}
	if(pos<=cont && cont>0)
	{
	aux->getlibro()->print();	
	}	
	else
		cout<<"A ocurrido un error o ingreso posicion que no cuenta con un libro siguiente"<<endl;
		system("pause");
}

