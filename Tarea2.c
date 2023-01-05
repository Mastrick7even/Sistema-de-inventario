// Diego Vargas Gomez
// Bastian Arriagada Quero
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
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
int inicio_sesion(USER a);
void nombreVisible(USER a);

//agregar productos
MOUSE agregar_mouse(MOUSE productos_mouse[], int aux);
void mostrar_mouse(MOUSE productos_mouse[], int aux);

KEYBOARD agregar_teclado(KEYBOARD productos_teclado[], int aux);
void mostrar_teclado(KEYBOARD productos_teclado[], int aux);

MONITOR agregar_monitor(MONITOR productos_monitor[], int aux);
void mostrar_monitor(MONITOR productos_monitor[], int aux);

NOTEBOOK agregar_notebook(NOTEBOOK productos_notebook[], int aux);
void mostrar_notebook(NOTEBOOK productos_notebook[], int aux);

DESKTOP agregar_desktop(DESKTOP productos_desktop[], int aux);

//menu para elegir tipo de producto
void elegirProducto();

//mostrar productos concatenados
void concatenar_mouse(MOUSE productos_mouse[], int aux);
void concatenar_keyboard(KEYBOARD productos_keyboard[], int aux);
void concatenar_monitor(MONITOR productos_monitor[], int aux);
void concatenar_notebook(NOTEBOOK productos_notebook[], int aux);
void concatenar_desktop(DESKTOP productos_desktop[], int aux);

//eliminar productos
void eliminar_mouse(MOUSE productos_mouse[], int *aux);
void eliminar_keyboard(KEYBOARD productos_keyboard[], int *aux);
void eliminar_monitor(MONITOR productos_monitor[], int *aux);
void eliminar_notebook(NOTEBOOK productos_notebook[], int *aux);
void eliminar_desktop(DESKTOP productos_desktop[], int *aux);

//listar productos
void listar_mouse(MOUSE productos_mouse[], int aux);
void listar_teclado(KEYBOARD productos_keyboard[], int aux);
void listar_monitor(MONITOR productos_monitor[], int aux);
void listar_notebook(NOTEBOOK productos_notebook[], int aux);
void listar_desktop(DESKTOP productos_desktop[], int aux);

//actualizar productos
void actualizar_mouse(MOUSE productos_mouse[]);
void actualizar_keyboard(KEYBOARD productos_keyboard[]);
void actualizar_monitor(MONITOR productos_monitor[]);
void actualizar_notebook(NOTEBOOK productos_notebook[]);
void actualizar_desktop(DESKTOP productos_desktop[]);

