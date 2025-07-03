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
	
void AgregarOrden(pnodo &inicio, pnodo nuevo){
	pnodo i;
	if(inicio == NULL){
		inicio = nuevo;
	}
	else{
		if(nuevo -> dato < inicio -> dato){
			nuevo -> sig = inicio;
			inicio -> ant = nuevo;
			inicio = nuevo;
		}
		else{
			for(i = inicio; i -> sig != NULL && (i -> sig) -> dato < nuevo -> dato; i = i -> sig);
				if(i -> sig != NULL){
					nuevo -> sig = i -> sig;
					nuevo -> ant = i;
					(i -> sig) -> ant = nuevo;
					i -> sig = nuevo;
				}
				else{
					i -> sig = nuevo;
					nuevo -> ant = i;
				}
		}
	}
}
	
pnodo QuitarInicio(pnodo &inicio){
	pnodo extraido;
	if(inicio == NULL){
		extraido = NULL;
	}
	else{
		if(inicio -> sig == NULL){
			extraido = inicio;
			inicio = NULL;
		}
		else{
			extraido = inicio;
			inicio = inicio -> sig;
			inicio -> ant = NULL;
			extraido -> sig = NULL;
		}
	}
	return extraido;
}
	
pnodo QuitarFinal(pnodo &inicio){
	pnodo extraido, i;
	if(inicio == NULL){
		extraido = NULL;
	}
	else{
		for(i = inicio; i -> sig != NULL; i = i -> sig);
		extraido = i;
		(i -> ant) -> sig = NULL;
		i -> ant = NULL;
	}
	return extraido;
}
	
pnodo QuitarNodo(pnodo &inicio, int valor){
	pnodo extraido, i;
	if(inicio == NULL){
		extraido = NULL;
	}
	else{
		if(inicio -> dato == valor){
			extraido = inicio;
			inicio = inicio->sig;
			inicio->ant = NULL;
			extraido->sig = NULL;
		}
		else{
			for(i = inicio; i != NULL && i -> dato != valor; i = i -> sig);
				if(i != NULL){
					extraido = i;
					(i -> ant) -> sig = i -> sig;
					i -> sig = i -> ant;
					extraido -> sig = NULL;
					extraido -> ant = NULL;
				}
			}
		}
	return extraido;
}
	
bool BuscarNodo(pnodo inicio, int valor){
	pnodo i = inicio;
	while(i != NULL){
		if(i->dato == valor){
			return true;
		}
		i = i->sig;
	}
	return false;
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
	
	cout<<"\nlista: "<<endl;
	MostrarLista(lista);
	
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
	
	cout<<"\ncuántos valores desea insertar ordenadadamente en la lista?: ";
	cin>>cantidad;
	for(int i = 0; i <cantidad; i++){
		cout<<"valor: ";
		cin>>valor;
		CrearNodo(nuevo, valor);
		AgregarOrden(lista, nuevo);
	}
	
	cout<<"\nlista actual: "<<endl;
	MostrarLista(lista);
	
	cout<<"\nquitando el primer nodo.."<<endl;
	nuevo = QuitarInicio(lista);
	if(nuevo != NULL){
		cout<<"listo"<<endl;
		delete nuevo;
	}
	
	cout<<"\nquitando el último nodo.."<<endl;
	nuevo = QuitarFinal(lista);
	if(nuevo != NULL){
		cout<<"listo"<<endl;
		delete nuevo;
	}
	
	cout<<"\nlista actualizada: "<<endl;
	MostrarLista(lista);
	
	cout<<"\ningrese un valor a quitar de la lista: ";
	cin>>valor;
	nuevo = QuitarNodo(lista, valor);
	if(nuevo != NULL){
		cout<<"valor quitado"<<endl;
		delete nuevo;
	}
	else{
		cout<<"el valor no estaba en la lista"<<endl;
	}
	
	cout<<"\nlista actualizada: "<<endl;
	MostrarLista(lista);
	
	cout<<"\ningrese un valor a buscar en la lista: ";
	cin>>valor;
	if(BuscarNodo(lista, valor)){
		cout<<"el valor "<<valor<<" se encuentra en la lista"<<endl;
	}
	else{
		cout<<"el valor "<<valor<<" no está en la lista"<<endl;
	}

}
