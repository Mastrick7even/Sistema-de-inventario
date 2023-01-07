// Diego Vargas Gomez: 21.012.009-2
// Bastian Arriagada Quero: 21.213.125-3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
    char marca[30];
    char modelo[30];
    char idioma[30];
} KEYBOARD;

typedef struct mouse
{
    int id;
    char marca[30];
    char modelo[30];
} MOUSE;

typedef struct monitor
{
    int id;
    char marca[30];
    char modelo[30];
    float tamano;
} MONITOR;

typedef struct notebook
{
    int id;
    char marca[30];
    char modelo[30];
    char procesador[30];
    float tamanoPantalla;
    int ram;
} NOTEBOOK;

typedef struct pc_escritorio
{
    int id;
    char marca[30];
    char modelo[30];
    int ram;
    char procesador[30];
    KEYBOARD teclado;
    MOUSE mouse;
    MONITOR monitor;
} DESKTOP;

//PROTOTIPOS DE FUNCIONES

void precarga_mouse(MOUSE productos_mouse[]);
void precarga_teclado(KEYBOARD productos_keyboard[]);
void precarga_monitor(MONITOR productos_monitor[]);
void precarga_notebook(NOTEBOOK productos_notebook[]);
void precarga_desktop(DESKTOP productos_desktop[]);

int inicio_sesion(USER a);
void nombreVisible(USER a);
void elegirProducto();
void logo_akme();
void bienvenido();

MOUSE agregar_mouse(MOUSE productos_mouse[], int aux);
KEYBOARD agregar_teclado(KEYBOARD productos_teclado[], int aux);
MONITOR agregar_monitor(MONITOR productos_monitor[], int aux);
NOTEBOOK agregar_notebook(NOTEBOOK productos_notebook[], int aux);
DESKTOP agregar_desktop(DESKTOP productos_desktop[], int aux);

void eliminar_mouse(MOUSE productos_mouse[], int *aux);
void eliminar_keyboard(KEYBOARD productos_keyboard[], int *aux);
void eliminar_monitor(MONITOR productos_monitor[], int *aux);
void eliminar_notebook(NOTEBOOK productos_notebook[], int *aux);
void eliminar_desktop(DESKTOP productos_desktop[], int *aux);

void listar_mouse(MOUSE productos_mouse[], int aux);
void listar_teclado(KEYBOARD productos_keyboard[], int aux);
void listar_monitor(MONITOR productos_monitor[], int aux);
void listar_notebook(NOTEBOOK productos_notebook[], int aux);
void listar_desktop(DESKTOP productos_desktop[], int aux);

MOUSE actualizar_mouse(MOUSE productos_mouse[]);
KEYBOARD actualizar_keyboard(KEYBOARD productos_keyboard[]);
MONITOR actualizar_monitor(MONITOR productos_monitor[]);
NOTEBOOK actualizar_notebook(NOTEBOOK productos_notebook[]);
DESKTOP actualizar_desktop(DESKTOP productos_desktop[]);

int busquedaMarcaMouse(MOUSE productos_mouse[], int aux, char marca[], int bandera);
int busquedaMarcaTeclado(KEYBOARD productos_teclado[], int aux, char marca[], int bandera);
int busquedaMarcaMonitor(MONITOR productos_monitor[], int aux, char marca[], int bandera);
int busquedaMarcaNotebook(NOTEBOOK productos_notebook[], int aux, char marca[], int bandera);
int busquedaMarcaDesktop(DESKTOP productos_desktop[], int aux, char marca[], int bandera);

void concatenar_mouse(MOUSE productos_mouse[], int aux);
void concatenar_keyboard(KEYBOARD productos_keyboard[], int aux);
void concatenar_monitor(MONITOR productos_monitor[], int aux);
void concatenar_notebook(NOTEBOOK productos_notebook[], int aux);
void concatenar_desktop(DESKTOP productos_desktop[], int aux);

void mostrar_mouse(MOUSE productos_mouse[], int aux);
void mostrar_teclado(KEYBOARD productos_teclado[], int aux);
void mostrar_monitor(MONITOR productos_monitor[], int aux);
void mostrar_notebook(NOTEBOOK productos_notebook[], int aux);
void mostrar_desktop(DESKTOP productos_desktop[], int aux);