//PRECARGA DE PRODUCTOS
int main()
{
    // USER
    USER usuario1 = {991, "admin", "admin123", "Kylian", "Mbappe", "Lottin"};

    //MOUSE
    int auxMouse = 3;
    MOUSE productos_mouse[1000];
            productos_mouse[0].id = 11897;
    strncpy(productos_mouse[0].marca, "LOGITECH", 30);
    strncpy(productos_mouse[0].modelo, "G502 HERO", 30);

            productos_mouse[1].id = 11001;
    strncpy(productos_mouse[1].marca,  "HYPERX",30);
    strncpy(productos_mouse[1].modelo, "FPS PRO",30);

            productos_mouse[2].id = 11034;
    strncpy(productos_mouse[2].marca,"LOGITECH",30);
    strncpy(productos_mouse[2].modelo, "LIGHTSPEED",30);

    // KEYBOARD
    int auxKeyboard = 3;
    KEYBOARD productos_keyboard[1000];
            productos_keyboard[0].id = 11898;
    strncpy(productos_keyboard[0].marca,"HYPERX",30); 
    strncpy(productos_keyboard[0].modelo,"ALLOY CORE RGB",30);
    strncpy(productos_keyboard[0].idioma,"INGLES",30);

            productos_keyboard[1].id = 11937;
    strncpy(productos_keyboard[1].marca,"RAZER",30); 
    strncpy(productos_keyboard[1].modelo,"BLACKWIDOW",30);
    strncpy(productos_keyboard[1].idioma,"INGLES",30);

            productos_keyboard[2].id = 11907;
    strncpy(productos_keyboard[2].marca,"RAZER",30); 
    strncpy(productos_keyboard[2].modelo,"CHROMA",30);
    strncpy(productos_keyboard[2].idioma,"INGLES",30);

    // MONITOR
    int auxMonitor = 3;
    MONITOR productos_monitor[1000];
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

    // NOTEBOOK
    int auxNotebook = 3;
    NOTEBOOK productos_notebook[1000];
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

            int auxDesktop = 3;
    DESKTOP productos_desktop[1000];
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
            

    // INICIO DE SESION
    int inicia = 0;
    int menu, opcion, agregar, eliminar, actualizar;
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
            case 1://AGREGAR UN PRODUCTO
                do{
                    system("cls");
                    printf("Que tipo de producto deseas agregar?\n");
                    elegirProducto();
                    scanf("%d", &agregar);

                    switch (agregar)
                    {
                        case 1:
                            auxMouse++;
                            agregar_mouse(productos_mouse, auxMouse);
                            system("pause");
                            break;
                        case 2:
                            auxKeyboard++;
                            agregar_teclado(productos_keyboard, auxKeyboard);
                            system("pause");
                            break;
                        case 3:
                            auxMonitor++;
                            agregar_monitor(productos_monitor, auxMonitor);
                            system("pause");
                            break;
                        case 4:
                            auxNotebook++;
                            agregar_notebook(productos_notebook, auxNotebook);
                            system("pause");
                            break;
                        case 5:
                            auxDesktop++;
                            agregar_desktop(productos_desktop, auxDesktop);
                            system("pause");
                            break;
                        case 6:
                            break;
                        default:
                            system("cls");
                            printf("Opcion no valida, ingrese nuevamente");
                            getch();
                            break;
                    }
                }while(agregar !=6);
                break;

            case 2:// ACTUALIZAR UN PRODUCTO
            do{
                    system("cls");
                    printf("Que tipo de producto deseas actualizar?\n");
                    elegirProducto();
                    scanf("%d", &actualizar);

                    switch (actualizar)
                    {
                        case 1:
                            concatenar_mouse(productos_mouse, auxMouse);
                            actualizar_mouse(productos_mouse);
                            break;
                        case 2:
                            concatenar_keyboard(productos_keyboard, auxKeyboard);
                            actualizar_keyboard(productos_keyboard);
                            system("pause");
                            break;
                        case 3:
                            concatenar_monitor(productos_monitor, auxMonitor);
                            actualizar_monitor(productos_monitor);
                            system("pause");
                            break;
                        case 4:
                            concatenar_notebook(productos_notebook, auxNotebook);
                            actualizar_notebook(productos_notebook);
                            system("pause");
                            break;
                        case 5:
                            concatenar_desktop(productos_desktop, auxDesktop);
                            actualizar_desktop(productos_desktop);
                            system("pause");
                            break;
                        case 6:
                            break;
                        default:
                            system("cls");
                            printf("Opcion no valida, ingrese nuevamente");
                            getch();
                            break;
                    }
                }while(actualizar !=6);
                break;

            case 3:// LISTAR LOS PRODUCTOS
                system("cls");
                printf("MOUSE:\n");
                listar_mouse(productos_mouse, auxMouse);
                
                printf("-------------------------------------\n");
                printf("TECLADOS.\n");
                listar_teclado(productos_keyboard, auxKeyboard);
                
                printf("-------------------------------------\n");
                printf("MONITORES.\n");
                listar_monitor(productos_monitor, auxMonitor);
                
                printf("-------------------------------------\n");
                printf("NOTEBOOKS.\n");
                listar_notebook(productos_notebook, auxNotebook);

                printf("-------------------------------------\n");
                printf("PCs de escritorio.\n");
                listar_desktop(productos_desktop, auxDesktop);
                system("pause");
                break;

            case 4://BUSQUEDA POR MARCA (RECURSIVIDAD)

            case 5://ELIMINAR PRODUCTOS
                do{
                    system("cls");
                    printf("Que tipo de producto deseas eliminar?\n");
                    elegirProducto();
                    scanf("%d", &eliminar);

                    switch (eliminar)
                    {
                        case 1:
                            system("cls");
                            concatenar_mouse(productos_mouse, auxMouse);
                            eliminar_mouse(productos_mouse, &auxMouse);
                            break;

                        case 2:
                            system("cls");
                            concatenar_keyboard(productos_keyboard, auxKeyboard);
                            eliminar_keyboard(productos_keyboard, &auxKeyboard);
                            break;

                        case 3:
                            system("cls");
                            concatenar_monitor(productos_monitor, auxMonitor);
                            eliminar_monitor(productos_monitor, &auxMonitor);
                            break;
                        case 4:
                            system("cls");
                            concatenar_notebook(productos_notebook, auxNotebook);
                            eliminar_notebook(productos_notebook, &auxNotebook);
                            break;

                        case 5:
                            system("cls");
                            concatenar_desktop(productos_desktop, auxDesktop);
                            eliminar_desktop(productos_desktop, &auxDesktop);
                            break;

                        default:
                            system("cls");
                            printf("Opcion no valida, ingrese nuevamente");
                            getch();
                            break;
                    }
                }while(eliminar !=5);
                break;

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
        }while (opcion != 6);
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

