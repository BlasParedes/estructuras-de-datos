#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "ArbolBB.h"
#include "ArbolAVL.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <fstream>
using std::cout;
using std::ifstream;
int main(int argc, char** argv) {
	ifstream fp1("arbolesAVL.txt");
	ArbolAVL<int> arbol,arbol2;
	char line[100],*p;

	fp1.getline(line,100,'\n');
	int i = atoi(strtok(line," "));
	arbol.Agre_Busc(i);
	arbol2.Agre_Busc(i);
	while( (p = strtok(NULL," ")) != NULL){
		int i = atoi(p);
		arbol.Agre_Busc(i);
		arbol2.Agre_Busc(i);
	}

//	cout<<arbol.is_completo();
//	arbol.ImpPro_Orden(arbol.get_raiz());
//	cout<<arbol.is_equilibrado(arbol.get_raiz());
//	cout<<arbol.nodo_op_sim(54);
//	arbol.Eliminar(17);
//	cout<<"\n\n";
//	arbol.ImpPro_Orden(arbol.get_raiz());
//  arbol.ImpPro_PreOrd(arbol.get_raiz());
//  arbol.ImpPro_Orden(arbol.get_raiz());
//  arbol.ImpExten();
//  cout<<"\n"<<arbol.comparar_simetria(arbol2);
//  cout<<"\n"<<arbol.is_simetrico();
	fp1.close();
	system("PAUSE");
	return 0;
}
