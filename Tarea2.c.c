//Diego Vargas Gomez 
//Bastian Arriagada Quero
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct user{
    int id;
    char nickname[50];
    char password[50];
    char nombres[50];
    char apellidoPaterno[30];
    char apellidoMaterno[30];
} USER;

typedef struct teclado{
    int id;
    char marca[20];
    char modelo[20];
    char idioma[20];
} KEYBOARD;

typedef struct mouse{
    int id;
    char marca[20];
    char modelo[20];
} MOUSE;

typedef struct monitor{
    int id;
    char marca[20];
    char modelo[20];
    float tamano;
} MONITOR;

typedef struct notebook{
    int id;
    char marca[20];
    char modelo[20];
    char procesador[30];
    float tamanoPantalla;
    int ram;
} NOTEBOOK;

typedef struct pc_escritorio{
    int id;
    char marca[20];
    char modelo[20];
    int ram;
    char procesador[30];
    KEYBOARD teclado;
    MOUSE mouse;
    MONITOR monitor;
} DESKTOP;


int main(){
    //PRECARGAR 3 ARTICULOS DE CADA TIPO
   //PRECARGA MOUSEP
    MOUSE producto1[] = {11897,"Logitech","G502 HERO"};
    MOUSE producto2[] = {11001, "HyperX","FPS Pro"};
    MOUSE producto3[] = {11034, "Logitech","Lightspeed"};
    //PRECARGA KEYBOARD
    KEYBOARD producto1[] = {11898,"Hyperx", "Alloy Core Rgb","Español"};
    KEYBOARD producto2[] = {11937,"RAZER" "BLACKWIDOW","Español"};
    KEYBOARD producto3[] = {11907,"RAZER" "CHROMA","Español"};
    //PRECARGA USUARIO
    USER usuario1[] = {991,"admin","admin123","Kylian","Mbappe", "Lottin"};
    
    char nickname;
    char contrasena;
    
    printf("\n Ingrese Nickname \n");
    gets(nickname);

    printf("\n Ingrese Contraseña \n");
    gets(contrasena);


    return 0;
}
