#ifndef STATICQUEUE_H
#define STATICQUEUE_H
#include "Song.h"
#include <iostream>
#include <sstream>
using namespace std;

class StaticQueue
{
	private:
		Song catalogo[100];
		int ultimo;
	public:
		StaticQueue();
		void enqueue(Song );
		Song* dequeue();
		Song* first();
		bool vacia();
		bool llena();
		void ingreso(Song);
		int get_ultimo();
};

#endif
