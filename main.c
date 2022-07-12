#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include "bicola.h"

void InsertarAlInicio(Bicola * bicola);

int main() {
    system("color 0d");
    char opcion[2];
    int auxOpcion;
    Bicola * bicola = crearBicola();

    while(true) {
        system("cls");
        printf("\n========== MENU DE BICOLA ==========\n\n");
        printf("1.-  Insertar Elemento al Inicio\n");
        printf("2.-  Insertar Elemento al Final\n");
        printf("3.-  Eliminar Elemento del Inicio\n");
        printf("4.-  Eliminar Elemento del Final\n");  
        printf("5.- EXIT\n");

        printf("\nINGRESE SU OPCION: ");

        while (true) {
            gets(opcion);
            if (esNumero(opcion)) break;
            else printf("Opcion ingresada incorrecta, intentelo de nuevo: ");
        }

        auxOpcion = convertirNum(opcion);
        fflush(stdin);

        switch(auxOpcion)
        {
            case 1: 
                InsertarAlInicio(bicola);
                break;
            case 2: 
                InsertarAlFinal(bicola);
                break;
            case 3: 
                EliminarAlInicio(bicola);
                break;
            case 4: 
                EliminarAlFinal(bicola);
                break;
                return EXIT_SUCCESS;
        }
    return 0;
    }
}

void InsertarAlInicio(Bicola * bicola){
    system("cls");
    int * numero = (int *) malloc (sizeof(int));
    printf("Inserte un numero: ");
    scanf("%i", numero);
    insertarIzq(bicola, numero);
}

void InsertarAlFinal(Bicola * bicola){
    system("cls");
    int * numero = (int *) malloc (sizeof(int));
    printf("Inserte un numero: ");
    scanf("%i", numero);
    insertarDer(bicola, numero);
}

void EliminarAlInicio(Bicola * bicola){
    system("cls");
    int * numero = ((int *)eliminarIzq(bicola));
    printf("El numero eliminado es: %i", *numero);
}
void EliminarAlFinal(Bicola * bicola){
    system("cls");
    int * numero = ((int *)eliminarDer(bicola));
    printf("El numero eliminado es: %i", *numero);
}

