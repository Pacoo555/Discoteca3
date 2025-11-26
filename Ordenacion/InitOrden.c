/*****************************************
 * Nombre: InitOrden
 * Argumentos: LIBRO *Fichas:   Array de libros
 * Descripción: Genera un array con los punteros a los libros ordenados por
 *              su orden numérico, es decir, el mismo orden el que están en
 *              en array de libros Fichas.
 * Reglas de uso: Hay que alocar el espacio para el array de punteros
 * Código de Retorno: Puntero al array de punteros a los libros ordenados (LIBROS **)
 * Programador:
 *****************************************/

#include "../Discoteca.h"

DISCO **InitOrden(DISCO *Fichas)
{
    
    // Código del alumno

    int total = Estadisticas.NumeroFichas;

    DISCO **Orden;

    Orden = (DISCO **)malloc(sizeof(DISCO *) * total);

    for (int i = 0; i < total; i++) {
        Orden[i] = &Fichas[i];
    }

    return Orden;
    
}