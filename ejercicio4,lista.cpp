#include<iostream>
using namespace std;

typedef struct nodoPila *pnodoPila;

typedef struct nodoPila{
	int dato;
	pnodoPila siguiente;
};

typedef struct Pila{
	pnodoPila tope;
};

void iniciarPila(Pila &pila){
	pila.tope = NULL;
}
	
bool pilaVacia(Pila pila){
	return pila.tope == NULL;
}
	
void push(Pila &pila, int valor){
	pnodoPila nuevo = new nodoPila;
	nuevo->dato = valor;
	nuevo->siguiente = pila.tope;
	pila.tope = nuevo;
}

int pop(Pila &pila){
	if(pilaVacia(pila)){
		cout<<"Pila vac�a"<<endl;
		return -999;
	}
	int extraido=pila.tope->dato;
	pnodoPila aux=pila.tope;
	pila.tope=pila.tope->siguiente;
	delete aux;
	return extraido;
}

int consultarTope(Pila pila){
	if(pilaVacia(pila)){
		cout<<"Pila vac�a"<<endl;
		return -999;
	}
	return pila.tope->dato;
}

typedef struct nodoCola *pnodoCola;

typedef struct nodoCola{
	int dato;
	pnodoCola siguiente;
};

typedef struct Cola{
	pnodoCola frente;
	pnodoCola final;
	int cantidad;
};

void iniciarCola(Cola &cola){
	cola.frente = NULL;
	cola.final = NULL;
	cola.cantidad = 0;
}

bool colaVacia(Cola cola){
	return cola.frente == NULL;
}

void agregarCola(Cola &cola, int valor){
	pnodoCola nuevo = new nodoCola;
	nuevo->dato = valor;
	nuevo->siguiente = NULL;
    if(colaVacia(cola)){
		cola.frente = nuevo;
		cola.final = nuevo;
	}
	else{
		cola.final->siguiente = nuevo;
		cola.final = nuevo;
	}
	cola.cantidad++;
}

int quitarCola(Cola &cola){
	if(colaVacia(cola)){
	    cout<<"Cola vac�a"<<endl;
		return -999;
	}
	int extraido = cola.frente->dato;
	pnodoCola aux = cola.frente;
	cola.frente = cola.frente->siguiente;
	delete aux;
	cola.cantidad--;
	if(cola.frente == NULL){
		cola.final = NULL;
	}
	return extraido;
}

int consultarFrente(Cola cola){
	if(colaVacia(cola)){
		cout<<"Cola vac�a"<<endl;
		return -999;
	}
	return cola.frente->dato;
}

int obtenerCantidad(Cola cola){
	return cola.cantidad;
}

	int main(){
	Pila pila;
	iniciarPila(pila);
    int cantidadPila, valor;

	cout<<"**PILA**" << endl;
	cout<<"�Cu�ntos elementos desea apilar?: ";
	cin>>cantidadPila;
	for(int i=0;i<cantidadPila;i++){
		cout<<"Ingrese valor para la pila: ";
		cin>>valor;
		push(pila, valor);
	}
    cout<<"Tope de la pila: "<<consultarTope(pila)<<endl;
    cout<<"Elemento extra�do de la pila: "<<pop(pila)<<endl;
	cout<<"Nuevo tope de la pila: "<<consultarTope(pila)<<endl;

	Cola cola;
	iniciarCola(cola);
	int cantidadCola;

	cout<<"\n**COLA**"<<endl;
	cout<<"�Cu�ntos elementos desea encolar?: ";
	cin>>cantidadCola;
	for(int i=0;i<cantidadCola;i++){
		cout<<"Ingrese valor para la cola: ";
		cin>>valor;
		agregarCola(cola, valor);
	}
	cout << "Frente de la cola: " << consultarFrente(cola)<<endl;
	cout << "Elemento extra�do de la cola: " << quitarCola(cola)<<endl;
	cout << "Nuevo frente de la cola: " << consultarFrente(cola)<<endl;
	cout << "Cantidad actual en la cola: " << obtenerCantidad(cola)<<endl;
	}
