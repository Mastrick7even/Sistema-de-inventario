// Diego Vargas Gomez
// Bastian Arriagada Quero
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    // PRECARGA STRUCT
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
    inicia = inicio_sesion(usuario1);
    if (inicia == 0)
    {
        inicia = inicio_sesion(usuario1);
        do
        {
            inicia = inicio_sesion(usuario1);
        } while (inicia == 0);
    }
    if (inicia == 1)
    {
        printf("\n \t BIENVENIDO AL SISTEMA \n");
        system("pause");
    }

    return 0;
}

int inicio_sesion(USER a)
{
    // INICIO DE SESION
    system("cls");
    char usuario[20] = {a.nickname};
    char clave[20] = {a.password};
    char caracter;
    int i = 0;
    printf("\n\t\t INICIO DE SESION \n");
    printf("\nUSUARIO:");
    gets(usuario);
    printf("CLAVE:");
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
        printf("\n Usuario o contrasena mal ingresados \n");
        system("pause");
        return 0;
    }
}