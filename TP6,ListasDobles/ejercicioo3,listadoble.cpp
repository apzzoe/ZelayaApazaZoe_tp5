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

void DecimalaBinario(int numero, pnodo &inicio){
	pnodo nuevo;
	if(numero == 0){
		CrearNodo(nuevo, 0);
		agregar_inicio(inicio, nuevo);
	}
	while(numero > 0){
		int bit = numero % 2;
		CrearNodo(nuevo, bit);
		agregar_inicio(inicio, nuevo); 
		numero = numero / 2;
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
	pnodo binario;
	IniciarLista(binario);

	int numero;
	cout<<"ingrese un numero decimal: ";
	cin>>numero;
	
	DecimalaBinario(numero, binario);
	
	cout<<"\nbinario: "<<endl;
	MostrarLista(binario);
	}
