
#ifndef bicola_h
#define bicola_h

typedef struct Elemento Elemento;
typedef struct Bicola Bicola;

Bicola * crearBicola();

int esVacía(Bicola* bicola);

Elemento* createElem(void * dato);

void insertarIzq(Bicola* bicola, void * value);

void insertarDer(Bicola* bicola, void * value);

void* eliminarIzq(Bicola* bicola);

void* eliminarDer(Bicola* bicola);

void enLarge(Bicola* bicola);

#endif /*bicola.h*/
