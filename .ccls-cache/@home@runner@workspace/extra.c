#include <stdio.h>
#include <stdlib.h>
#include "extra.h"

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void presioneTeclaParaContinuar() {
    printf("\nPresione ENTER para continuar...");
    getchar();
}