//OPCIONES PARA ELEGIR EL PRODUCTO
void elegirProducto()
{
    printf("\n1. Mouse");
    printf("\n2. Teclado");
    printf("\n3. Monitor");
    printf("\n4. Notebook");
    printf("\n5. PC de escritorio");
    printf("\n6. Volver atras\n");
    printf(">> ");
}

//FUNCION PARA AGREGAR PRODUCTOS
MOUSE agregar_mouse(MOUSE productos_mouse[], int aux)
{
    printf("\nAGREGAR MOUSE N*%d: \n\n", aux);
    printf("Ingrese ID: ");
    fflush(stdin);
    scanf("%d", &productos_mouse[aux-1].id);
    printf("Ingrese marca: ");
    fflush(stdin);
    gets(productos_mouse[aux-1].marca);
    printf("Ingrese modelo: ");
    fflush(stdin);
    gets(productos_mouse[aux-1].modelo);

    return productos_mouse[aux-1];
}
void mostrar_mouse(MOUSE productos_mouse[], int aux)
{
    printf("\nEl id del mouse es: %d \n", productos_mouse[aux-1].id);
    printf("La marca del mouse es: %s \n", productos_mouse[aux-1].marca);
    printf("El modelo del mouse es: %s \n", productos_mouse[aux-1].modelo);
}

KEYBOARD agregar_teclado(KEYBOARD productos_teclado[], int aux)
{
    printf("\nAGREGAR TECLADO N*%d: \n\n", aux);
    printf("Ingrese ID: ");
    fflush(stdin);
    scanf("%d", &productos_teclado[aux-1].id);
    printf("Ingrese marca: ");
    fflush(stdin);
    gets(productos_teclado[aux-1].marca);
    printf("Ingrese modelo: ");
    fflush(stdin);
    gets(productos_teclado[aux-1].modelo);
    printf("Ingrese idioma: ");
    fflush(stdin);
    gets(productos_teclado[aux-1].idioma);

    return productos_teclado[aux-1];
}
void mostrar_teclado(KEYBOARD productos_teclado[], int aux)
{
    printf("\nEl id del teclado es: %d \n", productos_teclado[aux-1].id);
    printf("La marca del teclado es: %s \n", productos_teclado[aux-1].marca);
    printf("El modelo del teclado es: %s \n", productos_teclado[aux-1].modelo);
    printf("El idioma del teclado es: %s \n", productos_teclado[aux-1].idioma);
}

MONITOR agregar_monitor(MONITOR productos_monitor[], int aux)
{
    printf("\nAGREGAR MONITOR N*%d: \n\n", aux);
    printf("Ingrese ID: ");
    fflush(stdin);
    scanf("%d", &productos_monitor[aux-1].id);
    printf("Ingrese marca: ");
    fflush(stdin);
    gets(productos_monitor[aux-1].marca);
    printf("Ingrese modelo: ");
    fflush(stdin);
    gets(productos_monitor[aux-1].modelo);
    printf("Ingrese tamano: ");
    fflush(stdin);
    scanf("%f", &productos_monitor[aux-1].tamano);

    return productos_monitor[aux-1];
}
void mostrar_monitor(MONITOR productos_monitor[], int aux)
{
    printf("\nEl id del monitor es: %d \n", productos_monitor[aux-1].id);
    printf("La marca del monitor es: %s \n", productos_monitor[aux-1].marca);
    printf("El modelo del monitor es: %s \n", productos_monitor[aux-1].modelo);
    printf("El tamano del monitor es: %.1f \n", productos_monitor[aux-1].tamano);
}

