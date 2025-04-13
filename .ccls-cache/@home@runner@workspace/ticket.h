#ifndef TICKET_H
#define TICKET_H

#include "list.h"

typedef struct {
    int id;
    int prioridad;         // 1 = Baja, 2 = Media, 3 = Alta
    char hora[6];          // Hora de ingreso (HH:MM)
    char descripcion[100]; // Descripción del problema
    int ordenLlegada;      // Número incremental para desempatar
} Ticket;

Ticket crearTicket(int id, int prioridad, int ordenLlegada);
void mostrarTicket(Ticket* t);
void cambiarPrioridad(List* lista, int id, int nueva_prioridad);
void insertarOrdenadoPorPrioridad(List* lista, Ticket* nuevo);

#endif


