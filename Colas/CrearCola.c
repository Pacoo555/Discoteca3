/*****************************************
 * Nombre: CrearCola
 * Argumentos: N/A
 * Descripción: Crea una cola sin elementos.
 * Reglas de uso: 
 * Código de Retorno: Puntero a la Cola creada (vacía)
 *                    NULL - No se ha podido alocar espacio nuevo
 * Programador:
 *****************************************/

#include "Colas.h"

COLA *CrearCola()
{
    // Dar espacio a la cola
    COLA *Cola = (COLA *)malloc(sizeof(COLA));
    if (!Cola) {
        return NULL;
    }

    // Inicializar la cola
    Cola->Cabecera = NULL;
    Cola->Final = NULL;

    return Cola;
}