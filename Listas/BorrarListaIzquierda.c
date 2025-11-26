/*****************************************
 * Nombre: BorrarListaIzquierda
 * Argumentos: LISTA *Lista:   Puntero al TAD Lista
 * Descripción: Borra un elemento de Lista a la izquierda.
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento que se ha borrado o NULL si no había elementos
 * Programador:
 *****************************************/

#include "Listas.h"

void *BorrarListaIzquierda(LISTA *Lista)
{
    
    // Código del Alumno

    NODO *nodoABorrar;
    void *dato;

    if (Lista == NULL) {
        return NULL;
    }

    nodoABorrar = Lista->Primero;
    dato = nodoABorrar->Elemento;

    Lista->Primero = nodoABorrar->Siguiente;

    if (Lista->Primero == NULL) {
        Lista->Ultimo == NULL;
    }

    free(nodoABorrar);

    return dato;
    
}