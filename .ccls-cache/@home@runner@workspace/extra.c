#include <stdio.h>
#include <stdlib.h>
#include "extra.h"

void limpiarPantalla() {
#ifdef _WIN32
    system("cls"); // system("cls"); // Para Windows
#else
    system("clear"); // system("clear"); // Para Unix/Linux/MacOS
#endif    
    
}

void presioneTeclaParaContinuar() {
    printf("\nPresione ENTER para continuar...");
    getchar();
}