//PRECARGA DE PRODUCTOS
int main()
{
    // USER
    USER usuario1 = {991, "admin", "admin123", "Kylian", "Mbappe", "Lottin"};

    //MOUSE
    int auxMouse = 3;
    MOUSE productos_mouse[100];
    precarga_mouse(productos_mouse);

    // KEYBOARD
    int auxKeyboard = 3;
    KEYBOARD productos_keyboard[100];
    precarga_teclado(productos_keyboard);

    // MONITOR
    int auxMonitor = 3;
    MONITOR productos_monitor[100];
    precarga_monitor(productos_monitor);

    // NOTEBOOK
    int auxNotebook = 3;
    NOTEBOOK productos_notebook[100];
    precarga_notebook(productos_notebook);

    //PC de escritorio
    int auxDesktop = 3;
    DESKTOP productos_desktop[100];
    precarga_desktop(productos_desktop);

    // INICIO DE SESION
    int inicia = 0;
    int menu, opcion, agregar, eliminar, actualizar, busqueda, i;
    char marca[30];
    do{
        inicia = inicio_sesion(usuario1);
        if (inicia == 0)
        {
            printf("\033[0;31m");
            printf("\nCredenciales erroneas, ingrese nuevamente. \n\n");
            printf("\033[0m");
            printf("\033[1;30m");
            system("pause");
            printf("\033[0m");
        }
        else
        {
            system("cls");
            printf("\033[0;32m");
            bienvenido();
            printf("\033[0m");
            nombreVisible(usuario1);
            printf("\033[1;30m");
            system("pause");
            printf("\033[0m");
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
            logo_akme();
            printf("\033[0;32m");
            printf("Que deseas hacer?\n");
            printf("\033[0m");
            printf("\n1. Agregar productos");
            printf("\n2. Actualizar productos");
            printf("\n3. Listar los productos");
            printf("\n4. Buscar un producto por su marca");
            printf("\n5. Eliminar productos");
            printf("\n6. Salir del programa \n");
            printf("\033[0;32m");
            printf(">> ");
            printf("\033[0m");
            scanf("%d", &opcion);

            switch (opcion)
            {
            case 1://AGREGAR UN PRODUCTO
                do{
                    system("cls");
                    nombreVisible(usuario1);
                    printf("\033[1;32m");
                    printf("Que tipo de producto deseas agregar?\n");
                    printf("\033[0m");
                    elegirProducto();
                    scanf("%d", &agregar);

                    switch (agregar)
                    {
                        case 1://mouse
                            auxMouse++;
                            system("cls");
                            nombreVisible(usuario1);
                            agregar_mouse(productos_mouse, auxMouse);
                            printf("\033[0;32m");
                            printf("\nProducto agregado correctamente!\n\n");
                            printf("\033[0m");
                            printf("\033[1;30m");
                            system("pause");
                            printf("\033[0m");
                            break;

                        case 2://teclado
                            auxKeyboard++;
                            system("cls");
                            nombreVisible(usuario1);
                            agregar_teclado(productos_keyboard, auxKeyboard);
                            printf("\033[0;32m");
                            printf("\nProducto agregado correctamente!\n\n");
                            printf("\033[0m");
                            printf("\033[1;30m");
                            system("pause");
                            printf("\033[0m");
                            break;

                        case 3://monitor
                            auxMonitor++;
                            system("cls");
                            nombreVisible(usuario1);
                            agregar_monitor(productos_monitor, auxMonitor);
                            printf("\033[0;32m");
                            printf("\nProducto agregado correctamente!\n\n");
                            printf("\033[0m");
                            printf("\033[1;30m");
                            system("pause");
                            printf("\033[0m");
                            break;

                        case 4://notebook
                            auxNotebook++;
                            system("cls");
                            nombreVisible(usuario1);
                            agregar_notebook(productos_notebook, auxNotebook);
                            printf("\033[0;32m");
                            printf("\nProducto agregado correctamente!\n\n");
                            printf("\033[0m");
                            printf("\033[1;30m");
                            system("pause");
                            printf("\033[0m");
                            break;

                        case 5://desktop
                            auxDesktop++;
                            system("cls");
                            nombreVisible(usuario1);
                            agregar_desktop(productos_desktop, auxDesktop);
                            printf("\033[0;32m");
                            printf("\nProducto agregado correctamente!\n\n");
                            printf("\033[0m");
                            printf("\033[1;30m");
                            system("pause");
                            printf("\033[0m");
                            break;

                        case 6://salir
                            break;

                        default://mal ingresado
                            system("cls");
                            nombreVisible(usuario1);
                            printf("Opcion no valida, ingrese nuevamente");
                            getch();
                            break;
                    }
                }while(agregar !=6);
                break;

            case 2:// ACTUALIZAR UN PRODUCTO
            do{
                    system("cls");
                    nombreVisible(usuario1);
                    printf("\033[0;32m");
                    printf("Que tipo de producto deseas actualizar?\n");
                    printf("\033[0m");
                    elegirProducto();
                    scanf("%d", &actualizar);

                    switch (actualizar)
                    {
                        case 1://mouse
                            concatenar_mouse(productos_mouse, auxMouse);
                            actualizar_mouse(productos_mouse);
                            printf("\033[0;33m");
                            printf("\nProducto actualizado!\n");
                            printf("\033[0m");
                            printf("\033[1;30m");
                            system("pause");
                            printf("\033[0m");
                            break;

                        case 2://teclado
                            concatenar_keyboard(productos_keyboard, auxKeyboard);
                            actualizar_keyboard(productos_keyboard);
                            printf("\033[0;33m");
                            printf("\nProducto actualizado!\n");
                            printf("\033[0m");
                            printf("\033[1;30m");
                            system("pause");
                            printf("\033[0m");
                            break;

                        case 3://monitor
                            concatenar_monitor(productos_monitor, auxMonitor);
                            actualizar_monitor(productos_monitor);
                            printf("\033[0;33m");
                            printf("\nProducto actualizado!\n");
                            printf("\033[0m");
                            printf("\033[1;30m");
                            system("pause");
                            printf("\033[0m");
                            break;

                        case 4://notebook
                            concatenar_notebook(productos_notebook, auxNotebook);
                            actualizar_notebook(productos_notebook);
                            printf("\033[0;33m");
                            printf("\nProducto actualizado!\n");
                            printf("\033[0m");
                            printf("\033[1;30m");
                            system("pause");
                            printf("\033[0m");
                            break;

                        case 5://desktop
                            concatenar_desktop(productos_desktop, auxDesktop);
                            actualizar_desktop(productos_desktop);
                            printf("\033[0;33m");
                            printf("\nProducto actualizado!\n");
                            printf("\033[0m");
                            printf("\033[1;30m");
                            system("pause");
                            printf("\033[0m");
                            break;

                        case 6://salir
                            break;

                        default://mal ingresado
                            system("cls");
                            nombreVisible(usuario1);
                            printf("Opcion no valida, ingrese nuevamente");
                            getch();
                            break;
                    }
                }while(actualizar !=6);
                break;

            case 3:// LISTAR LOS PRODUCTOS
            
                system("cls");
                nombreVisible(usuario1);
                printf("\033[1;34m");
                printf("-------------------------------------\n");
                printf("\033[0m");
                printf("\033[0;32m");
                printf("MOUSE:\n");
                printf("\033[0m");
                listar_mouse(productos_mouse, auxMouse);
                
                printf("\033[1;34m");
                printf("-------------------------------------\n");
                printf("\033[0m");
                printf("\033[0;32m");
                printf("TECLADOS.\n");
                printf("\033[0m");
                listar_teclado(productos_keyboard, auxKeyboard);
                
                printf("\033[1;34m");
                printf("-------------------------------------\n");
                printf("\033[0m");
                printf("\033[0;32m");
                printf("MONITORES.\n");
                printf("\033[0m");
                listar_monitor(productos_monitor, auxMonitor);
                
                printf("\033[1;34m");
                printf("-------------------------------------\n");
                printf("\033[0m");
                printf("\033[0;32m");
                printf("NOTEBOOKS.\n");
                printf("\033[0m");
                listar_notebook(productos_notebook, auxNotebook);

                printf("\033[1;34m");
                printf("-------------------------------------\n");
                printf("\033[0m");
                printf("\033[0;32m");
                printf("PCs de escritorio.\n");
                printf("\033[0m");
                listar_desktop(productos_desktop, auxDesktop);
                printf("\033[1;34m");
                printf("-------------------------------------\n");
                printf("\033[0m");
                printf("\033[1;30m");
                system("pause");
                printf("\033[0m");

                break;

            case 4://BUSQUEDA POR MARCA (RECURSIVIDAD)
            system("cls");
            nombreVisible(usuario1);
            printf("\033[0;32m");     
            printf("Ingrese marca a buscar: ");
            printf("\033[0m");
            fflush(stdin);
            gets(marca);
            for(i = 0; marca[i] != '\0'; i++){
                marca[i] = toupper(marca[i]);
            }
    
            printf("\n\n");
            
            printf("Mouse: \n");
            if(busquedaMarcaMouse(productos_mouse, auxMouse-1, marca, 0) == 1){
                printf("\033[0;32m");
                printf("\nBusqueda de mouse completa\n\n");
                printf("\033[0m");
            } else{
                printf("\033[0;31m");
                printf("No existen mouse que correspondan a esa marca.\n\n");
                printf("\033[0m");
            }

            printf("Teclados: \n");
            if(busquedaMarcaTeclado(productos_keyboard, auxKeyboard-1, marca, 0) == 1){
                printf("\033[0;32m");
                printf("\nBusqueda de teclados completa\n\n");
                printf("\033[0m");
            } else{
                printf("\033[0;31m");
                printf("No existen teclados que correspondan a la marca ingresada.\n\n");
                printf("\033[0m");
            }

            printf("Monitores: \n");
            if(busquedaMarcaMonitor(productos_monitor, auxMonitor-1, marca, 0) == 1){
                printf("\033[0;32m");
                printf("\nBusqueda de monitores completa\n\n");
                printf("\033[0m");
            } else{
                printf("\033[0;31m");
                printf("No existen monitores que correspondan a la marca ingresada.\n\n");
                printf("\033[0m");
            }

            printf("Notebooks: \n");
            if(busquedaMarcaNotebook(productos_notebook, auxNotebook-1, marca, 0) == 1){
                printf("\033[0;32m");
                printf("\nBusqueda de notebooks completa\n\n");
                printf("\033[0m");
            } else{
                printf("\033[0;31m");
                printf("No existen notebooks que correspondan a la marca ingresada.\n\n");
                printf("\033[0m");
            }

            printf("Pc de escritorio: \n");
            if(busquedaMarcaDesktop(productos_desktop, auxDesktop-1, marca, 0) == 1){
                printf("\033[0;32m");
                printf("\nBusqueda de PCs completa\n\n");
                printf("\033[0m");
            } else{
                printf("\033[0;31m");
                printf("No existen PCs de escritorio que correspondan a la marca ingresada.\n\n");
                printf("\033[0m");
            }
            printf("\033[1;30m");
            system("pause");
            printf("\033[0m");
            break;
            
            case 5://ELIMINAR PRODUCTOS
                do{
                    system("cls");
                    nombreVisible(usuario1);
                    printf("\033[0;32m");
                    printf("Que tipo de producto deseas eliminar?\n");
                    printf("\033[0m");
                    elegirProducto();
                    scanf("%d", &eliminar);

                    switch (eliminar)
                    {
                        case 1://mouse
                            system("cls");
                            nombreVisible(usuario1);
                            printf("Eliminar mouse: \n\n");
                            concatenar_mouse(productos_mouse, auxMouse);
                            eliminar_mouse(productos_mouse, &auxMouse);
                            printf("\033[0;31m");
                            printf("\n%c Producto eliminado %c\n\n", 207, 207);
                            printf("\033[0m");
                            printf("\033[1;30m");
                            system("pause");
                            printf("\033[0m");
                            break;

                        case 2://teclado
                            system("cls");
                            nombreVisible(usuario1);
                            printf("Eliminar teclado: \n\n");
                            concatenar_keyboard(productos_keyboard, auxKeyboard);
                            eliminar_keyboard(productos_keyboard, &auxKeyboard);
                            printf("\033[0;31m");
                            printf("\n%c Producto eliminado %c\n\n", 207, 207);
                            printf("\033[0m");
                            printf("\033[1;30m");
                            system("pause");
                            printf("\033[0m");
                            break;

                        case 3://monitor
                            system("cls");
                            nombreVisible(usuario1);
                            printf("Eliminar monitor: \n\n");
                            concatenar_monitor(productos_monitor, auxMonitor);
                            eliminar_monitor(productos_monitor, &auxMonitor);
                            printf("\033[0;31m");
                            printf("\n%c Producto eliminado %c\n\n\n\n", 207, 207);
                            printf("\033[0m");
                            printf("\033[1;30m");
                            system("pause");
                            printf("\033[0m");
                            break;
                        case 4://notebook
                            system("cls");
                            nombreVisible(usuario1);
                            printf("Eliminar notebook: \n\n");
                            concatenar_notebook(productos_notebook, auxNotebook);
                            eliminar_notebook(productos_notebook, &auxNotebook);
                            printf("\033[0;31m");
                            printf("\n%c Producto eliminado %c\n\n", 207, 207);
                            printf("\033[0m");
                            printf("\033[1;30m");
                            system("pause");
                            printf("\033[0m");
                            break;

                        case 5://desktop
                            system("cls");
                            nombreVisible(usuario1);
                            printf("Eliminar PC: \n\n");
                            concatenar_desktop(productos_desktop, auxDesktop);
                            eliminar_desktop(productos_desktop, &auxDesktop);
                            printf("\033[0;31m");
                            printf("\n%c Producto eliminado %c\n\n", 207, 207);
                            printf("\033[0m");
                            printf("\033[1;30m");
                            system("pause");
                            printf("\033[0m");
                            break;
                        
                        case 6://salir
                            break;

                        default://mal ingresado
                            system("cls");
                            nombreVisible(usuario1);
                            printf("Opcion no valida, ingrese nuevamente");
                            getch();
                            break;
                    }
                }while(eliminar !=6);
                break;

            case 6:
                system("cls");
                nombreVisible(usuario1);
                logo_akme();
                printf("\033[36m");
                printf("\t\t\t\tHasta pronto, que tenga un buen dia!");
                printf("\033[0m");
                printf("\n\n");
            break;

            default:
                system("cls");
                nombreVisible(usuario1);
                printf("Opcion no valida, ingrese nuevamente");
                getch();
            break;
            }
        }while (opcion != 6);
    }
    return 0;
}

