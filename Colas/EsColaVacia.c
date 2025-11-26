/*****************************************
 * Nombre: EsColaVacía
 * Argumentos: COLA *Cola:   Puntero al TAD Cola
 * Descripción: Devuelve 'true' si la Cola está vacía o 'false' si tiene elementos
 * Reglas de uso: 
 * Código de Retorno: true  - La Cola no tiene elementos
 *                    false - La Cola tiene elementos
 * Programador:
 *****************************************/

#include "Colas.h"

bool EsColaVacia(COLA *Cola)
{
    
    // Comprobar si la cola esta vacia o la cabezera es null
    if (!Cola || Cola->Cabecera == NULL) {
        return true;
    }

    return false;
}