#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ticket.h"  
#include "list.h"    

void cambiarPrioridad(List* lista, int id, int nueva_prioridad) {
    Ticket* t = firstList(lista);

    // Buscar el ticket con el ID correspondiente
    while (t != NULL) {
        if (t->id == id) break;
        t = nextList(lista);
    }

    if (t == NULL) {
        printf("Ticket con ID %d no encontrado.\n", id);
        return;
    }

    // Guardar puntero al ticket actual (que será eliminado)
    Ticket* ticketMovido = t;

    // Actualizar prioridad
    ticketMovido->prioridad = nueva_prioridad;

    // Sacar el ticket de la lista actual
    popCurrent(lista);

    // Recorrer lista para encontrar su nueva posición
    Ticket* aux = firstList(lista);
    while (aux != NULL && aux->prioridad >= ticketMovido->prioridad) {
        aux = nextList(lista);
    }

    // Insertar en la posición correcta
    if (aux == NULL) {
        pushBack(lista, ticketMovido);  
    } else {
        pushCurrent(lista, ticketMovido);  
    }

    printf("Prioridad del ticket ID %d actualizada a %d y reordenada.\n", id, nueva_prioridad);
}

int main() {
    // Crear lista para guardar tickets
    List* listaTickets = createList();

    // Contador de IDs automáticos
    int contadorId = 1;

    // Crear ticket de ejemplo 
    Ticket* nuevo = (Ticket*) malloc(sizeof(Ticket));
    *nuevo = crearTicket(contadorId++, 2); // prioridad media 2

    // Mostrar ticket
    mostrarTicket(nuevo);

    // Agregarlo a la lista
    pushBack(listaTickets, nuevo);

    return 0;
}
