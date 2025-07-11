#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
	int dato;
	pnodo siguiente;
};
typedef struct tlista{
	pnodo inicio;
	pnodo final;
	int cantidad=0;
};

void iniciar_lista(tlista &lista){
	lista.inicio = NULL;
	lista.final = NULL;
}
	
void crear_nodo(pnodo &nuevo){
	nuevo = new tnodo;
	if(nuevo != NULL){
		cout<<"Ingrese valor: ";
		cin>> nuevo -> dato;
		nuevo -> siguiente = NULL;
	}
	else{
		cout<<"Memoria insuficiente" <<endl;
	}
}

void agregar_final(tlista &lista, pnodo nuevo){
	if(lista.inicio == NULL){
		lista.inicio = nuevo;
		lista.final = nuevo;
	}
	else{
		lista.final->siguiente = nuevo;
		lista.final = nuevo;
	}
	lista.cantidad++;
}

pnodo eliminar_final(tlista &lista){
	pnodo borrado, i;
	if(lista.inicio == NULL){
		borrado = NULL;
	}
	else{
		if(lista.inicio == lista.final){
			borrado = lista.inicio;
			lista.inicio = NULL;
			lista.final = NULL;
		}
		else{
			for(i = lista.inicio; (i->siguiente)->siguiente != NULL; i=i->siguiente){
				borrado = lista.final;
			}
			lista.final = i;
			lista.final->siguiente = NULL;
		}
		lista.cantidad--;
	}
	return borrado;
}

void mostrar(tlista lista){
	pnodo i;
	if(lista.inicio != NULL){
		for(i = lista.inicio; i != NULL; i = i->siguiente){
			cout<<"Nodo: " << i->dato << endl;
		}
	}
	else{
		cout<<"Lista vac�a";
	}
}

int obtener_cantidad(tlista lista){
	return lista.cantidad;
}
	
	int main(){
	tlista lista;
	iniciar_lista(lista);
	pnodo nuevo;
	int cantidad;
	
	cout<<"�Cu�ntos nodos desea crear? ";
    cin>>cantidad;
	
	for(int i = 0; i < cantidad; i++){
		crear_nodo(nuevo);
		agregar_final(lista, nuevo);
	}

	cout<<"\nLista actual:\n";
	mostrar(lista);
	cout<<"\nCantidad de elementos: " << obtener_cantidad(lista)<<endl;

	pnodo borrado = eliminar_final(lista);
	if(borrado != NULL){
		cout<<"\nNodo eliminado: " << borrado->dato<<endl;
		delete borrado;
	}

	cout<<"\nLista luego de eliminar �ltimo nodo:\n";
	mostrar(lista);
	cout<<"\nCantidad de elementos: " << obtener_cantidad(lista)<<endl;
	}
