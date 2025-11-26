/*****************************************
 * Nombre: Desapilar
 * Argumentos: PILA *Pila:      Puntero al TAD Pila
 *             void **Elemento: Puntero de referencia al puntero del elemento que se desapila
 * Descripción: Desapila el primer elemento de la pila y guarda el puntero desapilado en *Elemento
 * Reglas de uso: 
 * Código de Retorno: Nuevo Puntero al TAD Pila
 * Programador:
 *****************************************/

#include "Pilas.h"

PILA *Desapilar(PILA *Pila,void **Elemento)
{

    if (Pila == NULL) {
       *Elemento = NULL;
        return NULL;
    }

    PILA *Siguiente = Pila->Siguiente;
    if (Elemento) *Elemento = Pila->Elemento;
    free(Pila);
    return Siguiente;
    
}