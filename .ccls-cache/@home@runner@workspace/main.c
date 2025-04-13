#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ticket.h"
#include "list.h"
#include "extra.h"

void mostrar_menu() {
    printf("========================================\n");
    printf("     Sistema de Tickets de Soporte\n");
    printf("========================================\n");
    printf("1) Registrar ticket\n");
    printf("2) Cambiar prioridad de ticket\n");
    printf("3) Mostrar lista de tickets\n");
    printf("4) Atender siguiente ticket\n");
    printf("5) Buscar ticket por ID\n");
    printf("6) Salir\n");
    printf("========================================\n");
}

void registrar_ticket(List* lista, int* idCounter, int* ordenLlegada) {
    char descripcion[100];

    puts("Registro de nuevo ticket");
    printf("Ingrese descripción breve del problema: ");
    fgets(descripcion, sizeof(descripcion), stdin);
    descripcion[strcspn(descripcion, "\n")] = 0;

    Ticket* nuevo = malloc(sizeof(Ticket));
    *nuevo = crearTicket(*idCounter, 1, *ordenLlegada); // Prioridad baja por defecto
    strcpy(nuevo->descripcion, descripcion);

    insertarOrdenadoPorPrioridad(lista, nuevo);

    printf("Ticket ID %d registrado con prioridad Baja\n", *idCounter);
    (*idCounter)++;
    (*ordenLlegada)++;
}

void cambiar_prioridad(List* lista) {
    int id, nueva;
    printf("Ingrese ID del ticket a modificar: ");
    scanf("%d", &id);
    printf("Ingrese nueva prioridad (1 = Baja, 2 = Media, 3 = Alta): ");
    scanf("%d", &nueva);
    getchar(); // consumir newline
    cambiarPrioridad(lista, id, nueva);
}

void mostrar_tickets(List* lista) {
    Ticket* t = firstList(lista);
    if (!t) {
        printf("No hay tickets registrados.\n");
        return;
    }

    printf("\nLista de Tickets Pendientes:\n");
    while (t != NULL) {
        mostrarTicket(t);
        t = nextList(lista);
    }
}

void atender_ticket(List* lista) {
    Ticket* t = firstList(lista);
    if (!t) {
        printf("No hay tickets pendientes.\n");
        return;
    }

    printf("\nProcesando siguiente ticket:\n");
    mostrarTicket(t);
    popFront(lista);
}

void buscar_ticket(List* lista) {
    int id;
    printf("Ingrese ID a buscar: ");
    scanf("%d", &id);
    getchar();

    Ticket* t = firstList(lista);
    while (t != NULL) {
        if (t->id == id) {
            mostrarTicket(t);
            return;
        }
        t = nextList(lista);
    }

    printf("Ticket no encontrado.\n");
}

int main() {
    List* lista = createList();
    int opcion;
    int idCounter = 1;
    int ordenLlegada = 1;

    do {
        limpiarPantalla();
        mostrar_menu();
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                registrar_ticket(lista, &idCounter, &ordenLlegada);
                break;
            case 2:
                cambiar_prioridad(lista);
                break;
            case 3:
                mostrar_tickets(lista);
                break;
            case 4:
                atender_ticket(lista);
                break;
            case 5:
                buscar_ticket(lista);
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }

        presioneTeclaParaContinuar();

    } while (opcion != 6);

    return 0;
}
