#include "Menu.h"

int Menu::principalMenu(){
	int opc;
	cout<<"\n\t------ Proyecto cola ------"<<endl;
	cout<<"\t 1. Agregar caciones al arreglos de canciones"<<endl;
	cout<<"\t 2. Encolar en cola estatica"<<endl;
	cout<<"\t 3. Encolar en cola dinamica"<<endl;
	cout<<"\t 4. Mostrar cancion al frente de la cola"<<endl;
	cout<<"\t 5. Desencolar cancion de la cola estatica"<<endl;
	cout<<"\t 6. Desencolar canicon de la cola dinamica"<<endl; 
	cout<<"\t    Ingrese opcion"<<endl;
	cin>>opc;
	return opc;
}
