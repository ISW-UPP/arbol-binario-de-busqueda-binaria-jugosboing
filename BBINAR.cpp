
#include <iostream>

using namespace std;

struct Nodo{
	int dato;
	Nodo* derecha;
	Nodo* izquierda;
	Nodo* padre;
};

void menu();

Nodo* CrearnuevoNodo(int, Nodo *);
void insertarNodo(Nodo *&, int, Nodo *);
void visualizarArbol(Nodo *, int);
bool busqueda(Nodo *, int);


void eliminar(Nodo*, int);
Nodo* minimo(Nodo*);
void eliminarNodo(Nodo *);

void reemplazar(Nodo*, Nodo*);
void destruirNodo(Nodo*);

Nodo* arbol = NULL;


int main(){

	menu();
	return 0;
}

void menu(){

	int dato, opcion, contador = 0, cantidad;

	do{

		 
		cout << "              Arbol Binario         " << endl; 
		cout << "---------------------------------------" << endl;
		cout << "1. Ingresar un nuevo nodo" << endl;
		cout << "2. Mostrar Arbol" << endl;
		cout << "3. Eliminar" << endl;
		cout << "4. Buscar elemento" << endl;
		cout << "5. Salir" << endl;
		cout << "---------------------------------------" << endl;

		cout << "Elige una opcion: ";
		cin >> opcion;
		
		
		int a[100];
		switch (opcion){
			case 1:
				
				cout << "Cuantos nodos desea ingresar? ";
				cin >> cantidad;
				for(int i = 0; i < cantidad; i++){
					cout << "Ingresa el nodo " << i + 1 << ": ";
					cin >> dato;
					a[i]=dato;
					insertarNodo(arbol,dato, NULL);
				}
				system("cls");
				cout << "se agrego el nodo" << endl;
				system("pause");
				break;
	
			case 2:
				cout << "\n Mostrar arbol: \n\n";
				contador = 0;
				visualizarArbol(arbol, contador);
				system("pause");
				break;

			case 3:
				cout << "Que elemento deseas eliminar?: ";
				cin >> dato;
				eliminar(arbol, dato);
				break;

			case 4:
				
				a[cantidad];
				
				int inf, sup, mitad, dato, i;

			char band = 'F';
			cout << "Que elemento deseas buscar?: ";
			cin >> dato;
		
			inf = 0;
			sup = 0+cantidad;
			i = 0;
			
			while ((inf <= sup) && (i< cantidad))
			{
				mitad = (inf + sup) / 2;// mitad
		
				if (a[mitad] == dato)
				{
					band = 'V';
					
					break; //Se encontro el elemento buscado, para no perder tiempo
				}
				if (a[mitad] > dato)
				{
					sup = mitad;
					mitad = (inf + sup) / 2; //Refrescar la mitad con un nuevo valor del lado superior
				}
				if (a[mitad] < dato)
				{
					inf = mitad;
					mitad = (inf + sup) / 2; //Refrescar la mitad con un nuevo valor del lado inferior
				}
				i++;
			}
		
			if (band == 'V')
			{
				cout << "El numero se encontro en la posicion: " << mitad+1 << endl; // mitad guarda las posiciones
			}
			else
			{
				cout << "El numero no se encontro";
			}

						cout << "\n";
						system("pause");
						break;
				} 
			system("cls");
			} while (opcion != cantidad);
		}

Nodo* CrearnuevoNodo(int n, Nodo *padre){

	Nodo* nuevo_nodo = new Nodo();

	nuevo_nodo->dato = n;
	nuevo_nodo->derecha = NULL;
	nuevo_nodo->izquierda = NULL;

	return nuevo_nodo;
}

void insertarNodo(Nodo*& arbol, int n, Nodo *padre){

	if (arbol == NULL){	

		Nodo* nuevo_nodo = CrearnuevoNodo(n, padre);
		arbol = nuevo_nodo;
	}
	else{	

		int valorRaiz = arbol->dato;
		if (n < valorRaiz){ 
			insertarNodo(arbol->izquierda, n, arbol);
		} else{ 
			insertarNodo(arbol->derecha, n, arbol);
		}
	}
}

void visualizarArbol(Nodo *arbol, int cont){

	if (arbol == NULL){
		return;
	} 
	else{

		visualizarArbol(arbol->derecha, cont + 1);
		for (int i = 0; i < cont; i++){ 
			cout << "  ";
		}
		cout << arbol->dato << endl;
		visualizarArbol(arbol->izquierda, cont + 1);
	}
}


void eliminar(Nodo* arbol, int n){

	if(arbol == NULL){
		cout << "El arbol esta vacio UnU" << endl;
		return;
	} 
	else if(n < arbol->dato){		
		eliminar(arbol->izquierda, n);
	} 
	else if(n > arbol->dato){		
		eliminar(arbol->derecha, n);
	} 
	else{		
		eliminarNodo(arbol);
		cout << "Se elimino el nodo correctamente :D" << endl;
	}
}

Nodo* minimo(Nodo* arbol){

	if(arbol == NULL){
		return NULL;
	}
	if(arbol->izquierda){
		return minimo(arbol->izquierda);	
	} else{		
		return arbol;	
	}
}

void eliminarNodo(Nodo* nodoEliminar){

	if(nodoEliminar->izquierda && nodoEliminar->derecha){	
		
		Nodo * menor = minimo(nodoEliminar->derecha);	
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);	
	} 
	else if(nodoEliminar->izquierda){	

		reemplazar(nodoEliminar, nodoEliminar->izquierda);
		destruirNodo(nodoEliminar);
	} 
	else if(nodoEliminar->derecha){

		reemplazar(nodoEliminar, nodoEliminar->derecha);
		destruirNodo(nodoEliminar);	
	} else{

		reemplazar(nodoEliminar, nodoEliminar->derecha);
		destruirNodo(nodoEliminar);
	}
}

   void reemplazar(Nodo* arbol, Nodo* nuevoNodo){

	if(arbol->padre){	
	
		if(arbol->dato == arbol->padre->izquierda->dato){
			arbol->padre->izquierda = nuevoNodo;
		} 
		else if(arbol->dato == arbol->padre->derecha->dato){
			arbol->padre->derecha = nuevoNodo;
		}
	
		if(nuevoNodo){
			nuevoNodo->padre = arbol->padre;
		}
	}
}



void destruirNodo(Nodo* nodo){

	nodo->izquierda = NULL;
	nodo->derecha = NULL;
	delete nodo;
}

