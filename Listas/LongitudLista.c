/*****************************************
 * Nombre: LongitudLista
 * Argumentos: Lista *Lista:   Puntero al TAD Lista
 * Descripción: Calcula el número de elementos de Lista
 * Reglas de uso: 
 * Código de Retorno: el número de elementos de Lista
 * Programador:
 *****************************************/

#include "Listas.h"

int LongitudLista(LISTA *Lista)
{
    
    // Código del Alumno

    int num = 0;

    NODO *temp;
    temp = Lista->Primero;

    while (temp != NULL)
    {
        num++;
        temp = temp->Siguiente;
    }

    return num;
    
}