//FUNCIONES:
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
    logo_akme();
    printf("\033[4;33m");
    printf("INICIO DE SESION\n\n");
    printf("\033[0m");
    printf("\033[36m");
    printf("USUARIO: ");
    printf("\033[0m");
    gets(usuario);
    printf("\033[36m");
    printf("CLAVE: ");
    printf("\033[0m");
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
    printf("\033[1;34m");
    printf("\t\t\t\tNombre del usuario: %s \n\n\n", a.nombres);
    printf("\033[0m");
}
//OPCIONES PARA ELEGIR PRODUCTO
void elegirProducto()
{
    printf("\n1. Mouse");
    printf("\n2. Teclado");
    printf("\n3. Monitor");
    printf("\n4. Notebook");
    printf("\n5. PC de escritorio");
    printf("\n6. Volver atras\n");
    printf("\033[0;32m");
    printf(">> ");
    printf("\033[0m");
}

//AGREGAR PRODUCTOS
MOUSE agregar_mouse(MOUSE productos_mouse[], int aux)
{
    int i;
    char marca[30];
    printf("AGREGAR MOUSE ");
    printf("N%c%d: \n\n", 248, aux);
    printf("Ingrese ID: ");
    fflush(stdin);
    scanf("%d", &productos_mouse[aux-1].id);
    printf("Ingrese marca: ");
    fflush(stdin);
    gets(marca);
    for(i = 0; marca[i] != '\0' ; i++){ 
            marca[i] = toupper(marca[i]);
        }
    strcpy(productos_mouse[aux-1].marca, marca);
    printf("Ingrese modelo: ");
    fflush(stdin);
    gets(productos_mouse[aux-1].modelo);

    return productos_mouse[aux-1];
}
KEYBOARD agregar_teclado(KEYBOARD productos_teclado[], int aux)
{
    int i;
    char marca[30];
    printf("AGREGAR TECLADO ");
    printf("N%c%d: \n\n", 248, aux);
    printf("Ingrese ID: ");
    fflush(stdin);
    scanf("%d", &productos_teclado[aux-1].id);
    printf("Ingrese marca: ");
    fflush(stdin);
    gets(marca);
    for(i = 0; marca[i] != '\0'; i++){
            marca[i] = toupper(marca[i]);
        }
    strcpy(productos_teclado[aux-1].marca, marca);
    printf("Ingrese modelo: ");
    fflush(stdin);
    gets(productos_teclado[aux-1].modelo);
    printf("Ingrese idioma: ");
    fflush(stdin);
    gets(productos_teclado[aux-1].idioma);

    return productos_teclado[aux-1];
}
MONITOR agregar_monitor(MONITOR productos_monitor[], int aux)
{
    int i;
    char marca[30];
    printf("AGREGAR MONITOR ");
    printf("N%c%d: \n\n", 248, aux);
    printf("Ingrese ID: ");
    fflush(stdin);
    scanf("%d", &productos_monitor[aux-1].id);
    printf("Ingrese marca: ");
    fflush(stdin);
    gets(marca);
    for(i = 0; marca[i] != '\0'; i++){
        marca[i] = toupper(marca[i]);
    }
    strcpy(productos_monitor[aux-1].marca, marca);
    printf("Ingrese modelo: ");
    fflush(stdin);
    gets(productos_monitor[aux-1].modelo);
    printf("Ingrese tamano: ");
    fflush(stdin);
    scanf("%f", &productos_monitor[aux-1].tamano);

    return productos_monitor[aux-1];
}
NOTEBOOK agregar_notebook(NOTEBOOK productos_notebook[], int aux)
{
    int i;
    char marca[30];
    printf("AGREGAR NOTEBOOK ");
    printf("N%c%d: \n\n", 248, aux);
    printf("Ingrese ID: ");
    fflush(stdin);
    scanf("%d", &productos_notebook[aux-1].id);
    printf("Ingrese marca: ");
    fflush(stdin);
    gets(marca);
    for(i = 0; marca[i] != '\0'; i++){
        marca[i] = toupper(marca[i]);
    }
    strcpy(productos_notebook[aux-1].marca, marca);
    printf("Ingrese modelo: ");
    fflush(stdin);
    gets(productos_notebook[aux-1].modelo);
    printf("Ingrese procesador: ");
    fflush(stdin);
    gets(productos_notebook[aux-1].procesador);
    printf("Ingrese tamano de pantalla: ");
    fflush(stdin);
    scanf("%f", &productos_notebook[aux-1].tamanoPantalla);
    printf("Ingrese cantidad de ram: ");
    fflush(stdin);
    scanf("%d", &productos_notebook[aux-1].ram);

    return productos_notebook[aux-1];
}
DESKTOP agregar_desktop(DESKTOP productos_desktop[], int aux)
{
    int i;
    char marca[30];
    printf("AGREGAR PC ");
    printf("N%c%d: \n\n", 248, aux);
    printf("Ingrese ID: ");
    scanf("%d", &productos_desktop[aux-1].id);
    printf("Ingrese marca: ");
    fflush(stdin);
    gets(marca);
    for(i = 0; marca[i] != '\0'; i++){
        marca[i] = toupper(marca[i]);
    }
    strcpy(productos_desktop[aux-1].marca, marca);
    printf("Ingrese modelo: ");
    fflush(stdin);
    gets(productos_desktop[aux-1].modelo);
    printf("Ingrese procesador: ");
    fflush(stdin);
    gets(productos_desktop[aux-1].procesador);
    printf("Ingrese cantidad de ram: ");
    scanf("%d", &productos_desktop[aux-1].ram);
    gets(productos_desktop[aux-1].procesador);
    printf("Ingrese nombre mouse: ");
    fflush(stdin);
    gets(productos_desktop[aux-1].mouse.modelo);
    printf("Ingrese nombre teclado: ");
    fflush(stdin);
    gets(productos_desktop[aux-1].teclado.modelo);
    printf("Ingrese nombre monitor: ");
    fflush(stdin);
    gets(productos_desktop[aux-1].monitor.modelo);
    
    return productos_desktop[aux-1];
}

