#include <iostream>
#include "ListaCDE.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ListaCDE<int> lista;
	int eli = 134;
	lista.Insertar(14);
	lista.Insertar(134);
	lista.Insertar(4);
	lista.Insertar(300);
	lista.imprimir();
	lista.Eliminar(eli);
	lista.imprimir();
	return 0;
}
