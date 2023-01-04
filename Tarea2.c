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

//agregar productos
MOUSE agregar_mouse(MOUSE productos_mouse[], int aux);
void mostrar_mouse(MOUSE productos_mouse[], int aux);

KEYBOARD agregar_teclado(KEYBOARD productos_teclado[], int aux);
void mostrar_teclado(KEYBOARD productos_teclado[], int aux);

MONITOR agregar_monitor(MONITOR productos_monitor[], int aux);
void mostrar_monitor(MONITOR productos_monitor[], int aux);

NOTEBOOK agregar_notebook(NOTEBOOK productos_notebook[], int aux);
void mostrar_notebook(NOTEBOOK productos_notebook[], int aux);

//menu para elegir tipo de producto
void elegirProducto();

//mostrar productos concatenados
void concatenar_mouse(MOUSE productos_mouse[], int aux);
void concatenar_keyboard(KEYBOARD productos_keyboard[], int aux);
void concatenar_monitor(MONITOR productos_monitor[], int aux);
void concatenar_notebook(NOTEBOOK productos_notebook[], int aux);

//eliminar productos
void eliminar_mouse(MOUSE productos_mouse[], int *aux);
void eliminar_keyboard(KEYBOARD productos_keyboard[], int *aux);
void eliminar_monitor(MONITOR productos_monitor[], int *aux);
void eliminar_notebook(NOTEBOOK productos_notebook[], int *aux);

//listar productos
void listar_mouse(MOUSE productos_mouse[], int i);
void listar_teclado(KEYBOARD productos_keyboard[], int i);
void listar_monitor(MONITOR productos_monitor[], int i);
void listar_notebook(NOTEBOOK productos_notebook[], int i);

//PRECARGA DE PRODUCTOS
int main()
{
    // USER
    USER usuario1 = {991, "admin", "admin123", "Kylian", "Mbappe", "Lottin"};

    //MOUSE
    int auxMouse = 3;
    MOUSE productos_mouse[1000];
            productos_mouse[0].id = 11897;
    strncpy(productos_mouse[0].marca, "LOGITECH", 20);
    strncpy(productos_mouse[0].modelo, "G502 HERO", 20);

            productos_mouse[1].id = 11001;
    strncpy(productos_mouse[1].marca,  "HYPERX",20);
    strncpy(productos_mouse[1].modelo, "FPS PRO",20);

            productos_mouse[2].id = 11034;
    strncpy(productos_mouse[2].marca,"LOGITECH",20);
    strncpy(productos_mouse[2].modelo, "LIGHTSPEED",20);

    // KEYBOARD
    int auxKeyboard = 3;
    KEYBOARD productos_keyboard[1000];
            productos_keyboard[0].id = 11898;
    strncpy(productos_keyboard[0].marca,"HYPERX",20); 
    strncpy(productos_keyboard[0].modelo,"ALLOY CORE RGB",20);
    strncpy(productos_keyboard[0].idioma,"INGLES",20);

            productos_keyboard[1].id = 11937;
    strncpy(productos_keyboard[1].marca,"RAZER",20); 
    strncpy(productos_keyboard[1].modelo,"BLACKWIDOW",20);
    strncpy(productos_keyboard[1].idioma,"INGLES",20);

            productos_keyboard[2].id = 11907;
    strncpy(productos_keyboard[2].marca,"RAZER",20); 
    strncpy(productos_keyboard[2].modelo,"CHROMA",20);
    strncpy(productos_keyboard[2].idioma,"INGLES",20);

    // MONITOR
    int auxMonitor = 3;
    MONITOR productos_monitor[1000];
            productos_monitor[0].id = 39453;
    strncpy(productos_monitor[0].marca,"ASUS",20);
    strncpy(productos_monitor[0].modelo, "TUF GAMING",20);
            productos_monitor[0].tamano =27;

            productos_monitor[1].id = 39453;
    strncpy(productos_monitor[1].marca,"SAMSUNG",20);
    strncpy(productos_monitor[1].modelo, "C24RG50",20);
            productos_monitor[1].tamano =24;

            productos_monitor[2].id = 39106;
    strncpy(productos_monitor[2].marca,"VIEWSONIC",20);
    strncpy(productos_monitor[2].modelo, "VX3218-PC-MHD",20);
            productos_monitor[2].tamano = 32;

    // NOTEBOOK
    int auxNotebook = 3;
    NOTEBOOK productos_notebook[1000];
            productos_notebook[0].id = 45928;
    strncpy(productos_notebook[0].marca,"ACER",20);
    strncpy(productos_notebook[0].modelo,"ASPIRE NITRO 5",20);
    strncpy(productos_notebook[0].procesador,"INTEL CORE I5-10300H",30);
            productos_notebook[0].tamanoPantalla =  15.6;
            productos_notebook[0].ram =  16;

            productos_notebook[1].id = 45475;
    strncpy(productos_notebook[1].marca,"HP",20);
    strncpy(productos_notebook[1].modelo,"VICTUS 16-D0511LA",20);
    strncpy(productos_notebook[1].procesador,"INTEL CORE I5-11400H",30);
            productos_notebook[1].tamanoPantalla =  16.1;
            productos_notebook[1].ram =  8;

            productos_notebook[2].id = 45936;
    strncpy(productos_notebook[2].marca,"ASUS",20);
    strncpy(productos_notebook[2].modelo,"TUF GAMING A15",20);
    strncpy(productos_notebook[2].procesador,"AMD RYZEN 5 4600H",30);
            productos_notebook[2].tamanoPantalla =  15.6;
            productos_notebook[2].ram =  8;

    // INICIO DE SESION
    int inicia = 0;
    int menu, opcion, agregar, eliminar,opEliminar, i;
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
                            break;
                        default:
                            system("cls");
                            printf("Opcion no valida, ingrese nuevamente");
                            getch();
                            break;
                    }
                }while(agregar !=5);
                break;

            case 2:// ACTUALIZAR UN PRODUCTO

            case 3:// LISTAR LOS PRODUCTOS
                system("cls");
                printf("MOUSE:\n\n");
                for (i = 0; i < auxMouse; i++)
                {
                    listar_mouse(productos_mouse, i);
                }
                printf("-------------------------------------\n");
                printf("TECLADOS:\n\n");
                for (i = 0; i < auxKeyboard; i++)
                {
                    listar_teclado(productos_keyboard, i);
                }
                printf("-------------------------------------\n");
                printf("MONITORES:\n\n");
                for (i = 0; i < auxMonitor; i++)
                {
                    listar_monitor(productos_monitor, i);
                }
                printf("-------------------------------------\n");
                printf("NOTEBOOKS:\n\n");
                for (i = 0; i < auxNotebook; i++)
                {
                    listar_notebook(productos_notebook, i);
                }
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

                            concatenar_mouse(productos_mouse, auxMouse);
                            eliminar_mouse(productos_mouse, &auxMouse);
                            break;

                        case 2:
                            concatenar_keyboard(productos_keyboard, auxKeyboard);
                            eliminar_keyboard(productos_keyboard, &auxKeyboard);
                            break;

                        case 3:
                            concatenar_monitor(productos_monitor, auxMonitor);
                            eliminar_monitor(productos_monitor, &auxMonitor);
                            break;
                        case 4:
                            concatenar_notebook(productos_notebook, auxNotebook);
                            eliminar_notebook(productos_notebook, &auxNotebook);
                            break;

                        case 5:
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
    printf("\n5. Volver atras\n");
    printf(">> ");
}

