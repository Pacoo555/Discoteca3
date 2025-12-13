/*****************************************
 * Nombre: BusquedaBinaria
 * Argumentos: LIBRO *Fichas:       Array de las fichas de libros
 * Descripción: Después de capturar los apellidos de un autor, busca las fichas de libros de ese autor,
 *              por el método de búsqueda binaria
 *              La comparación de los apellidos se hace en mayúsculas. 
 *              Después se muestran los resultados en una pantalla de scroll.
 * Reglas de uso: 
 * Código de Retorno: N/A
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "Busqueda.h"

void BusquedaBinaria(DISCO *Fichas)
{
    char *Autor;
    DISCO **Resultado=NULL;
    DISCO **Orden=NULL;
    int Hallados=0;
    struct timeval inicio, fin;
    bool Encontrado;

    // Añadir aquí la definición del resto de variables usadas
    int inf = 0, sup, medio;
    int pos = -1;
    char apellidoMin[256];
    char *p;
    int i;

    if ((Autor=LeerAutor()) == NULL)
        return;

    gettimeofday(&inicio,NULL);

    Orden=Quicksort(Fichas, ORDEN_POR_AUTOR);

    //Código del alumno del Algoritmo de Búsqueda Binaria
    sup = Estadisticas.NumeroFichas - 1;

    while (inf <= sup) {
        medio = inf + (sup - inf) / 2;

        // Convertir el apellido a minúsculas
        strcpy(apellidoMin, Orden[medio]->ApellAutor);
        for (p = apellidoMin; *p; ++p) *p = tolower(*p);

        int cmp = strcmp(apellidoMin, Autor);

        if (cmp == 0) {
            pos = medio;
            Encontrado = true;
            break; // Encontrado
        } 
        else if (cmp < 0) {
            inf = medio + 1; // Buscar en la mitad superior
        } 
        else {
            sup = medio - 1; // Buscar en la mitad inferior
        }
    }

    // Al encontrar un disco, se buscan los demás discos de ese autor
    if (Encontrado) {
        int inicio_rango = pos;
        int fin_rango = pos;

        // Buscar hacia atrás más discos del mismo autor
        while (inicio_rango > 0) {
            strcpy(apellidoMin, Orden[inicio_rango - 1]->ApellAutor);
            for (p = apellidoMin; *p; ++p) *p = tolower(*p);
            
            if (strcmp(apellidoMin, Autor) == 0)
                inicio_rango--;
            else
                break;
        }

        // Buscar hacia adelante más discos del mismo autor
        while (fin_rango < Estadisticas.NumeroFichas - 1) {
            strcpy(apellidoMin, Orden[fin_rango + 1]->ApellAutor);
            for (p = apellidoMin; *p; ++p) *p = tolower(*p);
            
            if (strcmp(apellidoMin, Autor) == 0)
                fin_rango++;
            else
                break;
        }

        // Crear el array con todos los encontrados
        Hallados = fin_rango - inicio_rango + 1;
        Resultado = (DISCO **)malloc(Hallados * sizeof(DISCO *));
        
        for (i = 0; i < Hallados; i++) {
            Resultado[i] = Orden[inicio_rango + i];
        }
    }

    free(Orden);
    
    gettimeofday(&fin,NULL);
    Estadisticas.TiempoBusquedaBinaria=DifTiempo(inicio,fin);

    if (Encontrado == false) {
        VentanaError("No hay autores que cumplan el criterio");
        return;
    }
    
    Listado1(Resultado,Hallados,Fichas);
    free(Resultado);
    return;
    
}