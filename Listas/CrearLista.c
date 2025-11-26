/*****************************************
 * Nombre: CreaLista
 * Argumentos: N/A
 * Descripción: Crea una Lista vacía
 * Reglas de uso: 
 * Código de Retorno: Puntero a la Lista creada (vacía)
 * Programador:
 *****************************************/

#include "Listas.h"

LISTA *CrearLista()
{
    
    // Código del Alumno

    LISTA *lista;

    lista = (LISTA *) malloc(sizeof(LISTA));

    lista->Primero = NULL;
    lista->Ultimo = NULL;

    return lista;
}