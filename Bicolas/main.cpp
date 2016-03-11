#include <iostream>
#include "Bicolas.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Bicolas<int> cola;
	int sal;
	cola.Insertar(10,1);
	cola.Insertar(20,2);
	cola.Insertar(30,1);
	cola.Insertar(40,2);
	cola.Insertar(50,1);
	cola.Imprimir(2);
	cola.Eliminar(sal,1);
	std::cout<<"\n";
	cola.Imprimir(2);
	return 0;
}
