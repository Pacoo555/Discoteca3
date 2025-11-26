/*****************************************
 * Nombre: DescartarFichero
 * Argumentos: DISCO **Fichas:   Puntero al array de discos
 *             WINDOW *Wfichero: Ventana para mostrar el nombre del fichero
 * Descripción: Muestra los datos del fichero y los discos almacenados y descarta todos
 *              los discos en memoria y libera la memoria asignada.
 * Reglas de uso: 
 * Código de Retorno:
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "Ficheros.h"

void DescartarFichero(DISCO **Fichas,WINDOW *Wfichero)
{
    
    // Código del alumno
    
    //Variables
    int i;
    int eleccion;

    // Comprobar si hay discos 
    if (Estadisticas.NumeroFichas <= 0)
    {

        // Prueba
        touchwin(Wfichero);
        // -----------------------

        VentanaError("No hay discos para descartar.");
        return;
    }

    // Creando el mensaje
    char mensajeConfirmacion[100];
    sprintf(mensajeConfirmacion, "¿Descartar TODOS los %d discos (S/N)?", Estadisticas.NumeroFichas);

    // Leer la opcion del usuario

    //Prueba
    touchwin(Wfichero);
    // ---------------------

    eleccion = VentanaSN(mensajeConfirmacion);

    // Si es S
    if (eleccion == 'S')
    {

        // Liberar
        for ( i = 0; i < Estadisticas.NumeroFichas; i++)
        {
            if ((*Fichas)[i].Obra != NULL) free((*Fichas)[i].Obra);
            if ((*Fichas)[i].ApellAutor != NULL) free((*Fichas)[i].ApellAutor);
            if ((*Fichas)[i].NomAutor != NULL) free((*Fichas)[i].NomAutor);
            if ((*Fichas)[i].Tonalidad != NULL) free((*Fichas)[i].Tonalidad);
            if ((*Fichas)[i].Opus != NULL) free((*Fichas)[i].Opus);
            if ((*Fichas)[i].Duracion != NULL) free((*Fichas)[i].Duracion);
        }

        // Poner a NULL el puntero
        free(*Fichas);
        *Fichas = NULL;

        Estadisticas.NumeroFichas = 0;

        // Prueba
        mvwprintw(Wfichero,3,19,"0               "); 
        mvwprintw(Wfichero,3,55,"                    ");
        // -------------------------------------------------

        // Prueba
        touchwin(Wfichero);
        // -------------------

        VentanaError("Discos descartados correctamente.");
    } else { // Si la eleccion es N

        // Prueba
        touchwin(Wfichero);
        // -------------------------------

        VentanaError("Operacion cancelada");
    }

    return;
}