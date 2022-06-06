#include "Lista.h"
Nodo::Nodo()
{
	Biblioteca = NULL;
	sig = NULL;
}
Nodo::Nodo(Libro * lib,Nodo *Sig)
{
	Biblioteca = lib;
	sig =Sig;
}
void Nodo::setlibro(Libro *lib)
{
	Biblioteca = lib;	
}
void Nodo::setsiguiente(Nodo *Sig)
{
	sig = Sig;
}
Nodo *Nodo::getsiguiente()
{
	return sig;
}
Libro *Nodo::getlibro()
{
	return Biblioteca;	
}
Lista::Lista()
{
	primero=NULL;
}
Lista::~Lista(){
	Nodo *p=primero;
	Nodo *ac;
	while(p != NULL){
		ac = p->getsiguiente();
		delete p;
		p=ac;
	}
	primero = NULL;
}
void Lista::inserta(Libro* lib){
	primero=new Nodo(lib, primero);
}
void Lista::inserta_alfinal(Libro* lib){
	Nodo *p = primero;
	Nodo *nuevo;
	if(p==NULL)
	{
		inserta(lib);
			}
	else{
		while(p->getsiguiente() !=NULL){
			p=p->getsiguiente();
		}
		nuevo=new Nodo(lib,NULL);
		p->setsiguiente(nuevo);
	}
}

