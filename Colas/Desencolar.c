/*****************************************
 * Nombre: Desencolar
 * Argumentos: COLA *Cola:   Puntero al TAD Cola
 * Descripción: Devuelve el puntero al primer elemento de la Cola (Cabecera) y lo elimina de la Cola
 * Reglas de uso: El puntero debe ser void *
 * Código de Retorno: Puntero al elemento desencolado
 *                    NULL si la cola no está creada o no tiene elementos
 * Programador:
 *****************************************/

#include "Colas.h"

void* Desencolar(COLA *Cola)
{
    // Verificar si la cola existe o esta vacia
    if (!Cola || Cola->Cabecera == NULL) {
        return NULL;
    }

    // Guardar el primer nodo y obtener su elemento
    NODO *Primero = Cola->Cabecera;
    void *Elemento = Primero->Elemento;
    Cola->Cabecera = Primero->Siguiente;

    // Actualizar el final si esta vacia
    if (Cola->Cabecera == NULL) {
        Cola->Final = NULL;
    }

    // Liberar el nodo
    free(Primero);
    return Elemento;
}