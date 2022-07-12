#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <Windows.h>
#include "bicola.h"

void InsertarAlInicio(Bicola * bicola);

void InsertarAlInicio(Bicola * bicola);

void InsertarAlFinal(Bicola * bicola);

void EliminarAlInicio(Bicola * bicola);

void EliminarAlFinal(Bicola * bicola);

void MostrarBicola(Bicola * bicola);

size_t convertirNum(char *string);

bool esNumero(char *caracter);


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
        printf("5.-  Mostrar Bicola\n");   
        printf("6.-  EXIT\n");

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
            case 5:
                MostrarBicola(bicola);
                break;
            case 6:  
                return EXIT_SUCCESS;
        }
    }
    return 0;
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
    if(numero == NULL){
        printf("No hay numeros en la bicola\n");
        system("pause");
        return;
    }
    printf("El numero eliminado es: %i\n", *numero);
    system("pause");
}
void EliminarAlFinal(Bicola * bicola){
    system("cls");
    int * numero = ((int *)eliminarDer(bicola));
    if(numero == NULL){
        printf("No hay numeros en la bicola\n");
        system("pause");
        return;
    }
    printf("El numero eliminado es: %i\n", *numero);
    system("pause");
}

void MostrarBicola(Bicola * bicola){
    system("cls");
    int * numero = ((int *)eliminarIzq(bicola)); 
    if(numero == NULL){
        printf("No hay numeros en la bicola\n");
        system("pause");
        return;
    }
    printf("Bicola: ");
    while(numero != NULL){
        printf("%i ", *numero);
        numero = ((int *)eliminarIzq(bicola));
    }
    printf("\n");
    system("pause");
}

size_t convertirNum(char *string) {
    size_t cont;
    size_t num = 0;

    for (cont = 0; cont < strlen(string); cont++) {
        num = (num * 10) + (string[cont] - '0');
    }
    
    return num;
}

bool esNumero(char *caracter) {
    int cont;
    if( !strcmp(caracter, "0") ) return false;
    for (cont = 0; cont < strlen(caracter); cont++) {
        if (isdigit(caracter[cont]) != true) {
            return false;
        }
    }

    return true;
}
