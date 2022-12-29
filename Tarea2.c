// Diego Vargas Gomez
// Bastian Arriagada Quero
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

typedef struct user
{
    int id;
    char nickname[50];
    char password[50];
    char nombres[50];
    char apellidoPaterno[30];
    char apellidoMaterno[30];
} USER;

typedef struct teclado
{
    int id;
    char marca[20];
    char modelo[20];
    char idioma[20];
} KEYBOARD;

typedef struct mouse
{
    int id;
    char marca[20];
    char modelo[20];
} MOUSE;

typedef struct monitor
{
    int id;
    char marca[20];
    char modelo[20];
    float tamano;
} MONITOR;

typedef struct notebook
{
    int id;
    char marca[20];
    char modelo[20];
    char procesador[30];
    float tamanoPantalla;
    int ram;
} NOTEBOOK;

typedef struct pc_escritorio
{
    int id;
    char marca[20];
    char modelo[20];
    int ram;
    char procesador[30];
    KEYBOARD teclado;
    MOUSE mouse;
    MONITOR monitor;
} DESKTOP;

int inicio_sesion(USER a);

int main()
{
    // USER
    USER usuario1 = {991, "admin", "admin123", "Kylian", "Mbappe", "Lottin"};
    // MOUSE
    MOUSE producto1[] = {11897, "Logitech", "G502 HERO"};
    MOUSE producto2[] = {11001, "HyperX", "FPS Pro"};
    MOUSE producto3[] = {11034, "Logitech", "Lightspeed"};
    // KEYBOARD
    KEYBOARD producto4[] = {11898, "Hyperx", "Alloy Core Rgb", "Español"};
    KEYBOARD producto5[] = {11937, "RAZER", "BLACKWIDOW", "Español"};
    KEYBOARD producto6[] = {11907, "RAZER", "CHROMA", "Español"};
    // MONITOR
    MONITOR producto7[] = {39453, "ASUS", "TUF Gaming", 27};
    MONITOR producto8[] = {39209, "Samsung", "C24RG50", 24};
    MONITOR producto9[] = {39106, "Viewsonic", "VX3218-PC-MHD", 32};
    // NOTEBOOK
    NOTEBOOK producto10[] = {45928, "Acer", "Aspire Nitro 5", "Intel Core i5-10300H", 15.6, 16};
    NOTEBOOK producto11[] = {45475, "HP", "Victus 16-D0511LA", "Intel Core i5-11400H", 16.1, 8};
    NOTEBOOK producto12[] = {45936, "ASUS", "TUF Gaming A15", "AMD Ryzen 5 4600H", 15.6, 8};

    // INICIO DE SESION
    int inicia = 0;
    int opcion, menu;
    strcat(usuario1.nombres, " ");
    strcat(usuario1.nombres, usuario1.apellidoPaterno);
    strcat(usuario1.nombres, " ");
    strcat(usuario1.nombres, usuario1.apellidoMaterno);
    inicia = inicio_sesion(usuario1);
    if (inicia == 0)
    {
        printf("\nUsuario o contrasena mal ingresados \n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\nBIENVENIDO AL SISTEMA DE GESTION Y CONTROL DE PRODUCTOS AKME \n");
        printf("\nNombre del usuario: %s \n\n", usuario1.nombres);
        system("pause");
    }

    menu = inicia;

    if (menu == 1)
    {
        do
        {
            fflush(stdin);
            system("cls");

            printf("\nNombre del usuario: %s \n\n", usuario1.nombres);
            printf("Que deseas hacer?\n");
            printf("\n1. Agregar un producto");
            printf("\n2. Actualizar un producto");
            printf("\n3. Listar los producto");
            printf("\n4. Buscar un producto con su marca");
            printf("\n5. Eliminar un producto");
            printf("\n6. Salir del programa \n");
            printf(">> ");
            scanf("%d", &opcion);

            switch (opcion)
            {
            case 1:
                system("cls");
                printf("hola");
                getch();
                break; // Funcion para agregar producto
            case 2:    // Funcion para actualizar producto
            case 3:    // Funcion para listar los productos
            case 4:    // Funcion para busqueda por marca
            case 5:    // Funcion para eliminar productos
            case 6:
                system("cls");
                printf("Hasta pronto, que tenga un buen dia!");
                break;
            default:
                system("cls");
                printf("Opcion no valida, ingrese nuevamente");
                getch();
                break;
            }
        } while (opcion != 6);
    }

    return 0;
}

int inicio_sesion(USER a)
{
    // INICIO DE SESION
    system("cls");
    char usuario[50];
    char clave[50];
    usuario[50] = a.nickname[50];
    clave[50] = a.password[50];
    char caracter;
    int i = 0;
    printf("INICIO DE SESION\n");
    printf("USUARIO: ");
    gets(usuario);
    printf("CLAVE: ");
    while (caracter = getch())
    {
        if (caracter == 13)
        {
            clave[i] = '\0';
            break;
        }
        else if (caracter == 8)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            printf("*");
            clave[i] = caracter;
            i++;
        }
    }

    if (strcmp(usuario, a.nickname) == 0 && strcmp(clave, a.password) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
