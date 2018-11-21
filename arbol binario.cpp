#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

//Estructura tipo nodo 
struct Nodo{
	Nodo *derecho;
	int dato;
	Nodo *izquierdo;
};

//Prototipos de funciones 
void menu();
Nodo *nDinamico(int dato);
void inNodo(Nodo *&,int);
void imprimirDatos(Nodo *,int);

//Funcion principal
int main(){
	char opcion;//Variable para movernos dentro del switch
	Nodo *arbol=NULL;//Creando nodo arbol tipo puntero apuntando a NULL
	int numero;//Variable para guardar datos ingresados por el usuario
	int numDatos;//Vriable que almacenara el numero de datos que el usuario desea ingresar
	
	do{
		int contador=0;//Contador para imprimir espacios al imprimir el arbol dentro de do while para volver a inicializarce en 0
		menu();//Llamando a funcion menu
		cin>>opcion;
		fflush(stdin);//vaciando buffer
		switch(opcion){
			case '1':
				cout<<"\n\t1.Ingresar datos."<<endl;
				cout<<"Cuantos numeros desea agregar? "; cin>>numDatos;
				for(int i=0; i<numDatos; i++){
					cout<<"Ingresar numero "<<i+1<<" :"; cin>>numero;
					nDinamico(numero);
					inNodo(arbol,numero);
				}
				break;
			case '2':
				cout<<"\n\t2.Mostrar datos.\n\n\n";
				imprimirDatos(arbol,contador);
				cout<<endl;
				break;
			case '3':
				cout<<"\nSalio del programa."<<endl;
				break;
			default:
				cout<<"\nError: Opcion invalida."<<endl;
				break;
		}
		cout<<"\nPresione una tecla para continuar.."<<endl;
		getch();//pausa en el programa
		system("cls");//limpiar pantalla
	}while(opcion !='3');//si opcion diferente de 3 repetir
	
	return 0;
}

//Funcion para mostrar menu al usuario
void menu(){
	cout<<"\tMENU"<<endl
	    <<"1.Ingresar datos."<<endl
	    <<"2.Mostrar datos."<<endl
	    <<"3.Salir."<<endl
	    <<"Ingresar el numero de opcion que desea ejecutar: ";
	    
}
//Funcion tipo nodo para crear nuevo nodo usando memoria dinamica
Nodo *nDinamico(int dato){
    Nodo *nNodo = new Nodo();//creando nuevo nodo
	nNodo->dato = dato;//introduciendo dato en el nodo 
	nNodo->derecho = NULL;//nodo derecho apuntando hacia NULL
	nNodo->izquierdo = NULL;//nodo izquierdo apuntando hacia NULL
	
	return nNodo;//Retornando el nuevo nodo con su nuevo valor
}

//Funcion para insertar el nodo 
void inNodo(Nodo *&arbol,int dato){
	
	if(arbol==NULL){//si el arbol esta vacio
		Nodo *nNodo = nDinamico(dato);//nNodo toma el valor de el nodo retornado 
		arbol = nNodo;//se introduce el nodo al arbol
	}else{//si el arbol contiene dato
		if(dato < arbol->dato){//si el que se va a ingresar es menor al padre
			inNodo(arbol->izquierdo,dato);//pasar puntero izquierdo y el dato
		}else{//si el dato es mayor al padre 
			inNodo(arbol->derecho,dato);//pasando puntero derecho y el dato
		}
	}
}
//Funcion para imprimir datos del arbol
void imprimirDatos(Nodo *arbol,int contador){
	
	if(arbol == NULL){//si el arbol esta vacio
		return;
	}else{//si el arbol no esta vacio
		imprimirDatos(arbol->derecho,contador+1);
		for(int i=0; i<contador; i++){
			cout<<"   ";//espacios para imprimir el arbol binario
		}
		cout<<arbol->dato<<endl;
		imprimirDatos(arbol->izquierdo,contador+1);
	}
}
