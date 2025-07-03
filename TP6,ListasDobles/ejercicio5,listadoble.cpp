#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
	int dato;
	pnodo sig;
	pnodo ant;
};

void IniciarLista(pnodo &inicio){
	inicio = NULL;
}
	
void CrearNodo(pnodo &nuevo, int valor){
	nuevo = new tnodo;
	if(nuevo != NULL){
		nuevo -> dato = valor;
		nuevo -> sig = NULL;
		nuevo -> ant = NULL;
	}
}

void agregar_inicio(pnodo &inicio, pnodo nuevo){
	if(inicio == NULL){
		inicio = nuevo;
	}
	else{
		nuevo -> sig = inicio;
		inicio -> ant = nuevo;
		inicio = nuevo;
	}
}

void AgregarFinal(pnodo &inicio, pnodo nuevo){
	pnodo i;
	if(inicio == NULL){
		inicio = nuevo;
	}
	else{
		for(i = inicio; i -> sig != NULL; i = i -> sig);
		i -> sig = nuevo;
		nuevo -> ant = i;
	}
}
	
void MultiplosdeTres(pnodo inicio){
	pnodo actual = inicio;
	pnodo aux;
	while(actual != NULL){
		if(actual->dato % 3 == 0){
			aux = actual;
			actual = actual->sig;
			if(aux->ant != NULL){
				aux->ant->sig = aux->sig;
		    }
			else{
				inicio = aux->sig;
			}
			if(aux->sig != NULL){
				aux->sig->ant = aux->ant;
			}
			delete aux;
		}
		else{
			actual = actual->sig;
		}
	}
}

void MostrarLista(pnodo inicio){
	pnodo i;
	if(inicio != NULL){
		for(i = inicio; i != NULL; i = i -> sig){
			cout << i -> dato << endl;
		}
	}
}

	int main(){
	pnodo lista;
	IniciarLista(lista);

	int valor, cantidad;
	pnodo nuevo;

	cout<<"cuántos valores desea agregar al inicio de la lista?: ";
    cin>>cantidad;
	for(int i = 0; i<cantidad; i++){
		cout<<"valor: ";
		cin>>valor;
		CrearNodo(nuevo, valor);
		agregar_inicio(lista, nuevo);
	}
	
	cout<<"\ncuántos valores desea agregar al final de la lista? ";
	cin>>cantidad;
	for(int i = 0; i < cantidad; i++){
		cout<<"valor: ";
		cin>>valor;
		CrearNodo(nuevo, valor);
		AgregarFinal(lista, nuevo);
	}

	cout<<"\nlista: "<<endl;
	MostrarLista(lista);

	MultiplosdeTres(lista);

	cout<<"\nlista nueva: "<<endl;
	MostrarLista(lista);
	}
