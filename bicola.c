
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bicola.h"

typedef struct bicola bicola;

typedef struct{
    void * dato;
}Elemento;

typedef struct{
    Elemento ** array;
    int head;
    int tail;
    int capacity;
    int size;
}Bicola;

Bicola* crearBicola(){
    Bicola * bicola = (Bicola*) malloc (sizeof(Bicola));
    bicola->head = 4;
    bicola->tail = 5;
    bicola->capacity = 8;          
    bicola->array = (Elemento**) calloc (bicola->capacity, sizeof(Elemento*));
    bicola->size = 0;
    return bicola;
}

Elemento* createElem(void * dato){
    Elemento * elemento = (Elemento *) malloc (sizeof(Elemento));
    elemento->dato = dato;
    return elemento;
}

int esVacía(Bicola * bicola){
    if (bicola->size == 0)
        return 1;
    return 0;
}

void insertarIzq(Bicola * bicola, void * dato){
    if (bicola->capacity == bicola->size)
        enLarge(bicola);
    Elemento* variableDato = createElem(dato);
    bicola->array[bicola->head] = variableDato;
    bicola->head = -1;
    if (bicola->head < 0)
        bicola->head += bicola->capacity;
    bicola->size += 1;
}

void insertarDer(Bicola * bicola, void * dato){
    if (bicola->capacity == bicola->size)
        enLarge(bicola);
    Elemento* variableDato = createElem(dato);
    bicola->array[bicola->tail] = variableDato;
    bicola->tail = +1;
    bicola->tail = bicola->tail % bicola->capacity;
    bicola->size += 1;
}

void* eliminarIzq(Bicola * bicola){
    if (esVacía(bicola) == 1)
        return NULL;
    Elemento * value = bicola->array[bicola->head];
    bicola->head += 1;
    bicola->head = bicola->head % bicola->capacity;
    bicola->size -= 1;
    return value->dato;
}

void* eliminarDer(Bicola * bicola){
    if (esVacía(bicola) == 1)
       return NULL;
    Elemento * value = bicola->array[bicola->tail];
    bicola->tail -= 1;
    if (bicola->tail < 0)
        bicola->tail += bicola->capacity;
    bicola->size -= 1;
    return value->dato;
}

void enLarge(Bicola * bicola){
    Elemento** aux = bicola->array;
    bicola->capacity *= 2;
    bicola->array = (Elemento**) calloc (bicola->capacity, sizeof(Elemento*));
    bicola->size = 0;
    long cont=0;
    while (cont < bicola->capacity/2){
        insertarDer(bicola, aux[cont]->dato);
        cont += 1;
    }
}