//FUNCION PARA LISTAR PRODUCTOS
void listar_mouse(MOUSE productos_mouse[], int aux)
{
    int i;
    printf("\033[1;33m");
    printf("Stock disponible: %d \n\n", aux);
    printf("\033[0m");
    for(i = 0; i < aux; i++){
        printf("ID: %d \n", productos_mouse[i].id);
        printf("Marca: %s \n", productos_mouse[i].marca);
        printf("Modelo: %s \n\n", productos_mouse[i].modelo);
    }  
    
}
void listar_teclado(KEYBOARD productos_keyboard[], int aux)
{
    int i;
    printf("\033[1;33m");
    printf("Stock disponible: %d \n\n", aux);
    printf("\033[0m");
    for(i = 0; i < aux; i++){
        printf("ID: %d \n", productos_keyboard[i].id);
        printf("Marca: %s \n", productos_keyboard[i].marca);
        printf("Modelo: %s \n", productos_keyboard[i].modelo);
        printf("Idioma: %s \n\n", productos_keyboard[i].idioma);
    }
    
}
void listar_monitor(MONITOR productos_monitor[], int aux)
{
    int i;
    printf("\033[1;33m");
    printf("Stock disponible: %d \n\n", aux);
    printf("\033[0m");
    for(i = 0; i < aux; i++){
        printf("ID: %d \n", productos_monitor[i].id);
        printf("Marca: %s \n", productos_monitor[i].marca);
        printf("Modelo: %s \n", productos_monitor[i].modelo);
        printf("Tamano de pantalla: %.1f pulgadas \n\n", productos_monitor[i].tamano);
    }
    
}
void listar_notebook(NOTEBOOK productos_notebook[], int aux)
{
    int i;
    printf("\033[1;33m");
    printf("Stock disponible: %d \n\n", aux);
    printf("\033[0m");
    for(i = 0; i < aux; i++){
        printf("ID: %d \n", productos_notebook[i].id);
        printf("Marca: %s \n", productos_notebook[i].marca);
        printf("Modelo: %s \n", productos_notebook[i].modelo);
        printf("Procesador: %s \n", productos_notebook[i].procesador);
        printf("Tamano de pantalla: %.1f pulgadas \n", productos_notebook[i].tamanoPantalla);
        printf("Cantidad de ram: %d  \n\n", productos_notebook[i].ram);
    } 
    
}
void listar_desktop(DESKTOP productos_desktop[], int aux)
{
    int i;
    printf("\033[1;33m");
    printf("Stock disponible: %d \n\n", aux);
    printf("\033[0m");
    for(i = 0; i < aux; i++){
        printf("ID: %d \n", productos_desktop[i].id);
        printf("Marca: %s \n", productos_desktop[i].marca);
        printf("Modelo: %s \n", productos_desktop[i].modelo);
        printf("Procesador: %s \n", productos_desktop[i].procesador);
        printf("Cantidad de ram: %d GB  \n", productos_desktop[i].ram);
        printf("Mouse: %s \n", productos_desktop[i].mouse.modelo);
        printf("Teclado: %s\n", productos_desktop[i].teclado.modelo);
        printf("Monitor: %s \n\n", productos_desktop[i].monitor.modelo);
    }
}

