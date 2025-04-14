
# Sistema de Tickets de Soporte

Este programa es una aplicación en C que permite gestionar tickets de soporte utilizando una lista ordenada por prioridad y hora de llegada.

---

## a) ¿Cómo compilar y ejecutar la tarea?

1. Asegúrate de tener todos los archivos en el mismo directorio:
   - `main.c`
   - `ticket.c`
   - `ticket.h`
   - `list.c`, `list.h` (TDA lista)
   - `extra.c`, `extra.h` (para limpiar pantalla y pausar)

2. Compilar con:

```bash
gcc main.c ticket.c list.c extra.c -o soporte
```

3. Ejecutar el programa:

```bash
./soporte
```

---

## b) Opciones que funcionan correctamente

- `1) Registrar ticket`:  Registra correctamente y ordena por prioridad y hora.
- `2) Cambiar prioridad`:  Modifica la prioridad y reordena el ticket.
- `3) Mostrar lista de tickets`:  Muestra los tickets ordenados por prioridad y llegada.
- `4) Atender siguiente ticket`:  Atiende y elimina el ticket con mayor prioridad.
- `5) Buscar ticket por ID`:  Busca y muestra la información de un ticket.
- `6) Salir`:  Cierra el programa.

**Posibles problemas:**

- Si olvidas compilar todos los archivos (`list.c`, `extra.c`, etc.), el programa dará errores de linker.
- Si no declaras correctamente el campo `ordenLlegada` o usas mal la función `crearTicket`, pueden surgir errores de tipo o de compilación.

---

## c) Ejemplo de interacción

```plaintext
========================================
     Sistema de Tickets de Soporte
========================================
1) Registrar ticket
2) Cambiar prioridad de ticket
3) Mostrar lista de tickets
4) Atender siguiente ticket
5) Buscar ticket por ID
6) Salir
========================================
Ingrese su opción: 1
Registro de nuevo ticket
Ingrese descripción breve del problema: Error en el login
Ticket ID 1 registrado con prioridad Baja

Presione ENTER para continuar...

Ingrese su opción: 3
Lista de Tickets Pendientes:
ID: 1
Prioridad: Baja (1)
Hora: 17:45
Descripción: Error en el login
-----------------------------
```
