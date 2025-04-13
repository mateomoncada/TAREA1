#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ticket.h"
#include "list.h"

Ticket crearTicket(int id, int prioridad, int ordenLlegada) {
    Ticket t;
    t.id = id;
    t.prioridad = prioridad;
    t.ordenLlegada = ordenLlegada;

    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    strftime(t.hora, sizeof(t.hora), "%H:%M", tm_info);

    t.descripcion[0] = '\0';
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
    insertarOrdenadoPorPrioridad(lista, ticketMovido);
}

void insertarOrdenadoPorPrioridad(List* lista, Ticket* nuevo) {
    Ticket* aux = firstList(lista);

    while (aux != NULL) {
        if (nuevo->prioridad > aux->prioridad) break;

        if (nuevo->prioridad == aux->prioridad) {
            if (strcmp(nuevo->hora, aux->hora) < 0) break;
            if (strcmp(nuevo->hora, aux->hora) == 0 &&
                nuevo->ordenLlegada < aux->ordenLlegada) break;
        }

        aux = nextList(lista);
    }

    if (aux == NULL)
        pushBack(lista, nuevo);
    else
        pushCurrent(lista, nuevo);
}