//MOSTRAR PRODUCTOS CON DATOS CONCATENADOS
void concatenar_mouse(MOUSE productos_mouse[], int aux)
{
    int i;
    for(i = 0; i < aux; i++ )
    {
        char nombre[30];
        memset(nombre, 0, 30);
        strcat(nombre, productos_mouse[i].marca);
        strcat(nombre, " ");
        strcat(nombre, productos_mouse[i].modelo);
        printf("\033[0;31m");
        printf("%d. ", i+1);
        printf("\033[0m");
        printf("%s\n\n", nombre);
        
    }
}
void concatenar_keyboard(KEYBOARD productos_keyboard[], int aux)
{
    int i;
    for(i = 0; i < aux; i++ )
    {
        char nombre[30];
        memset(nombre, 0, 30);
        strcat(nombre, productos_keyboard[i].marca);
        strcat(nombre, " ");
        strcat(nombre, productos_keyboard[i].modelo);
        strcat(nombre, ", ");
        strcat(nombre, productos_keyboard[i].idioma);
        printf("\033[0;31m");
        printf("%d. ", i+1);
        printf("\033[0m");
        printf("%s\n\n", nombre);
        
    }
}
void concatenar_monitor(MONITOR productos_monitor[], int aux)
{
    int i;
    for(i = 0; i < aux; i++ )
    {
        char nombre[30];
        memset(nombre, 0, 30);
        strcat(nombre, productos_monitor[i].marca);
        strcat(nombre, " ");
        strcat(nombre, productos_monitor[i].modelo);
        printf("\033[0;31m");
        printf("%d. ", i+1);
        printf("\033[0m");
        printf("%s", nombre);
        printf(", %.1f pulgadas\n\n", productos_monitor[i].tamano);
    }
}
void concatenar_notebook(NOTEBOOK productos_notebook[], int aux)
{
    int i;
    for(i = 0; i < aux; i++ )
    {
        char nombre[30];
        memset(nombre, 0, 30);
        strcat(nombre, productos_notebook[i].marca);
        strcat(nombre, " ");
        strcat(nombre, productos_notebook[i].modelo);
        strcat(nombre, ", ");
        strcat(nombre, productos_notebook[i].procesador);;
        printf("\033[0;31m");
        printf("%d. ", i+1);
        printf("\033[0m");
        printf("%s", nombre);
        printf(", %dgb ram", productos_notebook[i].ram);
        printf(", %.1f pulgadas de pantalla\n\n", productos_notebook[i].tamanoPantalla);
    }
}
void concatenar_desktop(DESKTOP productos_desktop[], int aux)
{
    int i;
    for(i = 0; i < aux; i++ )
    {
        char nombre[30];
        memset(nombre, 0, 30);
        strcat(nombre, productos_desktop[i].marca);
        strcat(nombre, " ");
        strcat(nombre, productos_desktop[i].modelo);
        strcat(nombre, ", ");
        strcat(nombre, productos_desktop[i].procesador);
        printf("\033[0;31m");
        printf("%d. ", i+1);
        printf("\033[0m");
        printf("%s", nombre);
        printf(", %dgb ram\n\n", productos_desktop[i].ram);
    }
}

//ELIMINAR PRODUCTOS
void eliminar_mouse(MOUSE productos_mouse[], int *aux){
    int i, j, eliminar;
    printf("Ingrese ");
    printf("\033[0;31m");
    printf("N%c ", 248); 
    printf("\033[0m");
    printf("(segun enumeracion) del mouse para eliminar: ");
    scanf("%d", &eliminar);
    eliminar--;
    
        for(i = 0; i < *aux; i++)
        {
            if(eliminar == i)
            {
                for(j = i; j < *aux - 1; j++)
                {
                    productos_mouse[j] = productos_mouse[j+1]; 
                }
                *aux = *aux -1;
            }
        }
}
void eliminar_keyboard(KEYBOARD productos_keyboard[], int *aux){
    int i, j, eliminar;
    printf("Ingrese ");
    printf("\033[0;31m");
    printf("N%c ", 248); 
    printf("\033[0m");
    printf("(segun enumeracion) del teclado para eliminar: ");
    scanf("%d", &eliminar);
    eliminar--;
    
        for(i = 0; i < *aux; i++)
        {
            if(eliminar == i)
            {
                for(j = i; j < *aux - 1; j++)
                {
                    productos_keyboard[j] = productos_keyboard[j+1]; 
                }
                *aux = *aux -1;
            }
        }
}
void eliminar_monitor(MONITOR productos_monitor[], int *aux){
    int i, j, eliminar;
    printf("Ingrese ");
    printf("\033[0;31m");
    printf("N%c ", 248); 
    printf("\033[0m");
    printf("(segun enumeracion) del monitor para eliminar: ");
    scanf("%d", &eliminar);
    eliminar--;
    
        for(i = 0; i < *aux; i++)
        {
            if(eliminar == i)
            {
                for(j = i; j < *aux - 1; j++)
                {
                    productos_monitor[j] = productos_monitor[j+1]; 
                }
                *aux = *aux -1;
            }
        }
}
void eliminar_notebook(NOTEBOOK productos_notebook[], int *aux){
    int i, j, eliminar;
    printf("Ingrese ");
    printf("\033[0;31m");
    printf("N%c ", 248); 
    printf("\033[0m");
    printf("(segun enumeracion) del notebook para eliminar: ");
    scanf("%d", &eliminar);
    eliminar--;
    
        for(i = 0; i < *aux; i++)
        {
            if(eliminar == i)
            {
                for(j = i; j < *aux - 1; j++)
                {
                    productos_notebook[j] = productos_notebook[j+1]; 
                }
                *aux = *aux -1;
            }
        }
}
void eliminar_desktop(DESKTOP productos_desktop[], int *aux){
    int i, j, eliminar;
    printf("Ingrese ");
    printf("\033[0;31m");
    printf("N%c ", 248); 
    printf("\033[0m");
    printf("(segun enumeracion) del PC para eliminar: ");
    scanf("%d", &eliminar);
    eliminar--;
    
        for(i = 0; i < *aux; i++)
        {
            if(eliminar == i)
            {
                for(j = i; j < *aux - 1; j++)
                {
                    productos_desktop[j] = productos_desktop[j+1]; 
                }
                *aux = *aux -1;
            }
        }
}

