#include "StaticQueue.h"

StaticQueue::StaticQueue(){
	ultimo==-1;
}
bool StaticQueue::llena(){
	return ultimo==99;
}
bool StaticQueue::vacia(){
	ultimo==-1;
}
void StaticQueue::enqueue(Song s){
		ultimo++;
		string name;
	    string interpreter;
	    string album;
	    float time;
	    name=s.get_name();
	    interpreter=s.get_interpreter();
	    album=s.get_album();
	    time=s.get_time();
	    Song *so;
	    so=new Song(name,interpreter,album,time);
	    //ingreso(*so);
	    catalogo[ultimo]=*so;
		
		
}
void StaticQueue::ingreso(Song s){
	int pos=0;
	if( llena() )
		return;
		ultimo++;
		catalogo[ultimo]=s;
		

}
Song *StaticQueue::first(){
	Song* p;
	p=new Song();
	p=&catalogo[0];
	return p;	
}
int StaticQueue::get_ultimo(){
	return ultimo;
}
Song *StaticQueue::dequeue(){
	Song* p;
	p=new Song();
	if(ultimo>-1)
		{		
			p=&catalogo[0];
			for(int i=0;i<=ultimo;i++)
				catalogo[i]=catalogo[i+1];	
				ultimo--;
		}
		
		return p;
}