int Lista::validacion_isbn(string cadena){
	Nodo *p=primero;
	int band=0;
	if(p==NULL)
		return band;
	while(p!=NULL){
		if(p->getlibro()->recupera_isbn()==cadena)
		{
			band=1;
		}
		p=p->getsiguiente();
		}
	return band;
}
string Lista::tostring(){
	Nodo *p = primero;
	while(p!=NULL){
			cout<<"\t\tDireccion de memoria \t"<<p<<endl;
			p-> getlibro() -> print();
			p=p->getsiguiente();
		}
		return ".";
}
void Lista::ventas_isbn(string busqueda){
	Nodo*p=primero;
	Nodo* aux=NULL;
	int ejemplares;
	int recibo;
	while(p!=NULL){
		if(p->getlibro()->recupera_isbn()==busqueda)
				aux=p;
		p=p->getsiguiente();
	}

	if(aux!=NULL){
		aux->getlibro()->print();
		cout<<"\n\tCuantos libros desea comparar \n\t";
		cin>>ejemplares;
		if( aux->getlibro()->recupera_disponibles()>=ejemplares && aux->getlibro()->recupera_disponibles()!=0){
			cout<<"La venta se realizo con exito"<<endl;
			aux->getlibro()->aumenta_rank(ejemplares);
			aux->getlibro()->decrementa_disponibles(ejemplares);
					
		}
		else
		cout<<"\n\t\tno hay sucifientes libros para vender"<<endl;
		
		
		system("pause");
	}
	
}
void Lista::busqueda_titulo(string lib){
	Nodo *p=primero;
	Nodo *aux=NULL;
	string name;
	int inicial;
	int longitud;
	int compra;
	inicial=lib.length();
	
	
	while(p!=NULL){
		system("cls");
		int cont=0;
		for(int i=0;i<inicial;i++){
			name=p->getlibro()->get_titulo();
			if(name[i]==lib[i]){
				cont++;		
			}
		}
		if(inicial==cont){
			aux=p;
			aux->getlibro()->print();
			 cout<<"\n\tDesea comprar este libro?"<<endl;
			cout<<"\n\t1. SI	2.NO\n\t";
			cin>>compra;
			if(compra==1){
			
				venta(aux);
				break;
			}
		}
		p=p->getsiguiente();
	}
}
void Lista::venta(Nodo* p){
	int can;
	cout<<"Cunatos libros quiere comprar?"<<endl;
	cin>>can;
		if( p->getlibro()->recupera_disponibles()>=can && p->getlibro()->recupera_disponibles()!=0){
			cout<<"La venta se realizo con exito"<<endl;
			p->getlibro()->aumenta_rank(can);
			p->getlibro()->decrementa_disponibles(can);			
		}
		else
		cout<<"\n\t\tno hay sucifientes libros para vender"<<endl;
		system("pause");
}
void Lista::prestamo_isbn(string cadena){
	system("cls");
	Nodo *p=primero;
	bool estatus;
	int band=0;
	if(p==NULL)
		cout<<"No hay libros registrados"<<endl;
	while(p!=NULL){
		if(p->getlibro()->recupera_isbn()==cadena)
		{
			cout<<"El libro es "<<endl;
			p->getlibro()->print();
			estatus=p->getlibro()->getprestamo();
			if(estatus==true)
			{
				p->getlibro()->set_prestamo(false);
				cout<<"\n\n\n\tEl prestamo se realizo con exito 'CUIDE EL LIBRO'\n\n"<<endl;

			}
			else
				cout<<"\n\n\tNo se pude realizar el prestamo debido a que no se cuenta con ejemplares en este momento\n\n"<<endl;
				system("pause");
		}
		p=p->getsiguiente();
		}
}
void Lista::prestamo_titulo(string cadena){
	
	Nodo* p=primero;
	Nodo*aux=NULL;
	int longitud;
	string titulo;
	longitud=cadena.length();
	int opc;
	while(p!=NULL){
		system("cls");
		int cont=0;
		titulo=p->getlibro()->get_titulo();
		for(int i=0;i<longitud;i++){
			if(titulo[i]==cadena[i])
				cont++;	
		}
		if(cont==longitud){
			p->getlibro()->print(),
			cout<<"Quiere pedir prestado este libro?"<<endl;
			cout<<"\n\t1. Si	2.No\n\t";
			cin>>opc;
			if(opc==1)
			{
				if(p->getlibro()->getprestamo()==true){
					cout<<"prestamo realizado con exito 'CUIDE EL LIBRO'\n"<<endl;
					p->getlibro()->set_prestamo(false);
					system("pause");
					break;
				}
				else
					cout<<"\n\n\t Lo sentimos no se cuneta con ejemplares de prestamo en este momento\n\n\n"<<endl;
					system("pause");
			}
		}
		p=p->getsiguiente();
	}
}
void Lista::acomodar_libro(string isbn){
	Nodo *p=primero;
	int band=0;
	if(primero==NULL){
		cout<<"No hay libros registrados"<<endl;
		return;
	}
	while(p!=NULL){
		if(p->getlibro()->recupera_isbn()==isbn)
		{
			p->getlibro()->set_prestamo(true);
			cout<<"\n\t\t Se acomodo el libro que se encunetra al tope de la pila"<<endl;
			break;
		}
		p=p->getsiguiente();
		}
}
void Lista::devolver_libro(string cadena, Pila& pila){
	system("cls");
	Nodo *p=primero;
	Libro aux;
	
	if(primero==NULL){
		cout<<"\t No hay libros registrados"<<endl;
		system("pause");
		return;
	}
	while(p!=NULL){
		if(p->getlibro()->recupera_isbn()==cadena)
		{
			aux=*p->getlibro();
			pila.push(aux);
			cout<<"\n\t\tEl libro se regreso correctamente	:)"<<endl;
			system("pause");
			break;
		}
		p=p->getsiguiente();
		}
}
void Lista::acomodar_todo(Pila& pila){
	Nodo *p=primero;
	int band=0;
	string isbn;
	int tope=pila.get_cont();
	if(primero==NULL){
		cout<<"No hay libros registrados"<<endl;
		return;
	}
	
	while(tope>=0){
	isbn=pila.pop()->recupera_isbn();
	while(p!=NULL){
		if(p->getlibro()->recupera_isbn()==isbn)
		{
			p->getlibro()->set_prestamo(true);
		
			break;
		}
		p=p->getsiguiente();
		}
		tope--;
	}
		cout<<"\n\t\t Se acomodaron todos los libros de la pila \n\n\t Consulte mostrar todo para contemplar el acomodo"<<endl;
}
void Lista::bubblesort(){
string BIBLIOTECA[20];
char cadena1[100],cadena2[100];
string aux;
Nodo *p=primero;
int cont=-1;
int comp;
	while(p!=NULL){
		cont++;
		BIBLIOTECA[cont]=p->getlibro()->get_titulo();
		p=p->getsiguiente();	
	}	
	for(int i=0;i<cont;i++)
	for(int j=0;j<cont-i;j++){
		strcpy(cadena1,BIBLIOTECA[j].c_str());
		strcpy(cadena2,BIBLIOTECA[j+1].c_str());
		comp=strcmp(cadena1,cadena2);
		if(comp>0){
			aux=BIBLIOTECA[j];
			BIBLIOTECA[j]=BIBLIOTECA[j+1];
			BIBLIOTECA[j+1]=aux;
		}
	}
	//acomodar
	acomodo_titulo(BIBLIOTECA,cont);//organizar los objetos de tipo libro co		
}
void Lista::acomodo_titulo(string BIBLIOTECA[],int cont){
	Libro contenedor[100];
	int control=-1;
	Nodo *p=primero;
	Nodo *aux;
	Libro *lib;
	int x=0;
	while(p!=NULL){//pasamos los registros a el arreglo
		control++;
		contenedor[control]=*p->getlibro();
		aux=p;
		p=p->getsiguiente();
		delete aux;
	}
	primero=NULL;
	while(cont!=-1){
	
		for(int i=0;i<=control;i++){
			if(BIBLIOTECA[cont]==contenedor[i].get_titulo()){
				lib=new Libro();
				*lib=contenedor[i];
				inserta(lib);
				cont--;
			}
		}	
	}
}
void Lista::selectionsort(){
	Libro contenedor[100];
	Nodo *p=primero;
	Nodo* aux;
	int menor;
	int ultimo=-1;
	Libro *lib;
	while(p!=NULL){
		ultimo++;
		contenedor[ultimo]=*p->getlibro();
		aux=p;
		p=p->getsiguiente();
		delete aux;
		
	}
	primero=NULL;
	for(int i =0;i<ultimo;i++)
	{
		menor=i;
		for(int j=i+1;j<=ultimo;j++)
		{
			if(contenedor[j].get_rank()<contenedor[menor].get_rank())
			menor=j;
			if(i!=menor)
			{
			Libro aux=contenedor[i];
			contenedor[i]=contenedor[j];
			contenedor[j]=aux;
			}
		}	
	}

	for(int i=0;i<=ultimo;i++){
			lib=new Libro();
			*lib=contenedor[i];
			inserta(lib);
	}
	
}
void Lista::insertionsort(){
	int j;
	string BIBLIOTECA[100];
	string aux;
	int ultimo=-1;
	Nodo *p=primero;
	while(p!=NULL){
		ultimo++;
		BIBLIOTECA[ultimo]=p->getlibro()->get_autor();
		p=p->getsiguiente();	
	}
	for(int i=1;i<=ultimo;i++)
	{	aux=BIBLIOTECA[i];
	
	for(j=i;j>0 and aux.compare(BIBLIOTECA[j-1]) < BIBLIOTECA[j-1].compare(aux);j--)
	{
		BIBLIOTECA[j]=BIBLIOTECA[j-1];
	}
	if(i!=j)
	BIBLIOTECA[j]=aux;	
	}
	acomodo_autor(BIBLIOTECA,ultimo);//Una vez acomodado el arreglo de los autores los acomodamos con los objetos de tipo libro
}
void Lista::acomodo_autor(string BIBLIOTECA [],int cont){
	Libro contenedor[100];
	int control=-1;
	Nodo *p=primero;
	Nodo *aux;
	Libro *lib;
	int x=0;
	while(p!=NULL){//pasamos los registros a el arreglo
		control++;
		contenedor[control]=*p->getlibro();
		aux=p;
		p=p->getsiguiente();
		delete aux;
	}
	primero=NULL;
	while(cont!=-1){
	
		for(int i=0;i<=control;i++){
			if(BIBLIOTECA[cont]==contenedor[i].get_autor()){
				lib=new Libro();
				*lib=contenedor[i];
				inserta(lib);
				cont--;
			}
		}	
	}
}


