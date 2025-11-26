/*****************************************
 * Nombre: InsertarCabecera
 * Argumentos: COLA *Cola:      Puntero al TAD Cola
 *             void *Elemento:  Puntero al elemento a insertar
 * Descripción: Inserta el elemento dado en la cabecera de la Cola (primer elemento)
 * Reglas de uso: La Cola tiene que estar creada
 * Código de Retorno:  0 - Éxito
 *                    -1 - La Cola no está creada o no se pudo alocar espacio nuevo
 * Programador:
 *****************************************/

#include "Colas.h"

int InsertarCabecera(COLA *Cola, void *Elemento)
{
    
    // La cola no esta creada
    if (!Cola) {
        return -1;
    }

    // Dando espacio al nuevo nodo
    NODO *Nuevo = (NODO *)malloc(sizeof(NODO));
    if (!Nuevo) {
        return -1;
    }

    // Insertar el elemento nuevo en el primer elemento
    Nuevo->Elemento = Elemento;
    Nuevo->Siguiente = Cola->Cabecera;
    Cola->Cabecera = Nuevo;
    
    
    if (Cola->Final == NULL) {
        Cola->Final = Nuevo;
    }
    return 0;
}