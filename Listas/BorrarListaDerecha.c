/*****************************************
 * Nombre: BorrarListaDerecha
 * Argumentos: LISTA *Lista:   Puntero al TAD Lista
 * Descripción: Borra un elemento de Lista a la derecha.
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento que se ha borrado o NULL si no había elementos
 * Programador:
 *****************************************/

#include "Listas.h"

void *BorrarListaDerecha(LISTA *Lista)
{
    
    // Código del Alumno
    
    NODO *temp;
    NODO *nodoABorrar;
    void *dato;

    if (Lista == NULL) {
        return NULL;
    }

    // Solo hay un elemento
    if (Lista->Primero == Lista->Ultimo) {
        nodoABorrar = Lista->Primero;
        dato = nodoABorrar->Elemento;
        
        Lista->Primero = NULL;
        Lista->Ultimo = NULL;
        
        free(nodoABorrar);
        return dato;
    }

    // Hay más de un elemento. Bucle hasta el penúltimo.
    temp = Lista->Primero;
    while (temp->Siguiente != Lista->Ultimo) {
        temp = temp->Siguiente;
    }

    nodoABorrar = Lista->Ultimo;
    dato = nodoABorrar->Elemento;

    free(nodoABorrar);
    
    temp->Siguiente = NULL;
    Lista->Ultimo = temp;

    return dato;
}