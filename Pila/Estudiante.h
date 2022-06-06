#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <iostream>
using namespace std;
class Estudiante
{
	private:
		int codigo;
    	string nombre;
    	int ingreso;
    	bool egresado;
	public:
	Estudiante();
	Estudiante(int,string,int,bool);
	void set(int codigo_,string nombre_, int ingreso_, bool egresado_);
	void print();
	int get_codigo();
	string get_nombre();
	int get_ingreso();
	bool get_egresado();
	bool operator== (Estudiante &);
};

#endif