//ACTUALIZAR PRODUCTOS 
MOUSE actualizar_mouse(MOUSE productos_mouse[])
{
    int i;
    char marca[30];
    int actualizar;
    printf("Ingrese N%c del mouse que deseas editar?\n>>", 248);
    scanf("%d", &actualizar);
    actualizar--;
    productos_mouse[actualizar].id = 0;
    memset(productos_mouse[actualizar].marca, 0, 30);
    memset(productos_mouse[actualizar].modelo, 0, 30);
    printf("Modificar ID: ");
    scanf("%d", &productos_mouse[actualizar].id);
    printf("Modificar marca : ");
    fflush(stdin);
    gets(marca);
    for(i = 0; marca[i] != '\0'; i++){
            marca[i] = toupper(marca[i]);
        }
    strcpy(productos_mouse[actualizar].marca, marca);
    printf("Modificar modelo: ");
    fflush(stdin);
    gets(productos_mouse[actualizar].modelo);

    return productos_mouse[actualizar];
}
KEYBOARD actualizar_keyboard(KEYBOARD productos_keyboard[])
{
    int i;
    char marca[30];
    int actualizar;
    printf("Que teclado deseas actualizar / editar?\n");
    scanf("%d", &actualizar);
    actualizar--;
    productos_keyboard[actualizar].id = 0;
    memset(productos_keyboard[actualizar].marca, 0, 30);
    memset(productos_keyboard[actualizar].modelo, 0, 30);
    memset(productos_keyboard[actualizar].idioma, 0, 30);
    printf("Modificar ID: ");
    scanf("%d", &productos_keyboard[actualizar].id);
    printf("Modificar marca : ");
    fflush(stdin);
    gets(marca);
    for(i = 0; marca[i] != '\0'; i++){
            marca[i] = toupper(marca[i]);
        }
    strcpy(productos_keyboard[actualizar].marca, marca);
    printf("Modificar modelo: ");
    fflush(stdin);
    gets(productos_keyboard[actualizar].modelo);
    printf("Modificar idioma: ");
    fflush(stdin);
    gets(productos_keyboard[actualizar].idioma);

    return productos_keyboard[actualizar];
}
MONITOR actualizar_monitor(MONITOR productos_monitor[])
{
    int i;
    char marca[30];
    int actualizar;
    printf("Que monitor deseas actualizar / editar?\n");
    scanf("%d", &actualizar);
    actualizar--;
    productos_monitor[actualizar].id = 0;
    productos_monitor[actualizar].tamano = 0;
    memset(productos_monitor[actualizar].marca, 0, 30);
    memset(productos_monitor[actualizar].modelo, 0, 30);
    printf("Modificar ID: ");
    scanf("%d", &productos_monitor[actualizar].id);
    printf("Modificar marca : ");
    fflush(stdin);
    gets(marca);
    for(i = 0; marca[i] != '\0'; i++){
            marca[i] = toupper(marca[i]);
        }
    strcpy(productos_monitor[actualizar].marca, marca);
    printf("Modificar modelo: ");
    fflush(stdin);
    gets(productos_monitor[actualizar].modelo);
    printf("Modificar tamano de pantalla: ");
    scanf("%f", &productos_monitor[actualizar].tamano);

    return productos_monitor[actualizar];
}
NOTEBOOK actualizar_notebook(NOTEBOOK productos_notebook[])
{
    int i;
    char marca[30];
    int actualizar;
    printf("Que notebook deseas actualizar / editar?\n");
    scanf("%d", &actualizar);
    actualizar--;
    productos_notebook[actualizar].id = 0;
    productos_notebook[actualizar].ram = 0;
    productos_notebook[actualizar].tamanoPantalla = 0;
    memset(productos_notebook[actualizar].marca, 0, 30);
    memset(productos_notebook[actualizar].modelo, 0, 30);
    memset(productos_notebook[actualizar].procesador, 0, 30);
    printf("Modificar ID: ");
    scanf("%d", &productos_notebook[actualizar].id);
    printf("Modificar marca : ");
    fflush(stdin);
    gets(marca);
    for(i = 0; marca[i] != '\0'; i++){
            marca[i] = toupper(marca[i]);
        }
    strcpy(productos_notebook[actualizar].marca, marca);
    printf("Modificar modelo: ");
    fflush(stdin);
    gets(productos_notebook[actualizar].modelo);
    printf("Modificar procesador: ");
    fflush(stdin);
    gets(productos_notebook[actualizar].procesador);
    printf("Modificar ram: ");
    scanf("%d", &productos_notebook[actualizar].ram);
    printf("Modificar tamano de pantalla: ");
    scanf("%f", &productos_notebook[actualizar].tamanoPantalla);

    return productos_notebook[actualizar];
}
DESKTOP actualizar_desktop(DESKTOP productos_desktop[])
{int i;
    char marca[30];
    int actualizar;
    printf("Que PC de escritorio deseas actualizar / editar?\n");
    scanf("%d", &actualizar);
    actualizar--;
    productos_desktop[actualizar].id = 0;
    productos_desktop[actualizar].ram = 0;
    memset(productos_desktop[actualizar].marca, 0, 30);
    memset(productos_desktop[actualizar].modelo, 0, 30);
    memset(productos_desktop[actualizar].procesador, 0, 30);
    memset(productos_desktop[actualizar].mouse.modelo, 0, 30);
    memset(productos_desktop[actualizar].teclado.modelo, 0, 30);
    memset(productos_desktop[actualizar].monitor.modelo, 0, 30);
    printf("Modificar ID: ");
    scanf("%d", &productos_desktop[actualizar].id);
    printf("Modificar marca : ");
    fflush(stdin);
    gets(marca);
    for(i = 0; marca[i] != '\0'; i++){
            marca[i] = toupper(marca[i]);
        }
    strcpy(productos_desktop[actualizar].marca, marca);
    printf("Modificar modelo: ");
    fflush(stdin);
    gets(productos_desktop[actualizar].modelo);
    printf("Modificar procesador: ");
    fflush(stdin);
    gets(productos_desktop[actualizar].procesador);
    printf("Modificar ram: ");
    scanf("%d", &productos_desktop[actualizar].ram);
    printf("Modificar mouse: ");
    fflush(stdin);
    gets(productos_desktop[actualizar].mouse.modelo);
    printf("Modificar teclado: ");
    fflush(stdin);
    gets(productos_desktop[actualizar].teclado.modelo);
    printf("Modificar monitor: ");
    fflush(stdin);
    gets(productos_desktop[actualizar].monitor.modelo);

    return productos_desktop[actualizar];
}

