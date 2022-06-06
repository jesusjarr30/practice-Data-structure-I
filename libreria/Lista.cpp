#include "Lista.h"
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void Lista::inicializar(){
	ultimo=-1;
}
bool Lista::vacia(){
	return ultimo==-1;
}
bool Lista::llena(){
	return ultimo==99;
}
void Lista::agregar(Libro a,int pos){
	if(llena())
	return;
	ultimo++;
	for(int i=ultimo;i>pos;i--)
		Libros[i]=Libros[i-1];
	Libros[pos]=a;	
}
void Lista::print(){
	for(int i=0;i<=ultimo;i++)
	{
	cout<<"La posicion es "<<i<<endl;
	Libros[i].print();
}
	system("pause");
	system("cls");
}
int Lista::comparar_isbn(string cadena){
	int cont=1,y;
	for(int x=0;x<=ultimo;x++)
	{
		y=Libros[x].isbn_validacion(cadena);
		if(y==0)
		{
		cont=0;
		
		}
	}
	return cont;	
}	
int Lista::busqueda(string cadena){
	int z;
	int w;
	int cont=1,y;
	for(int x=0;x<=ultimo;x++)
	{
		y=Libros[x].isbn_validacion(cadena);
		if(y==0)
		{
		z=x;
		w=y;
		cont=0;
		}
	}	
	if(w==0){
	return z;
	}
	else{
	cout<<"\n\tNo se encontro su libro intente de nuevo"<<endl;
	system("pause");
	system("cls");	
	return -1;
	}		
}
void Lista::modificar(int opcion,string modificar,int z,int numero){
	
	switch (opcion)
	{
		
		case 1:
			Libros[z].nombre_set(modificar);
			break;
		case 2:
			//autor
			Libros[z].autor_set(modificar);
			break;
		case 3:
			//editorial
			Libros[z].editorial_set(modificar);
			break;
		case 4:
			//categoria
			Libros[z].categoria_set(modificar);
			break;
		case 5:
			//categoria secundaria
			Libros[z].categoria_secundaria_set(modificar);
			break;
		case 6:
			//disponibles
			Libros[z].disponibles_set(numero);
			break;
		case 7:
			//precio
			Libros[z].precio_set(numero);
			break;
	}
}
void Lista::print_modificar(int z){
	Libros[z].print();
}
int Lista::comparar_nombre(char *cadena){
		int resultado;
		for(int x=0;x<=ultimo;x++)
		{
			resultado=Libros[x].nombre_validacion(cadena);
			if(resultado==0)
			Libros[x].print();
		}
		cout<<"-----------------------------"<<endl;
		system("pause");
		system("cls");
}
void Lista::ventas_isbn(string codigo){
	int cont=1,y,pos,venta,dis;
	for(int x=0;x<=ultimo;x++)
	{
		y=Libros[x].isbn_validacion(codigo);
		if(y==0)
		pos=x;
		{
		cont=0;
		
		}
	}
	
	if(cont==0)
	{
		Libros[pos].print();
		cout<<"Cuantos libros desea comprar"<<endl;
		cin>>venta;
		dis=Libros[pos].recupera_disponibles();
		if(dis>=venta)
		{	Libros[pos].ventas_aumento(venta);
			cout<<"Extio en la venta"<<endl;
			system("pause");
			system("cls");
		}
		else 
		{
			cout<<"No fue posible realizar la venta"<<endl;
			system("pause");
			system("cls");
		}
		
	}
}
void Lista::vender_por_nombre(char* cadena){
	int resultado,respuesta,numero,dis;
		for(int x=0;x<=ultimo;x++)
		{
			resultado=Libros[x].nombre_validacion(cadena);
			if(resultado==0){
			Libros[x].print();
			cout<<"Desea comprar este libro"<<endl;
			cout<<"1. si 	2.No"<<endl;
			cin>>respuesta;
			system("cls");
			 if(respuesta==1)
			 	{
				 Libros[x].print();	
			 	cout<<"cuantos libros desea comprar"<<endl;
				 cin>>numero;
				 dis=Libros[x].recupera_disponibles();
				 	if(dis>=numero)
				 	{
				 	Libros[x].ventas_aumento(numero);
					cout<<"Extio en la venta"<<endl;
					system("pause");
					system("cls");	
					}
					else
					{
						cout<<"No fue posible realizar la venta"<<endl;
						system("pause");
						system("cls");
					}
					x=ultimo+1;
				 
				 }
			}
		}
		cout<<"-----------------------------"<<endl;
		system("cls");
}
