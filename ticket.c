#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ticket.h"

Ticket crearTicket(int id, int prioridad) {
    Ticket t;
    t.id = id;
    t.prioridad = prioridad;

    // Obtener hora actual
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(t.hora, sizeof(t.hora), "%H:%M", tm_info);

    return t;
}

void mostrarTicket(Ticket* t) {
    const char* prioridades[] = {"", "Baja", "Media", "Alta"};
    printf("====== Ticket ======\n");
    printf("ID: %d\n", t->id);
    printf("Prioridad: %s (%d)\n", prioridades[t->prioridad], t->prioridad);
    printf("Hora de ingreso: %s\n", t->hora);
    printf("====================\n");
}
