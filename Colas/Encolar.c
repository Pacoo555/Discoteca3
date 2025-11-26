/*****************************************
 * Nombre: Encolar
 * Argumentos: COLA *Cola:      Puntero al TAD Cola
 *             void *Elemento:  Puntero al Elemento a insertar
 * Descripción: Se inserta el elemento dado al final de la cola.
 *              Se aloca el espacio que sea necesario
 * Reglas de uso: La cola debe estar creada
 * Código de Retorno:  0 - Éxito
 *                    -1 - La Cola no está creada o no se pudo alocar espacio nuevo 
 * Programador:
 *****************************************/

#include "Colas.h"

int Encolar(COLA *Cola, void *Elemento)
{
    // La cola no esta creada
    if (!Cola) {
        return -1;
    }

    // Crear un nuevo nodo
    NODO *Nuevo = (NODO *)malloc(sizeof(NODO));
    if (!Nuevo) {
        return -1;
    }

    // Se inicializa el nuevo nodo
    Nuevo->Elemento = Elemento;
    Nuevo->Siguiente = NULL;

    // Se pone el nuevo nodo al final de la cola  
    if (Cola->Cabecera == NULL) {
        Cola->Cabecera = Nuevo;
        Cola->Final = Nuevo;
    } else {
        Cola->Final->Siguiente = Nuevo;
        Cola->Final = Nuevo;
    }
    return 0;
}