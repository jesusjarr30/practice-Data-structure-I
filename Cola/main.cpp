#include <iostream>
#include "StaticQueue.h"
#include "DynamicQueue.h"
#include "Menu.h"
#include "Song.h"

#define N 100

using namespace std;

void addSong(Song songsArray[],int &songsCount);//completar
void enqueue(StaticQueue& staticPlayList,Song songsArray[],int songsCount);//completar
void enqueue(DynamicQueue& dynamicPlayList,Song songsArray[],int songsCount);//completar
void showFronts(StaticQueue& staticPlayList, DynamicQueue& dynamicPlayList);//completar

int main()
{
    StaticQueue staticPlayList;
    DynamicQueue dynamicPlayList;
    Song songsArray[N];
    int songsCount = 0;
    Menu menu;
    int option;

    do{
        option = menu.principalMenu();
        switch(option){
            case 1:{//agregar elemento al arreglo de canciones
            	addSong(songsArray, songsCount);
                break;
            }
            case 2:{// agrega una cancion existente a la cola estática
               	enqueue(staticPlayList, songsArray, songsCount);
                break;
            }
            case 3:{// agrega una cancion existente a la cola dinámica
                enqueue(dynamicPlayList, songsArray, songsCount);
                break;
            }
            case 4:{//muestra la canción que se encuerntra al frente de las colas.
                showFronts(staticPlayList, dynamicPlayList);
                break;
            }
            case 5:{//desencola canción de la playlist estática
                staticPlayList.dequeue();
                break;
            }
            case 6:{//desencola canción de la playlist dinámica
                dynamicPlayList.dequeue();
                break;
            }

        }
    }while(option != 0);
    cout << "Exito!" << endl;
    return 0;
}
void addSong(Song songsArray[],int& songsCount){//completar
    string name;
    string interpreter;
    string album;
    float time;
    cout<<"Nombre: ";
    cin>> name;
    cout<<"Interprete: ";
    cin>> interpreter;
    cout<<"Album:: ";
    cin>> album;
    cout<<"Tiempo: ";
    cin>> time;
    Song s(name, interpreter, album, time);
    if (songsCount < N)
        songsArray[songsCount++] = s;   
}

void enqueue(StaticQueue& staticPlayList,Song songsArray[],int songsCount){//completar
    int selectedIndex;
    cout<<"Selecciona el indice de alguna cancion"<<endl;
    for (int i = 1; i <= songsCount; i++)
       cout<<i<<".- "<<songsArray[i-1].toString()<<endl;
    cin>>selectedIndex;
    if (selectedIndex > 0)
        if (selectedIndex <= N)
          staticPlayList.enqueue(songsArray[selectedIndex-1]);//completar
}

void enqueue(DynamicQueue& dynamicPlayList,Song songsArray[],int songsCount)
{//completar
    int selectedIndex;
    cout<<"Selecciona el indice de alguna cancion"<<endl;
    for (int i = 1; i <= songsCount; i++)
        cout<<i<<".- "<<songsArray[i-1].toString()<<endl;
    cin>>selectedIndex;
    if (selectedIndex > 0)
        if (selectedIndex <= N)
         dynamicPlayList.enqueue(songsArray[selectedIndex-1]);//completar
}

void showFronts(StaticQueue& staticPlayList, DynamicQueue& dynamicPlayList){//completar
	bool res;
	int n;
	Song *p;
    if(staticPlayList.get_ultimo()==-1)
    	cout<<"No hay caciones encoladas en estatico"<<endl;
    else
    	{
    		
    		p=staticPlayList.first();
    		cout<<"Pila Estatica"<<p->toString()<<endl;;
		}
	if(dynamicPlayList.get_primero()==NULL)
		cout<<"No hay canciones encoladas en dinamica"<<endl;
	else{
	p=dynamicPlayList.first();
	cout<<""<<p->toString()<<endl;
	}
}