//BUSQUEDA POR MARCA (RECURSIVA)
int busquedaMarcaMouse(MOUSE productos_mouse[], int aux, char marca[], int bandera)
{
    if(aux == -1){
        if (bandera == 1){
            return 1;
        }else{
            return 0;
        }
    }
    else{
        if(strcmp(productos_mouse[aux].marca, marca) == 0){
            mostrar_mouse(productos_mouse, aux);
            bandera = 1;
            return busquedaMarcaMouse(productos_mouse, aux-1, marca, bandera);
            
        }
        else{
            return busquedaMarcaMouse(productos_mouse, aux-1, marca, bandera);
        }
    } 
}
int busquedaMarcaTeclado(KEYBOARD productos_teclado[], int aux, char marca[], int bandera)
{
    if(aux == -1){
        if (bandera == 1){
            return 1;
        }else{
            return 0;
        }
    }
    else{
        if(strcmp(productos_teclado[aux].marca, marca) == 0){
            mostrar_teclado(productos_teclado, aux);
            bandera = 1;
            return busquedaMarcaTeclado(productos_teclado, aux-1, marca, bandera);  
        }
        else{
            return busquedaMarcaTeclado(productos_teclado, aux-1, marca, bandera);
        }
    } 
}
int busquedaMarcaMonitor(MONITOR productos_monitor[], int aux, char marca[], int bandera)
{
    if(aux == -1){
        if (bandera == 1){
            return 1;
        }else{
            return 0;
        }
    }
    else{
        if(strcmp(productos_monitor[aux].marca, marca) == 0){
            mostrar_monitor(productos_monitor, aux);
            bandera = 1;
            return busquedaMarcaMonitor(productos_monitor, aux-1, marca, bandera);  
        }
        else{
            return busquedaMarcaMonitor(productos_monitor, aux-1, marca, bandera);
        }
    } 
}
int busquedaMarcaNotebook(NOTEBOOK productos_notebook[], int aux, char marca[], int bandera)
{
    if(aux == -1){
        if (bandera == 1){
            return 1;
        }else{
            return 0;
        }
    }
    else{
        if(strcmp(productos_notebook[aux].marca, marca) == 0){
            mostrar_notebook(productos_notebook, aux);
            bandera = 1;
            return busquedaMarcaNotebook(productos_notebook, aux-1, marca, bandera);  
        }
        else{
            return busquedaMarcaNotebook(productos_notebook, aux-1, marca, bandera);
        }
    } 
}
int busquedaMarcaDesktop(DESKTOP productos_desktop[], int aux, char marca[], int bandera)
{
    if(aux == -1){
        if (bandera == 1){
            return 1;
        }else{
            return 0;
        }
    }
    else{
        if(strcmp(productos_desktop[aux].marca, marca) == 0){
            mostrar_desktop(productos_desktop, aux);
            bandera = 1;
            return busquedaMarcaNotebook(productos_desktop, aux-1, marca, bandera);  
        }
        else{
            return busquedaMarcaNotebook(productos_desktop, aux-1, marca, bandera);
        }
    } 
}

//MOSTRAR PRODUCTOS EN UN FORMATO "FORMAL"
void mostrar_mouse(MOUSE productos_mouse[], int aux)
{
    printf("\nID: %d \n", productos_mouse[aux].id);
    printf("Marca: %s \n", productos_mouse[aux].marca);
    printf("Modelo: %s \n", productos_mouse[aux].modelo);
}
void mostrar_teclado(KEYBOARD productos_teclado[], int aux)
{
    printf("\nID: %d \n", productos_teclado[aux].id);
    printf("Marca: %s \n", productos_teclado[aux].marca);
    printf("Modelo: %s \n", productos_teclado[aux].modelo);
    printf("Idioma: %s \n", productos_teclado[aux].idioma);
}
void mostrar_monitor(MONITOR productos_monitor[], int aux)
{
    printf("\nID: %d \n", productos_monitor[aux].id);
    printf("Marca: %s \n", productos_monitor[aux].marca);
    printf("Modelo: %s \n", productos_monitor[aux].modelo);
    printf("Tamano de pantalla: %.1f pulgadas \n", productos_monitor[aux].tamano);
}
void mostrar_notebook(NOTEBOOK productos_notebook[], int aux)
{
    printf("\nID: %d \n", productos_notebook[aux].id);
    printf("Marca: %s \n", productos_notebook[aux].marca);
    printf("Modelo: %s \n", productos_notebook[aux].modelo);
    printf("Procesador: %s \n", productos_notebook[aux].procesador);
    printf("Tamano de pantalla: %.1f pulgadas \n", productos_notebook[aux].tamanoPantalla);
}
void mostrar_desktop(DESKTOP productos_desktop[], int aux)
{
    printf("\nID: %d \n", productos_desktop[aux].id);
    printf("Marca: %s \n", productos_desktop[aux].marca);
    printf("Modelo: %s \n", productos_desktop[aux].modelo);
    printf("Procesador: %s \n", productos_desktop[aux].procesador);
    printf("Ram: %dgb \n", productos_desktop[aux].ram);
    printf("Mouse: %s \n", productos_desktop[aux].mouse.modelo);
    printf("Teclado: %s \n", productos_desktop[aux].teclado.modelo);
    printf("Monitor: %s \n", productos_desktop[aux].monitor.modelo);
}

