/*****************************************
 * Nombre: Seleccion
 * Argumentos: LIBRO *Ficha:       Array de las fichas de libros
 *             int campo:          Campo por el que hacer la ordenación (Título o Autor)
 * Descripción: Ordena el array de fichas de libros en un doble puntero a las fichas de Libros,
 *              por lo que el movimient de datos se reduce al cambio de punteros.
 *              Se usa el algoritmo de ordenación de Selección.
 * Reglas de uso: 
 * Código de Retorno: LIBRO **: Doble puntero ordenado por el criterio pedido a las fichas de libros.
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "../Discoteca.h"

// Función para comparar dos discos
static int Comparar(DISCO *d1, DISCO *d2, int Campo)
{
    char Autor1[256];
    char Autor2[256];

    if (Campo == ORDEN_POR_TITULO) {
        return strcmp(d1->Obra, d2->Obra);
    } else {
        
        strcpy(Autor1, d1->ApellAutor);
        if (d1->NomAutor != NULL) {
            strcat(Autor1, ", ");
            strcat(Autor1, d1->NomAutor);
        }

        strcpy(Autor2, d2->ApellAutor);
        if (d2->NomAutor != NULL) {
            strcat(Autor2, ", ");
            strcat(Autor2, d2->NomAutor);
        }

        return strcmp(Autor1, Autor2);
    }
}

DISCO **Seleccion(DISCO *Ficha, int Campo)
{
    DISCO **Orden;
    struct timeval inicio, fin;
    
    //Añade aquí la definición del resto de variables necesarias

    int i, j, min;
    DISCO *temp;

    gettimeofday(&inicio,NULL);
    Orden=InitOrden(Ficha);

    //Código del Alumno del Algoritmo de ordenación por Selección

    for (i = 0; i < Estadisticas.NumeroFichas - 1; i++) {
        min = i;
        
        for (j = i + 1; j < Estadisticas.NumeroFichas; j++) {
            if (Comparar(Orden[j], Orden[min], Campo) < 0) {
                min = j;
            }
        }
        
        if (min != i) {
            temp = Orden[i];
            Orden[i] = Orden[min];
            Orden[min] = temp;
        }
    }

    gettimeofday(&fin,NULL);
    Estadisticas.TiempoSeleccion=DifTiempo(inicio,fin);

    return(Orden);
}