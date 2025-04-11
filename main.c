#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"
#include "ticket.h"
#include "extra.h"

void mostrarMenu() {
    limpiarPantalla();
    puts("======================================");
    puts("     Sistema de Tickets de Soporte");
    puts("======================================");
    puts("1) Registrar ticket");
    puts("2) Cambiar prioridad de ticket");
    puts("3) Mostrar lista de tickets");
    puts("4) Atender siguiente ticket");
    puts("5) Buscar ticket por ID");
    puts("6) Salir");
}

void registrar_ticket(List* lista, int* idCounter) {
    char descripcion[100];
    puts("Registro de nuevo ticket");
    printf("Ingrese descripción del problema: ");
    fgets(descripcion, sizeof(descripcion), stdin);
    descripcion[strcspn(descripcion, "\n")] = 0;

    Ticket* nuevo = malloc(sizeof(Ticket));
    *nuevo = crearTicket(*idCounter, 1); // prioridad baja por defecto
    strcpy(nuevo->descripcion, descripcion);

    insertarOrdenadoPorPrioridad(lista, nuevo);

    printf("Ticket ID %d registrado con prioridad Baja\n", *idCounter);
    (*idCounter)++;
}



void cambiar_prioridad(List* lista) {
    int id, prioridad;
    printf("Ingrese ID del ticket: ");
    scanf("%d", &id);
    printf("Ingrese nueva prioridad (1 = Baja, 2 = Media, 3 = Alta): ");
    scanf("%d", &prioridad);
    getchar();
    cambiarPrioridad(lista, id, prioridad);
}

void mostrar_lista(List* lista) {
    Ticket* t = firstList(lista);
    if (!t) {
        puts("No hay tickets registrados.");
        return;
    }

    puts("Lista de Tickets Pendientes:");
    while (t) {
        mostrarTicket(t);
        t = nextList(lista);
    }
}

void atender_ticket(List* lista) {
    Ticket* t = firstList(lista);
    if (!t) {
        puts("No hay tickets pendientes.");
        return;
    }

    puts("Ticket en atención:");
    mostrarTicket(t);
    popFront(lista);
    puts("Ticket eliminado de la lista.");
}

void buscar_ticket(List* lista) {
    int id;
    printf("Ingrese ID a buscar: ");
    scanf("%d", &id);
    getchar();

    Ticket* t = firstList(lista);
    while (t) {
        if (t->id == id) break;
        t = nextList(lista);
    }

    if (t) mostrarTicket(t);
    else printf("Ticket con ID %d no encontrado.\n", id);
}

int main() {
    List* tickets = createList();
    int idCounter = 1;
    char opcion;

    do {
        mostrarMenu();
        printf("Ingrese su opción: ");
        scanf(" %c", &opcion);
        getchar();

        switch (opcion) {
            case '1': registrar_ticket(tickets, &idCounter); break;
            case '2': cambiar_prioridad(tickets); break;
            case '3': mostrar_lista(tickets); break;
            case '4': atender_ticket(tickets); break;
            case '5': buscar_ticket(tickets); break;
            case '6': puts("Saliendo del sistema..."); break;
            default:  puts("Opción no válida.");
        }

        if (opcion != '6') presioneTeclaParaContinuar();

    } while (opcion != '6');

    cleanList(tickets); // liberar memoria
    return 0;
}
