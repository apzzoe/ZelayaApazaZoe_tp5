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
			for(i = lista.inicio; (i->siguiente)->siguiente != NULL; i=i->siguiente);
				borrado = lista.final;
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
	
int buscar_indice(tlista lista, int valor){
	pnodo i = lista.inicio;
	int indice = 0;
	while(i != NULL){
		if(i->dato == valor){
			return indice;
		}
		i = i->siguiente;
		indice++;
	}
	return -1;
}
	
pnodo buscar_por_indice(tlista lista, int indice){
	if(indice < 0 || indice >= lista.cantidad){
		return NULL;
	}
	pnodo i = lista.inicio;
	int pos = 0;
	while(i != NULL && pos < indice){
		i = i->siguiente;
		pos++;
	}
	return i;
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

	int valor_buscar;
	cout<<"\nIngrese un valor a buscar en la lista: ";
	cin>>valor_buscar;

	int indice = buscar_indice(lista, valor_buscar);
	if(indice != -1){
		cout<<"El valor "<<valor_buscar<<" se encuentra en la posici�n l�gica: "<<indice<<endl;
	}
	else{
	    cout<<"El valor no se encuentra en la lista.\n";
	}

	int posicion;
	cout<<"\nIngrese una posici�n para buscar el nodo: ";
	cin>>posicion;

	pnodo encontrado = buscar_por_indice(lista, posicion);
	if(encontrado != NULL){
		cout<<"En la posici�n "<<posicion<<" se encuentra el valor: "<<encontrado->dato<<endl;
	}
	else{
	    cout<<"No hay ning�n nodo en esa posici�n.\n";
	}
    }
