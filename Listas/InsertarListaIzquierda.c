/*****************************************
 * Nombre: InsertarListaIzquierda
 * Argumentos: Lista *Lista:    Puntero al TAD Lista
 *             void *Elemento:  Puntero al elemento a insertar
 * Descripción: Inserta el elemento Elemento en Lista por la Izquierda
 * Reglas de uso: 
 * Código de Retorno:  0 - Éxito
 *                    -1 - La lista no está creada o no se ha podido alocar memoria nueva
 * Programador:
 *****************************************/

#include "Listas.h"

int InsertarListaIzquierda(LISTA *Lista, void *Elemento)
{
    
    // Código del Alumno

    NODO *nuevoNodo;

    if (Lista == NULL) {
        return -1;
    }

    nuevoNodo = (NODO *) malloc(sizeof(NODO));
    if (nuevoNodo == NULL) {
        return -1;
    }

    nuevoNodo->Elemento = Elemento;

    nuevoNodo->Siguiente = Lista->Primero;

    Lista->Primero = nuevoNodo;

    // Si la lista está vacía, el nuevo nodo también es el último
    if (Lista->Ultimo == NULL) {
        Lista->Ultimo = nuevoNodo;
    }

    return 0;
    
}