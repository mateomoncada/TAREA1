
#  Sistema de Tickets de Soporte

Este proyecto implementa un sistema de tickets de soporte técnico en lenguaje C, utilizando listas doblemente enlazadas (TDA List) para organizar y priorizar solicitudes.

##  Objetivo

Permitir el ingreso, visualización y gestión de tickets de atención, priorizando los más urgentes y antiguos según su hora de ingreso.

---

##  Funcionalidades

### 1. Registrar ticket
- El usuario ingresa la descripción del problema.
- Se asigna automáticamente una prioridad **baja (1)**.
- Se registra la hora del sistema.
- El ticket se inserta automáticamente en la posición correcta según su prioridad y hora.

### 2. Cambiar prioridad del ticket
- El usuario indica el **ID** del ticket y la nueva prioridad (`1`, `2` o `3`).
- El ticket se elimina de su posición y se vuelve a insertar de forma ordenada.
- Si no se encuentra el ID, se muestra un mensaje de error.

### 3. Mostrar lista de tickets pendientes
- Muestra todos los tickets ordenados por prioridad:
  - **Alta (3)** → **Media (2)** → **Baja (1)**
- Dentro de una misma prioridad, los tickets se ordenan por **hora de ingreso** (más antiguos primero).

### 4. Atender siguiente ticket
- Atiende el ticket con mayor prioridad.
- Si hay varios con la misma prioridad, se elige el más antiguo.
- Se elimina de la lista y se muestra su información.

### 5. Buscar ticket por ID
- Muestra los datos completos del ticket si existe.
- Si no se encuentra, se notifica al usuario.

---

##  Estructura de datos utilizada

- **TDA List**: Lista doblemente enlazada implementada de forma modular.
- Cada nodo almacena un **puntero a struct Ticket**.

---

##  Archivos importantes

- `main.c`: Menú y control de flujo del programa.
- `ticket.c / ticket.h`: Lógica del ticket, impresión, ordenamiento e inserción.
- `list.c / list.h`: Implementación del TDA List (entregado previamente).
- `extra.c / extra.h`: Funciones utilitarias como `limpiarPantalla()` y `presioneTeclaParaContinuar()`.

---

##  Compilación

Puedes compilar usando `Makefile` o directamente:

```bash
gcc main.c ticket.c list.c extra.c -o main
./main
```

> Si estás usando Replit, simplemente haz clic en el botón **"Run"**.

---

##  Notas importantes

- Solo se utilizaron **librerías estándar de C**, cumpliendo con los requisitos de la tarea.
- El sistema está modularizado y permite mantener el código limpio y mantenible.

---

##  Autor

Mateo Moncada  
Pontificia Universidad Católica de Valparaíso – Escuela de Ingeniería Informática  
Curso: Estructura de Datos  