NOTEBOOK agregar_notebook(NOTEBOOK productos_notebook[], int aux)
{
    printf("\nAGREGAR NOTEBOOK N*%d: \n\n", aux);
    printf("Ingrese ID: ");
    fflush(stdin);
    scanf("%d", &productos_notebook[aux-1].id);
    printf("Ingrese marca: ");
    fflush(stdin);
    gets(productos_notebook[aux-1].marca);
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
void mostrar_notebook(NOTEBOOK productos_notebook[], int aux)
{
    printf("\nEl id del notebook es: %d \n", productos_notebook[aux-1].id);
    printf("La marca del notebook es: %s \n", productos_notebook[aux-1].marca);
    printf("El modelo del notebook es: %s \n", productos_notebook[aux-1].modelo);
    printf("El procesador del notebook es: %s \n", productos_notebook[aux-1].procesador);
    printf("El tamano de pantalla del notebook es: %.1f \n", productos_notebook[aux-1].tamanoPantalla);
}

DESKTOP agregar_desktop(DESKTOP productos_desktop[], int aux){
    printf("\nAGREGAR DESKTOP N*%d: \n\n", aux);
    printf("Ingrese ID: ");
    scanf("%d", &productos_desktop[aux-1].id);
    printf("Ingrese marca: ");
    fflush(stdin);
    gets(productos_desktop[aux-1].marca);
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
    printf("Stock disponible: %d \n\n", aux);
    for(i = 0; i < aux; i++){
        printf("ID: %d \n", productos_mouse[i].id);
        printf("Marca: %s \n", productos_mouse[i].marca);
        printf("Modelo: %s \n\n", productos_mouse[i].modelo);
    }  
    
}
void listar_teclado(KEYBOARD productos_keyboard[], int aux)
{
    int i;
    printf("Stock disponible: %d \n\n", aux);
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
    printf("Stock disponible: %d \n\n", aux);
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
    printf("Stock disponible: %d \n\n", aux);
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
    printf("Stock disponible: %d \n\n", aux);
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

//Funcion para mostrar productos con modelo concatenado
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
        printf("%d. %s", i+1, nombre);
        printf(" (ID: %d)\n\n", productos_mouse[i].id);
        
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
        printf("%d. %s", i+1, nombre);
        printf(" (ID: %d)\n\n", productos_keyboard[i].id);
        
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
        printf("%d. %s", i+1, nombre);
        printf(", %.1f pulgadas", productos_monitor[i].tamano);
        printf(" (ID: %d)\n\n", productos_monitor[i].id);
        
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
        printf("%d. %s", i+1, nombre);
        printf(", %dgb ram", productos_notebook[i].ram);
        printf(", %.1f pulgadas de pantalla", productos_notebook[i].tamanoPantalla);
        printf(" (ID: %d)\n\n", productos_notebook[i].id);
        
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
        printf("%d. %s", i+1, nombre);
        printf(", %dgb ram", productos_desktop[i].ram);
        printf(" (ID: %d)\n\n", productos_desktop[i].id);
        
    }
}

//FUNCION PARA ELIMINAR PRODUCTOS
void eliminar_mouse(MOUSE productos_mouse[], int *aux){
    int i, j, eliminar;
    printf("Ingrese N* de producto para eliminar:\n\n");
    printf("Eliminar mouse N*: ");
    fflush(stdin);
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
    printf("Ingrese N* de producto para eliminar:\n\n");
    printf("Eliminar teclado N*: ");
    fflush(stdin);
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
    printf("Ingrese N* de producto para eliminar:\n\n");
    printf("Eliminar monitor N*: ");
    fflush(stdin);
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
    printf("Ingrese N* de producto para eliminar:\n\n");
    printf("Eliminar producto N*: ");
    fflush(stdin);
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
    printf("Ingrese N* de producto para eliminar:\n\n");
    printf("Eliminar producto N*: ");
    fflush(stdin);
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

//FUNCION PARA ACTUALIZAR PRODUCTOS 
void actualizar_mouse(MOUSE productos_mouse[]){
    int actualizar;
    printf("Que mouse deseas actualizar / editar?\n");
    scanf("%d", &actualizar);
    actualizar--;
    productos_mouse[actualizar].id = 0;
    memset(productos_mouse[actualizar].marca, 0, 30);
    memset(productos_mouse[actualizar].modelo, 0, 30);
    printf("Modificar ID: ");
    scanf("%d", &productos_mouse[actualizar].id);
    printf("Modificar marca : ");
    fflush(stdin);
    gets(productos_mouse[actualizar].marca);
    printf("Modificar modelo: ");
    fflush(stdin);
    gets(productos_mouse[actualizar].modelo);

    return productos_mouse[actualizar];
}
void actualizar_keyboard(KEYBOARD productos_keyboard[]){
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
    gets(productos_keyboard[actualizar].marca);
    printf("Modificar modelo: ");
    fflush(stdin);
    gets(productos_keyboard[actualizar].modelo);
    printf("Modificar idioma: ");
    fflush(stdin);
    gets(productos_keyboard[actualizar].idioma);

    return productos_keyboard[actualizar];
}
void actualizar_monitor(MONITOR productos_monitor[]){
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
    gets(productos_monitor[actualizar].marca);
    printf("Modificar modelo: ");
    fflush(stdin);
    gets(productos_monitor[actualizar].modelo);
    printf("Modificar tamano de pantalla: ");
    scanf("%f", &productos_monitor[actualizar].tamano);

    return productos_monitor[actualizar];
}
void actualizar_notebook(NOTEBOOK productos_notebook[]){
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
    gets(productos_notebook[actualizar].marca);
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
void actualizar_desktop(DESKTOP productos_desktop[]){
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
    gets(productos_desktop[actualizar].marca);
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
