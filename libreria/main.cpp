/*Rodriguez Renteri Jesus Alejandro
Materia: estrucura de daros 	seccion D08*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "Libro.h"
#include "Lista.h"
using namespace std;
int main() {
	char opc[10],opc2[10];
	int opcv,opcv2;
	int band=0;
	int x;
	string nombre;
	string autor;
	string editorial;
	string isbn;
	string categoria;
	string categoria_secundaria;
	int disponibles;
	float precio;
	int ventas;
	string codigo;
	Libro aux;
	Lista a;
	a.inicializar();
	
	do{
	cout<<"\n\t------Bienvenido a la libreria------"<<endl;
	cout<<"\t\t\tMenu"<<endl;
	cout<<"\t1. Ingresar nuevo libro"<<endl;
	cout<<"\t2. Buscar y mostrar"<<endl;
	cout<<"\t3. Modificar informacion del libro"<<endl;
	cout<<"\t4. Ventas"<<endl;
	cout<<"\t5. Mostrar todo"<<endl;
	cout<<"\t6. crea automatico"<<endl;
	cout<<"\t7. Salir\n\t";
	fflush(stdin);
	cin>>opc;
	opcv=atoi(opc);
	system("cls");
	if(opcv!=0){
		switch (opcv)
		{
			case 1:
				cout<<"\n\tRegistrar nuevo libro"<<endl;
				fflush(stdin);
				cout<<"\n\tIngrese ISBN"<<endl;
				getline(cin,isbn);		
				x=a.comparar_isbn(isbn);
				 if(x!=0)
				 {
				 	fflush(stdin);
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
				 	aux.set(nombre,autor,editorial,isbn,categoria,categoria_secundaria,precio,disponibles,0);
					a.agregar(aux,0);
				 	
				 }
				 else
				 {
				 	cout<<"el ISBN "<<isbn<<" ya se encuentra en uso por lo cual tendra que utilizar uno distinto"<<endl;
				 	system("pause");
				 	system("cls");
				 	break;
				 }
				fflush(stdin);	
				system("cls");
				break;
			fflush(stdin);	
			case 2:
				cout<<"\n\tBusqueda"<<endl;
				cout<<"\t1. ISBN"<<endl;
				cout<<"\t2. Nombre"<<endl;
				cin>>opc2;
				opcv2=atoi(opc2);
				system("cls");
				switch (opcv2)
				{
					case 1:
						int posicion;
						cout<<"\n\tIngrese ISBN del libro que desea buscar"<<endl;
						fflush(stdin);
						getline(cin,codigo);
						posicion=a.busqueda(codigo);
						system("cls");	
					break;
					case 2:
						int caracteres;
						char cadena[100];
						cout<<"\n\tIngrese Nombre del libro que desa buscar"<<endl;
						fflush(stdin);
						cin.getline(cadena,100,'\n');
						a.comparar_nombre(cadena);		
					break;
				}
				break;
			case 3:
				int posicion;
				system("cls");
				cout<<"\t\tModificar informacion"<<endl;
				cout<<"\n\tIngrese ISBN del libro que desea modificar"<<endl;
				fflush(stdin);
				getline(cin,codigo);
				posicion=a.busqueda(codigo);
				if(posicion!=-1)
				do{
				a.print_modificar(posicion);
				cout<<"\t\tModificar informacion"<<endl;
				cout<<"\t1.nombre"<<endl;
				cout<<"\t2.autor"<<endl;
				cout<<"\t3.editorial"<<endl;
				cout<<"\t4.categoria"<<endl;
				cout<<"\t5.categoria secundaria"<<endl;
				cout<<"\t6.disponibles "<<endl;
				cout<<"\t7.precio"<<endl;
				cout<<"\t8. Salir\n\t";
				cout<<"\tIngrese opcion\n\t";
				cin>>opc2;
				opcv2=atoi(opc2);
				system("cls");
				switch (opcv2)
				{
					case 1:
						system("cls");
						cout<<"\n\tIngrese nuevamente el nombre del libro"<<endl;
						fflush(stdin);
						getline(cin,nombre);
						cout<<"\n\tNombre registrado con exito"<<endl;
						a.modificar(1,nombre,posicion,0);
						system("pause");
						system("cls");
						break;
					case 2:
						system("cls");
						cout<<"\n\tIngrese nuevamente el autor del libro"<<endl;
						fflush(stdin);
						getline(cin,autor);
						cout<<"\n\tRegistro con exito"<<endl;
						a.modificar(2,autor,posicion,0);
						system("pause");
						system("cls");
						break;
					case 3:
						system("cls");
						cout<<"\n\tIngrese nuevamente la editorial del libro"<<endl;
						fflush(stdin);
						getline(cin,editorial);
						cout<<"\n\tRegistro con exito"<<endl;
						a.modificar(3,editorial,posicion,0);
						system("pause");
						system("cls");
						break;
					case 4:
						system("cls");
						cout<<"\n\tIngrese nuevamente la categoria del libro"<<endl;
						fflush(stdin);
						getline(cin,categoria);
						cout<<"\n\tRegistro con exito"<<endl;
						a.modificar(4,categoria,posicion,0);
						system("pause");
						system("cls");
						break;
					case 5:
						system("cls");
						cout<<"\n\tIngrese nuevamente la categoria secundaria del libro"<<endl;
						fflush(stdin);
						getline(cin,categoria_secundaria);
						cout<<"\n\tRegistro con exito"<<endl;
						a.modificar(5,categoria_secundaria,posicion,0);
						system("pause");
						system("cls");
						break;
					case 6:
						system("cls");
						cout<<"\n\tIngrese nuevamente cantidad de ejemplares en tienda"<<endl;
						fflush(stdin);
						cin>>disponibles;
						cout<<"\n\tRegistro con exito"<<endl;
						a.modificar(6,nombre,posicion,disponibles);
						system("pause");
						system("cls");
						break;
					case 7:
						system("cls");
						cout<<"\n\tIngrese nuevamente el precio del libro"<<endl;
						fflush(stdin);
						cin>>precio;
						cout<<"\n\tRegistro con exito"<<endl;
						a.modificar(7,nombre,posicion,precio);
						system("pause");
						system("cls");
						break;	
				}
				if(opcv2==0 || opcv2>=9)
				{
					system("cls");
					cout<<"Ingrese Datos correctos"<<endl;
					system("pause");
					system("cls");
				}
			}while(opcv2!=8);
			break;
			case 4:
				int opcventas;
				char opcventasv[10];
				//VENTAS
				system("cls");
				cout<<"\n\tVentas"<<endl;
				cout<<"\n\t1.Busqueda por ISBN"<<endl;
				cout<<"\n\t2.Busqeuda por Nombre"<<endl;
				cin>>opcventasv;
				opcventas=atoi(opcventasv);
					switch (opcventas)
						{
						case 1:
							system("cls");
							fflush(stdin);
							cout<<"\n\t Ingrese ISBN"<<endl;
							
							 getline(cin,codigo);
							 a.ventas_isbn(codigo);
							 
							break;
						case 2:
							char cadena[100];
							cout<<"\n\tIngrese Nombre del libro que desea comprar"<<endl;
							fflush(stdin);
							cin.getline(cadena,100,'\n');
							a.vender_por_nombre(cadena);
							break;
						}
						system("cls");
				break;
			case 5:
				cout<<"\n\t Mostrar todo\n"<<endl;
				cout<<"---------------------------"<<endl;
				a.print();
				
				
				break;
			case 6:
				//Solo puede genererse una vez en todo el programa
				
				if(band==0)
				{
				cout<<"\tCreacion de libros automatico"<<endl;
				cout<<"\n\t Se generaron 10 libros automaticamente\n\n\n"<<endl;
				
				aux.set("Vendedor del silencio","Serena Enrique","Alfaguara","9077","Literarura","Narrativa",100,10,0);
				if(a.comparar_isbn("9077")==1)
					a.agregar(aux,0);
				aux.set("El comediante del rey","Juan Gonzales","Aguilar","1597","Comedia","politica",200,10,0);
				if(a.comparar_isbn("1597")==1)
					a.agregar(aux,0);
				aux.set("Partials","Dan wells","Vergara y Riba","2546","ciencia ficcion","jovenes",500,5,0);
				if(a.comparar_isbn("2546")==1)
					a.agregar(aux,0);
				aux.set("El arte de la guerra","Arturo Martinez","Aguilar","2563","Literatura clasica","historia",350,15,0);
				if(a.comparar_isbn("2563")==1)
					a.agregar(aux,0);
				aux.set("Guerra de las dos rosas","Iggulden conn","Duomo","1235","Literatura","Narrativa",420,4,0);
				if(a.comparar_isbn("1235")==1)
				a.agregar(aux,0);
				aux.set("Chica salveje","Owens Delia","Atico de los libros","5689","Literatura","Novela",395,7,0);
				if(a.comparar_isbn("5689")==1)
				a.agregar(aux,0);
				aux.set("Los proyectos Manthattan","Jonathan hickman","Planeta deagostini comics","48965","cienccia ficcion","Drama",1000,3,0);
				if(a.comparar_isbn("48965")==1)
				a.agregar(aux,0);
				aux.set("Un asesinato corriente y otros relatados","P.D James","B de books","1564","lieratura","cuentos",119,50,0);
				if(a.comparar_isbn("1564")==1)
				a.agregar(aux,0);
				aux.set("El pasilllo estrecho","Acemoglu/Robinson","Critica","6987","comedia","politica",499,2,0);
				if(a.comparar_isbn("6987")==1)
				a.agregar(aux,0);
				aux.set("El traidor. El diario secreto del hijo de mayo","Hernandez Anabel","Grijalbo","8798","Novela","drama",299,17,0);
				if(a.comparar_isbn("8798")==1)
				a.agregar(aux,0);
				band++;
			}
			else
			{
			system("cls");
			cout<<"\n\t No es posible acceder nuevamente a este apartado\n\n"<<endl;
			}
				system("pause");
				system("cls");
				break;
		}
	}

	if(opcv<=0 || opcv>=8)
	{
	cout<<"\n\tIngrese datos validos"<<endl;
	system("pause");
	system("cls");
	}
}while(opcv!=7);
	cout<<"Exito!"<<endl;
	return 0;
}
