#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include "bicola.h"

struct Elemento{
    void * dato;
};

struct Bicola{
    Elemento ** array;
    int head;
    int tail;
    int capacity;
    int size;
};

Bicola* crearBicola(){
    Bicola * bicola = (Bicola*) malloc (sizeof(Bicola));
    bicola->head = 31;
    bicola->tail = 32;
    bicola->capacity = 64;          
    bicola->array = (Elemento**) calloc (bicola->capacity, sizeof(Elemento*));
    bicola->size = 0;
    return bicola;
}

Elemento* createElem(void * dato){
    Elemento * elemento = (Elemento *) malloc (sizeof(Elemento));
    elemento->dato = dato;
    return elemento;
}

int esVacia(Bicola * bicola){
    if (bicola->size == 0)
        return 1;
    return 0;
}

void insertarIzq(Bicola * bicola, void * dato){
    if (bicola->capacity == bicola->size){
        enLarge(bicola);
    }
    Elemento* variableDato = createElem(dato);
    bicola->array[bicola->head] = variableDato;
    bicola->head -= 1;
    if (bicola->head < 0)
        bicola->head += bicola->capacity;
    bicola->size += 1;
}

void insertarDer(Bicola * bicola, void * dato){
    if (bicola->capacity == bicola->size){
        enLarge(bicola);
    }
    Elemento* variableDato = createElem(dato);
    bicola->array[bicola->tail] = variableDato;
    bicola->tail += 1;
    bicola->tail = bicola->tail % bicola->capacity;
    bicola->size += 1;
}

void* eliminarIzq(Bicola * bicola){
    if (esVacia(bicola) == 1)
        return NULL;
    bicola->head += 1;
    bicola->head = bicola->head % bicola->capacity;
    bicola->size -= 1;
    Elemento * value = bicola->array[bicola->head];
    return value->dato;
}

void* eliminarDer(Bicola * bicola){
    if (esVacia(bicola) == 1)
       return NULL;
    bicola->tail -= 1;
    if (bicola->tail < 0)
        bicola->tail += bicola->capacity;
    bicola->size -= 1;
    Elemento * value = bicola->array[bicola->tail];
    return value->dato;
}

void enLarge(Bicola * bicola){
    Elemento** aux = bicola->array;
    bicola->capacity *= 2;
    bicola->array = (Elemento**) calloc (bicola->capacity, sizeof(Elemento*));
    bicola->size = 0;
    bicola->head = (int) (bicola->capacity/2);
    bicola->tail =(int) (bicola->capacity/2) + 1;
    long cont=0;
    while (cont < bicola->capacity/2){
        insertarDer(bicola, aux[cont]->dato);
        cont += 1;
    }
}
