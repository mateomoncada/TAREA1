#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ticket.h"
#include "list.h"

Ticket crearTicket(int id, int prioridad) {
    Ticket t;
    t.id = id;
    t.prioridad = prioridad;

    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    strftime(t.hora, sizeof(t.hora), "%H:%M", tm_info);

    t.descripcion[0] = '\0'; // Inicializa la descripción como vacía
    return t;
}

void mostrarTicket(Ticket* t) {
    const char* prioridades[] = {"", "Baja", "Media", "Alta"};
    printf("ID: %d\n", t->id);
    printf("Prioridad: %s (%d)\n", prioridades[t->prioridad], t->prioridad);
    printf("Hora: %s\n", t->hora);
    printf("Descripción: %s\n", t->descripcion);
    printf("-----------------------------\n");
}

void cambiarPrioridad(List* lista, int id, int nueva_prioridad) {
    Ticket* t = firstList(lista);

    while (t != NULL) {
        if (t->id == id) break;
        t = nextList(lista);
    }

    if (t == NULL) {
        printf("Ticket con ID %d no encontrado.\n", id);
        return;
    }

    Ticket* ticketMovido = t;
    ticketMovido->prioridad = nueva_prioridad;
    popCurrent(lista);

    Ticket* aux = firstList(lista);
    while (aux != NULL) {
        if (aux->prioridad < ticketMovido->prioridad) break;
        if (aux->prioridad == ticketMovido->prioridad) {
            if (strcmp(ticketMovido->hora, aux->hora) < 0) break;
        }
        aux = nextList(lista);
    }

    if (aux == NULL)
        pushBack(lista, ticketMovido);
    else
        pushCurrent(lista, ticketMovido);

    printf("Prioridad actualizada.\n");
}

void insertarOrdenadoPorPrioridad(List* lista, Ticket* nuevo) {
    Ticket* aux = firstList(lista);

    while (aux != NULL) {
        if (aux->prioridad < nuevo->prioridad) break;
        if (aux->prioridad == nuevo->prioridad) {
            if (strcmp(nuevo->hora, aux->hora) < 0) break;
        }
        aux = nextList(lista);
    }

    if (aux == NULL)
        pushBack(lista, nuevo);
    else
        pushCurrent(lista, nuevo);
}
