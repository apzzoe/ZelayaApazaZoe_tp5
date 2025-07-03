#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	int dato;
	pnodo sig;
	pnodo ant;
};
typedef struct tlista{
	pnodo inicio;
	pnodo fin;
};

void IniciarLista(tlista &lista)
{
	lista.inicio = NULL;
	lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor)
{
	nuevo = new tnodo;
	if(nuevo != NULL)
	{
		nuevo -> dato = valor;
		nuevo -> sig = NULL;
		nuevo -> ant = NULL;
	}
}

void AgregarInicio(tlista &lista, pnodo nuevo)
{
	if(lista.inicio == NULL){
		lista.inicio = nuevo;
		lista.fin = nuevo;
	}
	else{
		nuevo->sig = lista.inicio;
		lista.inicio->ant = nuevo;
		lista.inicio = nuevo;
	}
}

void AgregarFinal(tlista &lista, pnodo nuevo){
	if(lista.inicio == NULL){
		lista.inicio = nuevo;
		lista.fin = nuevo;
	}
	else{
		lista.fin->sig = nuevo;
		nuevo->ant = lista.fin;
		lista.fin = nuevo;
	}
}
	
	void QuitarInicio(){
		pnodo extraido;
		if(lista.inicio == NULL){
			cout<<"la lista ya se encuentra vacía"<<endl;
		}
		else{
			if(lista.inicio == lista.fin){
			extraido = lista.inicio;
			lista.inicio = NULL;
			lista.fin = NULL;
			delete extraido;
		}
			else{
			extraido = lista.inicio;
			lista.inicio = lista.inicio->sig;
			lista.inicio->ant = NULL;
			delete extraido;
		}
		}
	}
	
	void QuitarFinal(){
		pnodo extraido;
		if(lista.fin == NULL){
			cout<<"la lista ya se encuentra vacía"<<endl;
		}
		else{
			if(lista.inicio == lista.fin){
			extraido = lista.fin;
			lista.inicio = NULL;
			lista.fin = NULL;
			delete extraido;
		    }
			else{
			extraido = lista.fin;
			lista.fin = lista.fin->ant;
			lista.fin->sig = NULL;
			delete extraido;
		}
		}
	}
	
	int main(){
		
		return 0;
	}
