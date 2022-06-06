#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H
#include "Song.h"
#include <iostream>
#include <sstream>
using namespace std;
class Nodo
{
	private:
		Song *Catalogo;
		Nodo *sig;
	
	public:
		Nodo();
		Nodo(Song *,Nodo *);
		void set_song(Song *);
		void set_siguiente(Nodo *);
		Nodo *get_siguiente();
		Song *get_song();
};
class DynamicQueue
{
	private:
		Nodo *primero;
	public:
		DynamicQueue();
		void enqueue(Song &);
		void tostrign();
		Song* dequeue();
		Song* first();
		Nodo *get_primero();
	
};
#endif
/*se iserta al final se elimina por el frente
Encolar es enqueue que coloca un objeto despues del ultimo elemnto de cola
Desencolar retira el primer elemnto dequeue
*/
