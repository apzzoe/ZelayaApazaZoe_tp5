#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
	int dato;
	pnodo siguiente;
};

void iniciar_lista(pnodo &lista){
	lista = NULL;
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

void agregar_inicio(pnodo &lista, pnodo nuevo){
	nuevo -> siguiente = lista;
	lista = nuevo;
}

void agregar_final(pnodo &lista, pnodo nuevo){
	pnodo i;
	if(lista == NULL){
		lista = nuevo;
	}
	else{
		for(i = lista; i->siguiente != NULL;
		i=i->siguiente);
		i->siguiente = nuevo;
	}
}

void mostrar(pnodo lista){
	pnodo i;
	if(lista != NULL){
		for(i = lista; i != NULL; i = i->siguiente){
		cout<<"Nodo: " << i->dato << endl;
		}
	}
	else{
		cout<<"Lista vacía";
	}
}

pnodo extraer_minimo(pnodo &lista){
	pnodo i, ant_min = NULL, min = lista;
	if(lista == NULL){
		return NULL;
	}
	i = lista;
	while(i->siguiente != NULL){
		if(i->siguiente->dato < min->dato){
			min = i->siguiente;
		    ant_min = i;
	    }
		i = i->siguiente;
    }
	if(min == lista){
		lista = lista->siguiente;
	}
	else{
		ant_min->siguiente = min->siguiente;
	}
	min->siguiente = NULL;
	return min;
}
	int main(){
		pnodo lista;
		iniciar_lista(lista);
		int cantidad;
		cout<<"¿Cuántos nodos desea crear? ";
		cin>>cantidad;
		pnodo nuevo;
		for(int i = 0; i < cantidad; i++){
			crear_nodo(nuevo);
			agregar_final(lista, nuevo);
		}
		
		cout << "\nLista actual:\n";
		mostrar(lista);

		pnodo min = extraer_minimo(lista);
		if(min != NULL){
			cout<<"\nMínimo extraído: "<<min->dato<<endl;
			delete min;
		}

		cout<<"\nLista luego de extraer mínimo:\n";
		mostrar(lista);
	}
