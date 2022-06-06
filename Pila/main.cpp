#include <iostream>
#include "PilaEstatica.h"
#include "PilaDinamica.h"
#include "Estudiante.h"
#include "Menu.h"

using namespace std;

void apilar(PilaEstatica& pE);
void apilar(PilaDinamica& pD);
bool comparaTopes(PilaEstatica& pE, PilaDinamica& pD);
bool encuentraTopeEnPilaEstatica(PilaEstatica& pE, PilaDinamica& pD);
bool encuentraTopeEnPilaDinamica(PilaEstatica& pE, PilaDinamica& pD);


int main()
{
	
    PilaEstatica pE; //pila estática que almacena hasta 10 elementos de tipo Estudiante
    PilaDinamica pD; //pila dinámica que almacena elementos de tipo Estudiante
    Menu menu;
    int opc;

    do{
        opc=menu.menuPrincipal();
        switch(opc){
            case 1:{//apila en la pila estática
                apilar(pE);
                break;
            }
            case 2:{//apila en la pila dinámica
                apilar(pD);
                break;
            }
            case 3:{//evalúa si los topes de las pilas con el mismo.
               bool iguales= comparaTopes(pE, pD); // devuelve "true" si los topes de las pilas son los mismos estudiantes.
                if (iguales)
                    cout<<"los topes son los mismos"<<endl;
                else
                    cout<<"los topes son los diferentes"<<endl;
                    system("pause");
                break;
            }
            case 4:{//desapila elementos de la pila estática, hasta que el tope coincida con el de la pila dinámica, o se vacíe la pila estática.
                 bool exito = encuentraTopeEnPilaEstatica(pE, pD);
                 if (exito)
                     cout<<"los topes son los mismos"<<endl;
                 else
                     cout<<"no se encontro coincidencia, pila estatica vacia."<<endl;
                 break;
            }
            case 5:{//desapila elementos de la pila dinámica, hasta que el tope coincida con el de la pila estática, o se vacíe la pila dinámica.
                bool exito = encuentraTopeEnPilaDinamica(pE, pD);
                if (exito)
                    cout<<"los topes son los mismos"<<endl;
                else
                    cout<<"no se encontro coincidencia, pila dinamica vacia."<<endl;
                break;
            }
        }

    }while ( opc );

    cout << "Exito!" << endl;
    return 0;
}

void apilar(PilaEstatica& pE){
    int codigo;
    string nombre;
    int ingreso;
    bool egresado;

    cout<<"Codigo: ";
    cin>>codigo;
    cout<<"\nNombre (sin espacios): ";
    cin>>nombre;
    cout<<"\nIngreso (numerico):";
    cin>>ingreso;
    cout<<"Egresado (1 = Si, 0 = No):";
    cin>>egresado;
    Estudiante e;
	e.set(codigo, nombre, ingreso, egresado);
	pE.push(e);
}
void apilar(PilaDinamica& pD){
    int codigo;
    string nombre;
    int ingreso;
    bool egresado;

    cout<<"Codigo: ";
    cin>>codigo;
    cout<<"\nNombre (sin espacios): ";
    cin>>nombre;
    cout<<"\nIngreso (numerico):";
    cin>>ingreso;
    cout<<"Egresado (1 = Si, 0 = No):";
    cin>>egresado;
    Estudiante *e;
    e=new Estudiante(codigo,nombre,ingreso,egresado);
   	pD.push(e);

}

bool comparaTopes(PilaEstatica& pE, PilaDinamica& pD){
    return *pE.top() == *pD.top(); // sobrecargar operador == para la clase Estudiante.
}

bool encuentraTopeEnPilaEstatica(PilaEstatica&pE, PilaDinamica& pD){
	while(pE.get_cont()>=0)
	{
	if(*pE.top() == *pD.top())
		return true;
	else
		pE.pop();
	}
	return false;
}

bool encuentraTopeEnPilaDinamica(PilaEstatica&pE, PilaDinamica& pD){
    while(pD.get_cont()>=0)
    {
    	if(*pE.top() == *pD.top())
    		return true;
    	else
    	pD.pop();
	}
	return false;
}
