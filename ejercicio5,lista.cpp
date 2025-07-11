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

void ordenar_por_seleccion(tlista &lista){
	pnodo i, j, min;
	for(i = lista.inicio; i != NULL && i->siguiente != NULL; i = i->siguiente){
		min = i;
		for(j = i->siguiente; j != NULL; j = j->siguiente){
			if(j->dato < min->dato){
				min = j;
			}
		}
		if(min != i){
			int temp = i->dato;
			i->dato = min->dato;
			min->dato = temp;
		}
	}
}

void combinar_listas_sin_orden(tlista l1, tlista l2, tlista &resultado){
	iniciar_lista(resultado);
	pnodo i, nuevo;
	for(i = l1.inicio; i != NULL; i = i->siguiente){
		nuevo = new tnodo;
		nuevo->dato = i->dato;
		nuevo->siguiente = NULL;
		agregar_final(resultado, nuevo);
	}
	for(i = l2.inicio; i != NULL; i = i->siguiente){
		nuevo = new tnodo;
		nuevo->dato = i->dato;
		nuevo->siguiente = NULL;
		agregar_final(resultado, nuevo);
	}
}

void combinar_listas_ordenadas(tlista l1, tlista l2, tlista &resultado){
	iniciar_lista(resultado);
	pnodo i = l1.inicio;
	pnodo j = l2.inicio;
	pnodo nuevo;
	while(i != NULL && j != NULL){
		nuevo = new tnodo;
		if(i->dato <= j->dato){
			nuevo->dato = i->dato;
			i = i->siguiente;
		}
		else{
			nuevo->dato = j->dato;
			j = j->siguiente;
		}
		nuevo->siguiente = NULL;
		agregar_final(resultado, nuevo);
	}
	while(i != NULL){
		nuevo = new tnodo;
		nuevo->dato = i->dato;
		nuevo->siguiente = NULL;
		agregar_final(resultado, nuevo);
		i = i->siguiente;
	}
	while(j != NULL){
		nuevo = new tnodo;
		nuevo->dato = j->dato;
		nuevo->siguiente = NULL;
		agregar_final(resultado, nuevo);
		j = j->siguiente;
	}
}

	int main(){
	tlista lista1, lista2, lista_combinada;

    iniciar_lista(lista1);
	iniciar_lista(lista2);

	int cant1, cant2;
	pnodo nuevo;

	cout<<"Ingrese cantidad de elementos para la lista 1: ";
	cin>>cant1;
	for(int i = 0; i < cant1; i++){
		crear_nodo(nuevo);
		agregar_final(lista1, nuevo);
	}

	cout<<"Ingrese cantidad de elementos para la lista 2: ";
	cin>>cant2;
	for(int i = 0; i < cant2; i++){
		crear_nodo(nuevo);
		agregar_final(lista2, nuevo);
	}

	cout<<"\nLista 1:\n";
	mostrar(lista1);
	cout<<"\nLista 2:\n";
	mostrar(lista2);

	ordenar_por_seleccion(lista1);
	ordenar_por_seleccion(lista2);

	cout<<"\nLista 1 ordenada:\n";
	mostrar(lista1);
	cout<<"\nLista 2 ordenada:\n";
	mostrar(lista2);

	combinar_listas_sin_orden(lista1, lista2, lista_combinada);
	cout<<"\nListas combinadas (sin importar orden):\n";
	mostrar(lista_combinada);

	combinar_listas_ordenadas(lista1, lista2, lista_combinada);
	cout<<"\nListas combinadas (ordenadas):\n";
	mostrar(lista_combinada);
	}
