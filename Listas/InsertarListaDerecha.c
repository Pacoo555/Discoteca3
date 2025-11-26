/*****************************************
 * Nombre: InsertarListaDerecha
 * Argumentos: Lista *Lista:    Puntero al TAD Lista
 *             void *Elemento:  Puntero al elemento a insertar
 * Descripción: Inserta el elemento Elemento en Lista por la Derecha
 * Reglas de uso: 
 * Código de Retorno:  0 - Éxito
 *                    -1 - La lista no está creada o no se ha podido alocar memoria nueva
 * Programador:
 *****************************************/

#include "Listas.h"

int InsertarListaDerecha(LISTA *Lista, void *Elemento)
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

    nuevoNodo->Siguiente = NULL; //Apunta a null ya que es el último

    Lista->Ultimo->Siguiente = nuevoNodo;
    Lista->Ultimo = nuevoNodo;

    // Si la lista está vacía, el nuevo nodo también es el primero
    if (Lista->Primero == NULL) {
        Lista->Primero = nuevoNodo;
    }

    return 0;
    
}