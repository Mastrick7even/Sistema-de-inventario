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
} user;

typedef struct teclado{
    int id;
    char marca[20];
    char modelo[20];
    char idioma[20];
} keyboard;

typedef struct mouse{
    int id;
    char marca[20];
    char modelo[20];
} mouse;

typedef struct monitor{
    int id;
    char marca[20];
    char modelo[20];
    float tamano;
} monitor;

typedef struct notebook{
    int id;
    char marca[20];
    char modelo[20];
    char procesador[30];
    float tamanoPantalla;
    int ram;
} notebook;

typedef struct pc_escritorio{
    int id;
    char marca[20];
    char modelo[20];
    int ram;
    char procesador[30];
    keyboard teclado;
    mouse mouse;
    monitor monitor;
} desktop;


int main(){
    //PRECARGAR 3 ARTICULOS DE CADA TIPO
    return 0;
}