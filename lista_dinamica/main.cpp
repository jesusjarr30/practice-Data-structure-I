#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "Libro.h"
#include "ListaDinamica.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	//Menu 
	string nombre;
	string autor;
	string editorial;
	string isbn;
	string categoria;
	string categoria_secundaria;
	int disponibles;
	float precio;
	int ventas;
	ListaDinamica *a= new ListaDinamica();
	Libro *lib;
	int opc;
	do{
		system("cls");
	cout<<"\t------Menu principal-----"<<endl;
	cout<<"\t 1. Agregar nuevo."<<endl;
	cout<<"\t 2. Eliminar titulo."<<endl;
	cout<<"\t 3. Mostrar ficha de libro."<<endl;//busqueda por isbn
	cout<<"\t 4. Imprimir todo el catalago."<<endl;
	cout<<"\t 5. Borra todo."<<endl;
	cout<<"\t 6. Metodo clasicos de Lista simplemente ligada"<<endl;
	cout<<"\t 7.Salir"<<endl;
	cout<<"\t Ingrese opcion "<<endl;
	cin>>opc;
	system("cls");
	switch (opc)
		{
			case 1:
				int opc2;
				
				cout<<"\t 1. Insertar al inicio"<<endl;
				cout<<"\t 2. Insertar al final"<<endl;
				cout<<"\t 3. En posicion especifica"<<endl;	
				cout<<"\t Ingrese opcion  "<<endl;
				cin>>opc2;
				switch (opc2)
				{	
				int v;
					system("cls");
					case 1:
					cout<<"\n\tRegistrar nuevo libro"<<endl;
					fflush(stdin);
					cout<<"\n\tIngrese ISBN\n\t";
					getline(cin,isbn);
					fflush(stdin);
					v=a->validacion_isbn(isbn);
					if(v==0)
					{
					 	cout<<"\n\tIngrese nombre del libro\n\t";
					 	getline(cin,nombre);
					 	fflush(stdin);
					 	cout<<"\n\t Ingrese autor\n\t";
					 	getline(cin,autor);
					 	fflush(stdin);
					 	cout<<"\n\t Ingrese editorial\n\t";
					 	getline(cin,editorial);
					 	fflush(stdin);
					 	cout<<"\n\t Ingrese categoria\n\t";
					 	getline(cin,categoria);
					 	fflush(stdin);
					 	cout<<"\n\t Ingrese categoria secundariar\n\t";
					 	getline(cin,categoria_secundaria);
					 	fflush(stdin);
					 	cout<<"\n\t Cantidad de ejemplares en tienda\n\t";
					 	cin>>disponibles;
					 	cout<<"\n\t Precio\n\t";
					 	cin>>precio;
					 	lib=new Libro(nombre,autor,editorial,isbn,categoria,categoria_secundaria,disponibles,precio,0);
					 	a->ingresalib(lib);
					}
					else
					{
						cout<<"\n\t\tYa existe un libro con el mismo isbn intente otra combinacion"<<endl;
						system("pause");
					}
						break;
					case 2:
					cout<<"\n\tRegistrar nuevo libro"<<endl;
					fflush(stdin);
					cout<<"\n\tIngrese ISBN"<<endl;
					getline(cin,isbn);
					fflush(stdin);
					v=a->validacion_isbn(isbn);
					if(v==0)
					{
					 	cout<<"\n\tIngrese nombre del libro\n\t";
					 	getline(cin,nombre);
					 	fflush(stdin);
					 	cout<<"\n\t Ingrese autor\n\t";
					 	getline(cin,autor);
					 	fflush(stdin);
					 	cout<<"\n\t Ingrese editorial\n\t";
					 	getline(cin,editorial);
					 	fflush(stdin);
					 	cout<<"\n\t Ingrese categoria\n\t";
					 	getline(cin,categoria);
					 	fflush(stdin);
					 	cout<<"\n\t Ingrese categoria secundariar\n\t";
					 	getline(cin,categoria_secundaria);
					 	fflush(stdin);
					 	cout<<"\n\t Cantidad de ejemplares en tienda\n\t";
					 	cin>>disponibles;
					 	cout<<"\n\t Precio\n\t";
					 	cin>>precio;
					 	lib=new Libro(nombre,autor,editorial,isbn,categoria,categoria_secundaria,disponibles,precio,0);
					 	a->ingresalibu(lib);
					 }
					 else
					{
						cout<<"\n\t\tYa existe un libro con el mismo isbn intente otra combinacion"<<endl;
						system("pause");
					}
					break;	
					case 3:
					//falta
					break;
				}
				break;
			case 2:
				fflush(stdin);
				cout<<"\n\t\t Eliminar libro por isbn"<<endl;
				cout<<"Ingrese isbn\t";
				getline(cin,isbn);
				a->elimina_isbn(isbn);
				break;
			case 3:
				fflush(stdin);
				cout<<"\n\t\t Mostrar ficha de libros"<<endl;
				cout<<"Ingrese isbn\t";
				getline(cin,isbn);
				a->mostrar_ficha_libro(isbn);
				break;
			case 4:
				a->tostrign();
				system("pause");
				break;
			case 5:
				a->~ListaDinamica();
				cout<<"\n\t\tSe borraron todos los libros registrados "<<endl;
				system("pause");
				system("cls");
				break;
			case 6:
				int opc1;
				cout<<"1. Lista vacia."<<endl;
				cout<<"2. Mostrar todo."<<endl;
				cout<<"3. Mostrar el primero."<<endl;
				cout<<"4. Mostrar el ultimo."<<endl;
				cout<<"5. Mostrar anterior."<<endl;
				cout<<"6. Mostrar siguiente."<<endl;
				cout<<"7. Modificar libro."<<endl;
				cout<<"\t Ingrese opcion"<<endl;
				cin>>opc1;
				system("cls");
				switch (opc1)
					{
						case 1:
							a->lista_vacia();
							break;
						case 2:
							a->tostrign();
							system("pause");
							break;
						case 3:
							a->mostrar_primero();
							break;
						case 4:
							a->mostrar_ultimo();
							break;
						case 5://mostrar anterior
							int posicion;
							cout<<"Mostrar anterior"<<endl;
							cout<<"Ingrese una posicion y se imprimer el libro anterior a este ejemplo indica posicion 2 se le muestra la posicion 1"<<endl;
							cin>>posicion;
							a->anterior(posicion);	
							break;
						case 6:
							int pos2;
							cout<<"Mostrar sigueinte"<<endl;
							cout<<"Ingrese la posicion y se le postrara el elemento sigueinte a esta "<<endl;
							cout<<"Recuerde que se inicia de cero"<<endl;
							cin>>pos2;
							a->posicion_siguiente(pos2);
							break;
						case 7:
							string isbn;
							fflush(stdin);
							cout<<"\n\tModificar libro"<<endl;
							cout<<"\t Ingrese isbn del libro que desea modificar"<<endl;
							getline(cin,isbn);
							a->modificar_libro(isbn);
							break;		
					}
				break;	
		}
	}while(opc!=7);
	cout<<"Exito";
	return 0;
}
