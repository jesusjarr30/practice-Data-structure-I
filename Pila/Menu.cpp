#include "Menu.h"
int Menu::menuPrincipal(){
	
	int opc;
	cout<<"\n\t------ Proyecto Pila ------"<<endl;
	cout<<"1. Apilar pila estatica"<<endl;
	cout<<"2. Apilar pila Dinamica"<<endl;
	cout<<"3. Comparar topes de pila"<<endl;
	cout<<"4. Desapilar elementos de la pila estatica"<<endl;
	cout<<"5. Desapilar elementos de pila dinamica"<<endl;
	cin>>opc;
	return opc;
}
