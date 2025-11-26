/*****************************************
 * Nombre: ConsultarCola
 * Argumentos: COLA *Cola:   Puntero al TAD Cola
 * Descripción: Devuelve un puntero al primer Elemento de la Cola.
 *              No se modifica la Cola, solo se consulta
 * Reglas de uso: 
 * Código de Retorno: Puntero al primer elemento de la Cola o NULL si la cola está vacía
 * Programador:
 *****************************************/

#include "Colas.h"

void *ConsultarCola(COLA *Cola)
{
    
    // Comprobar si la cola esta vacia o la cabezera es null
    if (!Cola || Cola->Cabecera == NULL) {
        return NULL;
    }

    // Devolver el primero elemento de la cola
    return Cola->Cabecera->Elemento;
}