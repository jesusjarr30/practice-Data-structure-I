#include <iostream>
#include "Menu.h"
#include "Lista.h"
#include "Libro.h"
#include "Pila.h"

using namespace std;

void agregar_titulo(Lista& lista);
void mostrar_titulo(Lista& lista);
void ordenar(Lista& lista);
void vender(Lista& lista);
void prestamo(Lista& lista,Pila& pila);
void devueltos(Lista& lista,Pila& pila);

int main(){
	int opc;
	Menu menu;
	Lista lista;
	Pila pila;
	do{	
		menu.menu();
		cin>>opc;
		system("cls");
		switch(opc){
			
			case 1:
				agregar_titulo(lista);
				break;
			case 2:
				mostrar_titulo(lista);
				break;
			case 3:
				ordenar(lista);	
				break;
			case 4:
				vender(lista);
				break;
			case 5:
				prestamo(lista,pila);
				break;
			case 6:
				devueltos(lista,pila);
				break;
		}
	}while(opc!=0);
	cout<<"Exito"<<endl;
	return 0;
}
void agregar_titulo(Lista& lista){
	Libro* lib;
	string titulo;
	string autor;
	string editorial;
	string isbn;
	int disponibles;
	float precio;
	int rank=0;
	bool prestamo;
	int temp;
	fflush(stdin);
	cout<<"Ingrese isnb "<<endl;
	getline(cin,isbn);
	fflush(stdin);
	if(lista.validacion_isbn(isbn)==0){
		fflush(stdin);
		cout<<"Ingrese titulo   ";
		getline(cin,titulo);
		fflush(stdin);
		cout<<"Ingrese autor      ";
		getline(cin,autor);
		fflush(stdin);
		cout<<"ingrese aditorial   ";
		getline(cin,editorial);
		fflush(stdin);
		cout<<"Ingrese ejemplares disponibles   ";
		cin>>disponibles;
		fflush(stdin);
		cout<<"Ingrese precio de venta   ";
		cin>>precio;
		fflush(stdin);
		cout<<"¿Se cuenta con ejemplares de prestamo?  \n 0.NO 1.SI    ";
		cin>>prestamo;
		fflush(stdin);
		lib=new Libro(titulo,autor,editorial,isbn,disponibles,precio,rank,prestamo);
		lista.inserta(lib);
	}
	else{
		cout<<"El isbn que ingreso ya esta en uso, intente de nuevo"<<endl;
		system("pause");
	}
	system("cls");
}
void mostrar_titulo(Lista& lista){
		cout<<"\tMostrar Titulos\n"<<endl;
	 	lista.tostring();
	 	fflush(stdin);
	 	system("pause");
		
}
void ordenar(Lista& lista){
		int opc;
		cout<<"\t1. Ordenar por titulo"<<endl;
		cout<<"\t2. Ordenar por rank"<<endl;
		cout<<"\t3. ordenar por autor"<<endl;
		cout<<"\t Ingrese opcion\n\t";
		cin>>opc;
		if(opc==1){
		
			lista.bubblesort();
			cout<<"\n\t\tLos titulos ordenados correctamente \n\n\t Consulte mostrar todo para contemplar el acomodo"<<endl;
			system("pause");
		}
		if(opc==2){
			lista.selectionsort();
			cout<<"Los libros fueron acomodados por rank"<<endl;
			system("pause");
		}
		if(opc==3){
			lista.insertionsort();
			cout<<"\n\t\tLos libros se acomodaron por autor correctamente \n\n\t Consulte mostrar todo para contemplar el acomodo"<<endl;
			system("pause");
		}
}
void vender(Lista& lista){
	int opc;
	string busqueda;
	cout<<"\t1. Buscar por titulo"<<endl;
	cout<<"\t2. Buscar por isbn"<<endl;
	cout<<"\t Ingrese opcion\n\t";
	cin>>opc;
	system("cls");
	if(opc==1){
		cout<<"\n\tIngrese titulo del libro que desea buscar\n\t";
		fflush(stdin);
		getline(cin,busqueda);
		lista.busqueda_titulo(busqueda);
	}
	if(opc==2){
		cout<<"\t Ingrese isbn del libro que desea comprar"<<endl;
		fflush(stdin);
		getline(cin,busqueda);	
		fflush(stdin);
		lista.ventas_isbn(busqueda);
		fflush(stdin);
	}
	
}
void prestamo(Lista& lista,Pila& pila){
	int opc;
	string busqueda;
	cout<<"\t1. Prestar(Buscar titulo)"<<endl;
	cout<<"\t2. Prestar (Buscar por isnb)"<<endl;
	cout<<"\t3. Devolver libro"<<endl;
	cout<<"\t Ingrese opcion\n\t";
	cin>>opc;
	fflush(stdin);
	if(opc==1){
		cout<<"\n\tIngrese titulo del libro\n\t";
		getline(cin,busqueda);
		lista.prestamo_titulo(busqueda);
	}
	if(opc==2){
		
		cout<<"\n\tIngrese isbn del libro a prestar\n\t";
		getline(cin,busqueda);
		lista.prestamo_isbn(busqueda);
	}
	if(opc==3){
		cout<<"\t Ingrese isbn del libro que desea devolver"<<endl;
		getline(cin,busqueda);
		lista.devolver_libro(busqueda, pila);
	}
	
}
void devueltos(Lista& lista,Pila& pila){
	int opc;
	Libro *lib;
	string cadena;
	cout<<"\t1. Ver tope"<<endl;
	cout<<"\t2. Acomodar libro"<<endl;
	cout<<"\t3. Acomodar todos"<<endl;
	cout<<"\t Ingrese opcion\n\t";
	cin>>opc;
	system("cls");
	if(opc==1){
		lib=pila.top();
		lib->print();
		
	}
	if(opc==2){
		lib=pila.pop();
		lib->print();
		cadena=lib->recupera_isbn();
		lista.acomodar_libro(cadena);
	}
	if(opc==3){
		lista.acomodar_todo(pila);
	}
	system("pause");
}
