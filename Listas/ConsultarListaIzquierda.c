/*****************************************
 * Nombre: ConsultarListaIzquierda
 * Argumentos: Lista *Lista:   Puntero al TAD Lista
 * Descripción: Consulta el elemento a la izquierda de Lista. No se elimina el elemento
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento a la izquierda de la Lista 
 * Programador:
 *****************************************/

#include "Listas.h"

void *ConsultarListaIzquierda(LISTA *Lista)
{
    
    // Código del Alumno

    if (Lista == NULL) {
        return NULL;
    } else {
        return Lista->Primero->Elemento;
    }
    
}