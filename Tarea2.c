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

//PROTOTIPOS DE FUNCIONES
int inicio_sesion(USER a);
void nombreVisible(USER a);

MOUSE agregar_mouse(MOUSE productos_mouse[], int aux);
void mostrar_mouse(MOUSE productos_mouse[], int aux);

KEYBOARD agregar_teclado(KEYBOARD productos_teclado[], int aux);
void mostrar_teclado(KEYBOARD productos_teclado[], int aux);

MONITOR agregar_monitor(MONITOR productos_monitor[], int aux);
void mostrar_monitor(MONITOR productos_monitor[], int aux);

NOTEBOOK agregar_notebook(NOTEBOOK productos_notebook[], int aux);
void mostrar_notebook(NOTEBOOK productos_notebook[], int aux);

void elegirProducto();

//PRECARGA DE PRODUCTOS
int main()
{
    // USER
    USER usuario1 = {991, "admin", "admin123", "Kylian", "Mbappe", "Lottin"};

    //MOUSE
    int auxMouse = 3;
    MOUSE productos_mouse[auxMouse];
            productos_mouse[0].id = 11897;
    strncpy(productos_mouse[0].marca, "Logitech",20);
    strncpy(productos_mouse[0].modelo, "G502 HERO",20);

            productos_mouse[1].id = 11001;
    strncpy(productos_mouse[1].marca,  "HyperX",20);
    strncpy(productos_mouse[1].modelo, "FPS Pro",20);

            productos_mouse[2].id = 11034;
    strncpy(productos_mouse[2].marca,"Logitech",20);
    strncpy(productos_mouse[2].marca, "Lightspeed",20);

    // KEYBOARD
    int auxKeyboard = 3;
    KEYBOARD productos_keyboard[auxKeyboard];
            productos_keyboard[0].id = 11898;
    strncpy(productos_keyboard[0].marca,"Hyperx",20); 
    strncpy(productos_keyboard[0].modelo,"Alloy Core Rgb",20);
    strncpy(productos_keyboard[0].idioma,"EspaÃ±ol",20);

            productos_keyboard[1].id = 11937;
    strncpy(productos_keyboard[1].marca,"RAZER",20); 
    strncpy(productos_keyboard[1].modelo,"BLACKWIDOW",20);
    strncpy(productos_keyboard[1].idioma,"EspaÃ±ol",20);

            productos_keyboard[2].id = 11907;
    strncpy(productos_keyboard[2].marca,"RAZER",20); 
    strncpy(productos_keyboard[2].modelo,"CHROMA",20);
    strncpy(productos_keyboard[2].idioma,"EspaÃ±ol",20);

    // MONITOR
    int auxMonitor = 3;
    MONITOR productos_monitor[auxMonitor];
            productos_monitor[0].id = 39453;
    strncpy(productos_monitor[0].marca,"ASUS",20);
    strncpy(productos_monitor[0].modelo, "TUF Gaming",20);
            productos_monitor[0].tamano =27;

            productos_monitor[1].id = 39453;
    strncpy(productos_monitor[1].marca,"Samsung",20);
    strncpy(productos_monitor[1].modelo, "C24RG50",20);
            productos_monitor[1].tamano =24;

            productos_monitor[2].id = 39106;
    strncpy(productos_monitor[2].marca,"Viewsonic",20);
    strncpy(productos_monitor[2].modelo, "VX3218-PC-MHD",20);
            productos_monitor[2].tamano = 32;

    // NOTEBOOK
    int auxNotebook = 3;
    NOTEBOOK productos_notebook[auxNotebook];
            productos_notebook[0].id = 45928;
    strncpy(productos_notebook[0].marca,"Acer",20);
    strncpy(productos_notebook[0].modelo,"Aspire Nitro 5",20);
    strncpy(productos_notebook[0].procesador,"Intel Core i5-10300H",30);
            productos_notebook[0].tamanoPantalla =  15.6;
            productos_notebook[0].ram =  16;

            productos_notebook[1].id = 45475;
    strncpy(productos_notebook[1].marca,"HP",20);
    strncpy(productos_notebook[1].modelo,"Victus 16-D0511LA",20);
    strncpy(productos_notebook[1].procesador,"Intel Core i5-11400H",30);
            productos_notebook[1].tamanoPantalla =  16.1;
            productos_notebook[1].ram =  8;

            productos_notebook[2].id = 45936;
    strncpy(productos_notebook[2].marca,"ASUS",20);
    strncpy(productos_notebook[2].modelo,"TUF Gaming A15",20);
    strncpy(productos_notebook[2].procesador,"AMD Ryzen 5 4600H",30);
            productos_notebook[2].tamanoPantalla =  15.6;
            productos_notebook[2].ram =  8;

    // INICIO DE SESION
    int inicia = 0;
    int menu, opcion, agregar, eliminar;
    do{
        inicia = inicio_sesion(usuario1);
        if (inicia == 0)
        {
            system("cls");
            printf("\nCREDENCIALES ERRONEAS, INGRESE NUEVAMENTE. \n");
            system("pause");
        }
        else
        {
            system("cls");
            nombreVisible(usuario1);
            printf("\nBIENVENIDO AL SISTEMA DE GESTION Y CONTROL DE PRODUCTOS AKME. \n");
            system("pause");
        }
    }while(inicia == 0);
    
    //MENU DE OPCIONES
    menu = inicia;
    if (menu == 1)
    {
        do
        {
            system("cls");
            nombreVisible(usuario1);
            printf("Que deseas hacer?\n");
            printf("\n1. Agregar productos");
            printf("\n2. Actualizar productos");
            printf("\n3. Listar los productos");
            printf("\n4. Buscar un producto por su marca");
            printf("\n5. Eliminar productos");
            printf("\n6. Salir del programa \n");
            printf(">> ");
            scanf("%d", &opcion);

            switch (opcion)
            {
            case 1: //AGREGAR UN PRODUCTO
                do{
                    system("cls");
                    elegirProducto();
                    scanf("%d", &agregar);
                    switch (agregar)
                    {
                        case 1:
                            auxMouse++;
                            agregar_mouse(productos_mouse, auxMouse);
                            mostrar_mouse(productos_mouse, auxMouse);
                            system("pause");
                            break;
                        case 2:
                            auxKeyboard++;
                            agregar_teclado(productos_keyboard, auxKeyboard);
                            mostrar_teclado(productos_keyboard, auxKeyboard);
                            system("pause");
                            break;
                        case 3:
                            auxMonitor++;
                            agregar_monitor(productos_monitor, auxMonitor);
                            mostrar_monitor(productos_monitor, auxMonitor);
                            system("pause");
                            break;
                        case 4:
                            auxNotebook++;
                            agregar_notebook(productos_notebook, auxNotebook);
                            mostrar_notebook(productos_notebook, auxNotebook);
                            system("pause");
                            break;
                        case 5:
                            break;
                        default:
                            system("cls");
                            printf("Opcion no valida, ingrese nuevamente");
                            getch();
                            break;
                    }
                }while(agregar !=5);
            break;
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

//FUNCIONES
//VALIDAR CREDENCIALES DE INICIO DE SESION
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

//CONCATENAR NOMBRE DE USUARIO Y TENERLO SIEMPRE VISIBLE EN PANTALLA
void nombreVisible(USER a){
    strcat(a.nombres, " ");
    strcat(a.nombres, a.apellidoPaterno);
    strcat(a.nombres, " ");
    strcat(a.nombres, a.apellidoMaterno);

    printf("Nombre del usuario: %s \n\n", a.nombres);
}

//FUNCION PARA AGREGAR PRODUCTOS
//MOUSE
MOUSE agregar_mouse(MOUSE productos_mouse[], int aux)
{
    printf("\nAGREGAR MOUSE N*%d: \n\n", aux);
    printf("Ingrese ID: ");
    fflush(stdin);
    scanf("%d", &productos_mouse[aux].id);
    printf("Ingrese marca: ");
    fflush(stdin);
    gets(productos_mouse[aux].marca);
    printf("Ingrese modelo: ");
    fflush(stdin);
    gets(productos_mouse[aux].modelo);

    return productos_mouse[aux];
}
//MOSTRAR MOUSE AGREGADO
void mostrar_mouse(MOUSE productos_mouse[], int aux)
{
    printf("\nEl id del mouse es: %d \n", productos_mouse[aux].id);
    fflush(stdin);
    printf("La marca del mouse es: %s \n", productos_mouse[aux].marca);
    fflush(stdin);
    printf("El modelo del mouse es: %s \n", productos_mouse[aux].modelo);
}

//TECLADO
KEYBOARD agregar_teclado(KEYBOARD productos_teclado[], int aux)
{
    printf("\nAGREGAR TECLADO N*%d: \n\n", aux);
    printf("Ingrese ID: ");
    fflush(stdin);
    scanf("%d", &productos_teclado[aux].id);
    printf("Ingrese marca: ");
    fflush(stdin);
    gets(productos_teclado[aux].marca);
    printf("Ingrese modelo: ");
    fflush(stdin);
    gets(productos_teclado[aux].modelo);
    printf("Ingrese idioma: ");
    fflush(stdin);
    gets(productos_teclado[aux].idioma);

    return productos_teclado[aux];
}
//MOSTRAR TECLADO AGREGADO
void mostrar_teclado(KEYBOARD productos_teclado[], int aux)
{
    printf("\nEl id del teclado es: %d \n", productos_teclado[aux].id);
    printf("La marca del teclado es: %s \n", productos_teclado[aux].marca);
    printf("El modelo del teclado es: %s \n", productos_teclado[aux].modelo);
    printf("El idioma del teclado es: %s \n", productos_teclado[aux].idioma);
}

//MONITOR
MONITOR agregar_monitor(MONITOR productos_monitor[], int aux)
{
    printf("\nAGREGAR MONITOR N*%d: \n\n", aux);
    printf("Ingrese ID: ");
    fflush(stdin);
    scanf("%d", &productos_monitor[aux].id);
    printf("Ingrese marca: ");
    fflush(stdin);
    gets(productos_monitor[aux].marca);
    printf("Ingrese modelo: ");
    fflush(stdin);
    gets(productos_monitor[aux].modelo);
    printf("Ingrese tamano: ");
    fflush(stdin);
    scanf("%f", &productos_monitor[aux].tamano);

    return productos_monitor[aux];
}
//MOSTRAR MONITOR AGREGADO
void mostrar_monitor(MONITOR productos_monitor[], int aux)
{
    printf("\nEl id del monitor es: %d \n", productos_monitor[aux].id);
    printf("La marca del monitor es: %s \n", productos_monitor[aux].marca);
    printf("El modelo del monitor es: %s \n", productos_monitor[aux].modelo);
    printf("El tamano del monitor es: %.1f \n", productos_monitor[aux].tamano);
}

//NOTEBOOK
NOTEBOOK agregar_notebook(NOTEBOOK productos_notebook[], int aux)
{
    printf("\nAGREGAR NOTEBOOK N*%d: \n\n", aux);
    printf("Ingrese ID: ");
    fflush(stdin);
    scanf("%d", &productos_notebook[aux].id);
    printf("Ingrese marca: ");
    fflush(stdin);
    gets(productos_notebook[aux].marca);
    printf("Ingrese modelo: ");
    fflush(stdin);
    gets(productos_notebook[aux].modelo);
    printf("Ingrese procesador: ");
    fflush(stdin);
    gets(productos_notebook[aux].procesador);
    printf("Ingrese tamano: ");
    fflush(stdin);
    scanf("%f", &productos_notebook[aux].tamanoPantalla);

    return productos_notebook[aux];
}
//MOSTRAR NOTEBOOK AGREGADO
void mostrar_notebook(NOTEBOOK productos_notebook[], int aux)
{
    printf("\nEl id del notebook es: %d \n", productos_notebook[aux].id);
    printf("La marca del notebook es: %s \n", productos_notebook[aux].marca);
    printf("El modelo del notebook es: %s \n", productos_notebook[aux].modelo);
    printf("El procesador del notebook es: %s \n", productos_notebook[aux].procesador);
    printf("El tamano de pantalla del notebook es: %.1f \n", productos_notebook[aux].tamanoPantalla);
}

void elegirProducto()
{
    printf("Que tipo de producto deseas agregar?\n");
    printf("\n1. Mouse");
    printf("\n2. Teclado");
    printf("\n3. Monitor");
    printf("\n4. Notebook");
    printf("\n5. Volver atras\n");
    printf(">> ");
}

