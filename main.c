
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ticket.h"
#include "list.h"
#include "extra.h"

// Función para mostrar el menú principal de opciones al usuario
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

// Función para registrar un nuevo ticket (con prioridad baja por defecto)
void registrar_ticket(List* lista, int* idCounter, int* ordenLlegada) {
    char descripcion[100];

    puts("Registro de nuevo ticket");
    printf("Ingrese descripción breve del problema: ");
    fgets(descripcion, sizeof(descripcion), stdin);
    descripcion[strcspn(descripcion, "\n")] = 0; // Eliminar salto de línea final

    // Crear nuevo ticket
    Ticket* nuevo = malloc(sizeof(Ticket));
    *nuevo = crearTicket(*idCounter, 1, *ordenLlegada); // Prioridad 1 = Baja
    strcpy(nuevo->descripcion, descripcion);

    // Insertar ordenadamente por prioridad y hora
    insertarOrdenadoPorPrioridad(lista, nuevo);

    printf("Ticket ID %d registrado con prioridad Baja\n", *idCounter);
    (*idCounter)++;
    (*ordenLlegada)++;
}

// Función para cambiar la prioridad de un ticket ya existente
void cambiar_prioridad(List* lista) {
    int id, nueva;
    printf("Ingrese ID del ticket a modificar: ");
    scanf("%d", &id);
    printf("Ingrese nueva prioridad (1 = Baja, 2 = Media, 3 = Alta): ");
    scanf("%d", &nueva);
    getchar(); // Consumir salto de línea
    cambiarPrioridad(lista, id, nueva);
}

// Función para mostrar todos los tickets ordenados por prioridad
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

// Función para atender (eliminar) el ticket con mayor prioridad y más antiguo
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

// Función para buscar un ticket por su ID
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

// Función principal que maneja el flujo del programa
int main() {
    List* lista = createList();  // Crear lista vacía
    int opcion;
    int idCounter = 1;           // Contador para IDs únicos
    int ordenLlegada = 1;        // Contador incremental para desempates

    do {
        limpiarPantalla();       // Limpia pantalla según SO
        mostrar_menu();          // Muestra el menú principal
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);
        getchar();               // Consumir salto de línea

        // Lógica del menú
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

        presioneTeclaParaContinuar(); // Esperar antes de limpiar y volver a mostrar

    } while (opcion != 6);

    return 0;
}