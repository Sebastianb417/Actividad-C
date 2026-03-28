#include <stdio.h>

#define MAX_PRODUCTOS 6
#define MAX_CARRITO 50

// Estructura producto
struct Producto {
    int id;
    char nombre[30];
    float precio;
};

// Estructura carrito
struct Carrito {
    int idProducto;
    int cantidad;
};

// Catálogo de productos
struct Producto productos[MAX_PRODUCTOS] = {
    {1, "Hamburguesa", 12000},
    {2, "Pizza", 18000},
    {3, "Perro caliente", 8000},
    {4, "Gaseosa", 4000},
    {5, "Papas fritas", 6000},
    {6, "Helado", 5000}
};

struct Carrito carrito[MAX_CARRITO];
int totalItems = 0;

// Función mostrar productos
void mostrarProductos() {
    printf("\n--- MENU DE PRODUCTOS ---\n");
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        printf("%d. %s - $%.2f\n", productos[i].id, productos[i].nombre, productos[i].precio);
    }
}

// Buscar producto
int buscarProducto(int id) {
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        if (productos[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Agregar al carrito
void agregarAlCarrito() {
    int id, cantidad;

    mostrarProductos();
    printf("\nIngrese ID del producto: ");
    scanf("%d", &id);

    int index = buscarProducto(id);

    if (index == -1) {
        printf("Producto no existe.\n");
        return;
    }

    printf("Ingrese cantidad: ");
    scanf("%d", &cantidad);

    if (cantidad <= 0) {
        printf("Cantidad inválida.\n");
        return;
    }

    carrito[totalItems].idProducto = id;
    carrito[totalItems].cantidad = cantidad;
    totalItems++;

    printf("Producto agregado al carrito.\n");
}

// Ver carrito
void verCarrito() {
    float total = 0;

    printf("\n--- CARRITO ---\n");

    if (totalItems == 0) {
        printf("Carrito vacío.\n");
        return;
    }

    for (int i = 0; i < totalItems; i++) {
        int index = buscarProducto(carrito[i].idProducto);
        float subtotal = productos[index].precio * carrito[i].cantidad;

        printf("%s x%d = $%.2f\n",
               productos[index].nombre,
               carrito[i].cantidad,
               subtotal);

        total += subtotal;
    }

    float domicilio = 3000;
    total += domicilio;

    printf("Domicilio: $%.2f\n", domicilio);
    printf("TOTAL: $%.2f\n", total);
}

// Confirmar pedido
void confirmarPedido() {
    if (totalItems == 0) {
        printf("No hay productos en el carrito.\n");
        return;
    }

    printf("\nPedido confirmado. ¡Gracias por su compra!\n");
    totalItems = 0; // Vaciar carrito
}

int main() {
    int opcion;

    do {
        printf("\n===== APP DOMICILIOS =====\n");
        printf("1. Ver productos\n");
        printf("2. Agregar al carrito\n");
        printf("3. Ver carrito\n");
        printf("4. Confirmar pedido\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarProductos();
                break;
            case 2:
                agregarAlCarrito();
                break;
            case 3:
                verCarrito();
                break;
            case 4:
                confirmarPedido();
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }

    } while (opcion != 5);

    return 0;
}