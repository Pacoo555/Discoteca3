/*****************************************
 * Nombre: Apilar
 * Argumentos: PILA *Pila:      Puntero al TAD Pila
 *             void *Elemento:  Puntero al elemento a apilar
 * Descripción: Apila el elemento Elemento al comienzo de la Pila
 * Reglas de uso: 
 * Código de Retorno: Nuevo Puntero al TAD Pila
 * Programador:
 *****************************************/

#include "Pilas.h"

PILA *Apilar(PILA *Pila,void *Elemento)
{

    NODO *Nuevo = (NODO *)malloc(sizeof (NODO));
    if (Nuevo == NULL) {
        return Pila; 
    }
    Nuevo->Elemento = Elemento;
    Nuevo->Siguiente = Pila;
    return Nuevo;
    
}