//FUNCION PARA AGREGAR PRODUCTOS
//Mouse
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
//Teclado
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
//Monitor
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
//Notebook
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


//FUNCION PARA LISTAR PRODUCTOS
//Mouse
void listar_mouse(MOUSE productos_mouse[], int i)
{
    printf("Mouse N*%d \n", i+1);
    printf("ID: %d \n", productos_mouse[i].id);
    printf("Marca: %s \n", productos_mouse[i].marca);
    printf("Modelo: %s \n\n", productos_mouse[i].modelo);
}
//Teclado
void listar_teclado(KEYBOARD productos_keyboard[], int i)
{
    printf("Teclado N*%d \n", i+1);
    printf("ID: %d \n", productos_keyboard[i].id);
    printf("Marca: %s \n", productos_keyboard[i].marca);
    printf("Modelo: %s \n", productos_keyboard[i].modelo);
    printf("Idioma: %s \n\n", productos_keyboard[i].idioma);
}
//Monitor
void listar_monitor(MONITOR productos_monitor[], int i)
{
    printf("Monitor N*%d \n", i+1);
    printf("ID: %d \n", productos_monitor[i].id);
    printf("Marca: %s \n", productos_monitor[i].marca);
    printf("Modelo: %s \n", productos_monitor[i].modelo);
    printf("Tamano de pantalla: %.1f pulgadas \n\n", productos_monitor[i].tamano);
}
//Notebook
void listar_notebook(NOTEBOOK productos_notebook[], int i)
{
    printf("Notebook N*%d \n", i+1);
    printf("ID: %d \n", productos_notebook[i].id);
    printf("Marca: %s \n", productos_notebook[i].marca);
    printf("Modelo: %s \n", productos_notebook[i].modelo);
    printf("Procesador: %s \n", productos_notebook[i].procesador);
    printf("Tamano de pantalla: %.1f pulgadas \n", productos_notebook[i].tamanoPantalla);
    printf("Cantidad de ram: %d  \n\n", productos_notebook[i].ram);
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
        printf("Mouse Numero %d: %s", i+1, nombre);
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
        printf("Teclado Numero %d: %s", i+1, nombre);
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
        printf("Teclado Numero %d: %s", i+1, nombre);
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
        printf("Teclado Numero %d: %s", i+1, nombre);
        printf(", %d gb ram", productos_notebook[i].ram);
        printf(", %.1f pulgadas de pantalla", productos_notebook[i].tamanoPantalla);
        printf(" (ID: %d)\n\n", productos_notebook[i].id);
        
    }
}


//FUNCION PARA ELIMINAR PRODUCTOS
//Mouse
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
//Teclado
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
//Monitor
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
//Notebook
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
