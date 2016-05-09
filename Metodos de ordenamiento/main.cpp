#include <cstdlib>
#include <iostream>
#include "Metodos_Ordenacion_Interna.h"
#include <sys/time.h>
#include <windows.h>
#include "Ordenacion_Externa.h"
#include <stdlib.h>
#define MAX 10
using namespace std;
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{//Macro para determinar el tiempo en milisegundos
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
int main(int argc, char *argv[]){ 
    int E[MAX],nu=MAX;
    /*Declarar antes de empezar el proceso*/
    LARGE_INTEGER t_ini, t_fin;
    double secs;
    QueryPerformanceCounter(&t_ini);
    Ordenacion_Externa MOE;
    char cont[]="ejemplo.dat";
    //MOE.fusion("ClientA.DAT","ClientB.DAT");
    MOE.inicializar(cont);
    MOE.MDirecta(cont);
    FILE *fp;
    fp=fopen(cont,"rb");
    MOE.imprimir(fp);
    fclose(fp);
    //Metodos_Ordenacion_Interna MOI;
    /*despues de esto va el proceso al que queremos medir
    for(int i=0;i<nu;i++)
        E[i]=nu-i;          */
    //MOI.Insercion_Directa(E,nu);
    //MOI.Insercion_Binaria(E,nu);
    //MOI.Burbuja(E,nu);
    //MOI.Metodo_Quick_Sort(E,0,nu-1);
    //MOI.Shaker_Sort(E,nu);
    //MOI.Metodo_Shell(E,nu);
    //MOI.Seleccion_Directa(E,nu); 
    //MOI.imprimir_Matriz(E,nu);    
    /*Terminado el proceso pegar esto para imprimir el tiempo en milisegundos*/
    QueryPerformanceCounter(&t_fin);
    secs = performancecounter_diff(&t_fin, &t_ini);
    cout<<secs * 1000.0<<" milisegundos\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}
