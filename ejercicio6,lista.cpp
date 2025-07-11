#include <iostream>
using namespace std;

template <typename T>
struct Nodo{
	T dato;
	Nodo<T>* siguiente;
};

template <typename T>
struct Lista{
	Nodo<T>* inicio;
	Nodo<T>* final;
	int cantidad;
};

template <typename T>
void iniciar_lista(Lista<T> &lista){
	lista.inicio = NULL;
	lista.final = NULL;
	lista.cantidad = 0;
}
	
template <typename T>
	void agregar_final(Lista<T> &lista, T valor){
	    Nodo<T>* nuevo = new Nodo<T>;
		nuevo->dato = valor;
		nuevo->siguiente = NULL;
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

template <typename T>
	void mostrar_lista(Lista<T> lista){
		Nodo<T>* i = lista.inicio;
		while(i != NULL){
			cout << i->dato << " ";
			i = i->siguiente;
		}
	}

bool es_primo(int n){
	if(n < 2){
		return false;
	}
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

int contar_primos(Lista<int> lista){
	Nodo<int>* i = lista.inicio;
	int contador = 0;
	while(i != NULL){
		if(es_primo(i->dato)){
			contador++;
		}
		i = i->siguiente;
	}
	return contador;
}
	
void contar_mayus_minus(Lista<char> lista, int &mayus, int &minus){
	mayus=0;
	minus=0;
	Nodo<char>* i = lista.inicio;
	while(i != NULL){
		if(i->dato >= 'A' && i->dato <= 'Z'){
			mayus++;
		}
		else{
			if(i->dato >= 'a' && i->dato <= 'z'){
				minus++;
			}
		}
		i = i->siguiente;
	}
}

	int main(){
	Lista<int> lista_enteros;
	iniciar_lista(lista_enteros);

	int cantidad, numero;
	cout<<"Ingrese cantidad de n�meros: ";
	cin>>cantidad;

	for(int i = 0; i < cantidad; i++){
		cout<<"Ingrese n�mero: ";
		cin>>numero;
		agregar_final(lista_enteros, numero);
	}

	cout<<"\nLista de enteros:\n";
	mostrar_lista(lista_enteros);

	int primos = contar_primos(lista_enteros);
	cout<<"Cantidad de n�meros primos: "<<primos<<endl;

	Lista<char> lista_caracteres;
	iniciar_lista(lista_caracteres);

	char letra;
	cout<<"\nIngrese cantidad de caracteres: ";
	cin>>cantidad;

	for(int i = 0; i < cantidad; i++){
		cout<<"Ingrese caracter: ";
		cin>>letra;
		agregar_final(lista_caracteres, letra);
	}

	cout<<"\nLista de caracteres:\n";
	mostrar_lista(lista_caracteres);

	int mayus, minus;
	contar_mayus_minus(lista_caracteres, mayus, minus);
	cout<<"May�sculas: "<<mayus<<", Min�sculas: "<<minus<<endl;
	}