//PRODUCTOS PRECARGADOS DE CADA TIP (3)
void precarga_mouse(MOUSE productos_mouse[]){
            productos_mouse[0].id = 11897;
    strncpy(productos_mouse[0].marca, "COOLER MASTER", 30);
    strncpy(productos_mouse[0].modelo, "MM711", 30);

            productos_mouse[1].id = 11001;
    strncpy(productos_mouse[1].marca,  "HYPERX",30);
    strncpy(productos_mouse[1].modelo, "Fps Pro",30);

            productos_mouse[2].id = 11034;
    strncpy(productos_mouse[2].marca,"LOGITECH",30);
    strncpy(productos_mouse[2].modelo, "Lightspeed",30);
}
void precarga_teclado(KEYBOARD productos_keyboard[]){
    productos_keyboard[0].id = 11898;
    strncpy(productos_keyboard[0].marca,"HYPERX",30); 
    strncpy(productos_keyboard[0].modelo,"Alloy core RGB",30);
    strncpy(productos_keyboard[0].idioma,"Ingles",30);

            productos_keyboard[1].id = 11937;
    strncpy(productos_keyboard[1].marca,"RAZER",30); 
    strncpy(productos_keyboard[1].modelo,"Blackwidow",30);
    strncpy(productos_keyboard[1].idioma,"Espanol",30);

            productos_keyboard[2].id = 11907;
    strncpy(productos_keyboard[2].marca,"RAZER",30); 
    strncpy(productos_keyboard[2].modelo,"CHROMA",30);
    strncpy(productos_keyboard[2].idioma,"Ingles",30);
}
void precarga_monitor(MONITOR productos_monitor[]){
    productos_monitor[0].id = 39453;
    strncpy(productos_monitor[0].marca,"ASUS",30);
    strncpy(productos_monitor[0].modelo, "TUF GAMING",30);
            productos_monitor[0].tamano =27;

            productos_monitor[1].id = 39453;
    strncpy(productos_monitor[1].marca,"SAMSUNG",30);
    strncpy(productos_monitor[1].modelo, "C24RG50",30);
            productos_monitor[1].tamano =24;

            productos_monitor[2].id = 39106;
    strncpy(productos_monitor[2].marca,"VIEWSONIC",30);
    strncpy(productos_monitor[2].modelo, "VX3218-PC-MHD",30);
            productos_monitor[2].tamano = 32;
}
void precarga_notebook(NOTEBOOK productos_notebook[]){
            productos_notebook[0].id = 45928;
    strncpy(productos_notebook[0].marca,"ACER",30);
    strncpy(productos_notebook[0].modelo,"ASPIRE NITRO 5",30);
    strncpy(productos_notebook[0].procesador,"INTEL CORE I5-10300H",30);
            productos_notebook[0].tamanoPantalla =  15.6;
            productos_notebook[0].ram =  16;

            productos_notebook[1].id = 45475;
    strncpy(productos_notebook[1].marca,"HP",30);
    strncpy(productos_notebook[1].modelo,"VICTUS 16-D0511LA",30);
    strncpy(productos_notebook[1].procesador,"INTEL CORE I5-11400H",30);
            productos_notebook[1].tamanoPantalla =  16.1;
            productos_notebook[1].ram =  8;

            productos_notebook[2].id = 45936;
    strncpy(productos_notebook[2].marca,"ASUS",30);
    strncpy(productos_notebook[2].modelo,"TUF GAMING A15",30);
    strncpy(productos_notebook[2].procesador,"AMD RYZEN 5 4600H",30);
            productos_notebook[2].tamanoPantalla =  15.6;
            productos_notebook[2].ram =  8;
}
void precarga_desktop(DESKTOP productos_desktop[]){
            productos_desktop[0].id = 73193;
    strncpy(productos_desktop[0].marca,"OLIDATA",30);
    strncpy(productos_desktop[0].modelo,"GAMER PC",30);
    strncpy(productos_desktop[0].procesador,"INTEL CORE 2 DUO",30);
            productos_desktop[0].ram =  16;
    strncpy(productos_desktop[0].mouse.modelo, "OLIDATA GENERIC MOUSE", 30);
    strncpy(productos_desktop[0].teclado.modelo, "OLIDATA GENERIC KEYBOARD", 30);
    strncpy(productos_desktop[0].monitor.modelo, "SAMSUNG SCREEN", 30);

            productos_desktop[1].id = 14321;
    strncpy(productos_desktop[1].marca,"GEAR",30);
    strncpy(productos_desktop[1].modelo,"WORKSPACE PC",30);
    strncpy(productos_desktop[1].procesador,"RYZEN 5 1600X",30);
            productos_desktop[1].ram =  8;
    strncpy(productos_desktop[1].mouse.modelo, "HP MOUSE WORKSPACE", 30);
    strncpy(productos_desktop[1].teclado.modelo, "HP TECLADO WORK", 30);
    strncpy(productos_desktop[1].monitor.modelo, "GEAR GAMER SCREEN", 30);

            productos_desktop[2].id = 14321;
    strncpy(productos_desktop[2].marca,"APPLE",30);
    strncpy(productos_desktop[2].modelo,"IMAC",30);
    strncpy(productos_desktop[2].procesador,"CHIP M1",30);
            productos_desktop[2].ram =  32;
    strncpy(productos_desktop[2].mouse.modelo, "APPLE MAGIC MOUSE", 30);
    strncpy(productos_desktop[2].teclado.modelo, "APPLE MAGIC KEYBOARD", 30);
    strncpy(productos_desktop[2].monitor.modelo, "APPLE STUDIO DISPLAY HDR", 30);
}

//TEXTOS A ASCII
void logo_akme()
{ 
printf("\033[0;32m");
printf(" \   
\t\t\t\t   ###    ##    ## ##     ## ######## \n \
\t\t\t\t  ## ##   ##   ##  ###   ### ##       \n \
\t\t\t\t ##   ##  ##  ##   #### #### ##       \n \
\t\t\t\t##     ## #####    ## ### ## ######   \n \
\t\t\t\t######### ##  ##   ##     ## ##       \n \
\t\t\t\t##     ## ##   ##  ##     ## ##       \n \
\t\t\t\t##     ## ##    ## ##     ## ######## \n");

printf("\033[0m");
printf("\n\n");
}
void bienvenido(){
    printf("\033[0;32m");
    printf(" \
\t\t########  #### ######## ##    ## ##     ## ######## ##    ## #### ########   ####### \n \ 
\t\t##     ##  ##  ##       ###   ## ##     ## ##       ###   ##  ##  ##     ## ##     ##\n \ 
\t\t##     ##  ##  ##       ####  ## ##     ## ##       ####  ##  ##  ##     ## ##     ##\n \ 
\t\t########   ##  ######   ## ## ## ##     ## ######   ## ## ##  ##  ##     ## ##     ##\n \ 
\t\t##     ##  ##  ##       ##  ####  ##   ##  ##       ##  ####  ##  ##     ## ##     ##\n \ 
\t\t##     ##  ##  ##       ##   ###   ## ##   ##       ##   ###  ##  ##     ## ##     ##\n \ 
\t\t########  #### ######## ##    ##    ###    ######## ##    ## #### ########   ####### \n");
    printf("\033[0m");
    printf("\n\n");
}
