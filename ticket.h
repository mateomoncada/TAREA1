#ifndef TICKET_H
#define TICKET_H

typedef struct {
    int id;
    int prioridad; // 1: Baja, 2: Media, 3: Alta
    char hora[6];  // HH:MM
} Ticket;

Ticket crearTicket(int id, int prioridad);
void mostrarTicket(Ticket* t);

#endif
