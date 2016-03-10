#include <iostream>
#include "ListaD.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using std::cout;
using std::cin;
int main(int argc, char** argv) {
	ListaD<NodoE> list;
	for(int i = 0;i<=3; i++){
		NodoE nodo;
		char control[60];
		cout<<"Escriba su cadena\n";
		cin.getline(control,60);
		cout<<"\n";
		nodo.set_cadena(control);
		list.Agregar(nodo);
	}
		
	list.Imprimir();
	NodoE eli;
	eli.set_cadena(list.get_cabezera().get_cadena());
		list.Eliminar(eli);
	return 0;
}
