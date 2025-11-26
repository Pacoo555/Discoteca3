/*****************************************
 * Nombre: ConsultarListaDerecha
 * Argumentos: Lista *Lista:   Puntero al TAD Lista
 * Descripción: Consulta el elemento de la derecha de Lista. No se elimina de Lista
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento de la derecha de Lista
 * Programador:
 *****************************************/

#include "Listas.h"

void *ConsultarListaDerecha(LISTA *Lista)
{
    
    // Código del Alumno

    if (Lista == NULL) {
        return NULL;
    } else {
        return Lista->Ultimo->Elemento;
    }
    
}