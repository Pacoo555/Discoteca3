/*****************************************
 * Nombre: ExportarFichero
 * Argumentos: DISCO **Fichas:   Puntero al array de discos
 *             WINDOW *Wfichero: Ventana para capturar el nombre del fichero
 * Descripción: Lee el nombre del fichero que contendrá los datos a exportar. Exporta los datos de la estructura
 *              de todos los discos en el fichero.
 * Reglas de uso: 
 * Código de Retorno:
 * Programador: JMSM (Sept-25)
 *****************************************/

#include "Ficheros.h"

void ExportarFichero(DISCO **Fichas,WINDOW *Wfichero)
{
    FILE *ficheroTemp;
    char NombreFichero[50];

    // Comprobamos si hay discos para exportar
    if (Estadisticas.NumeroFichas <= 0)
    {

        // Prueba
        touchwin(Wfichero);
        // -----------------------

        VentanaError("No hay discos para exportar.");
        return;
    }

     // Activamos eco y cursor
    echo();
    curs_set(1);

    // Capturamos el nombre del fichero
    mvwgetnstr(Wfichero, 2, 22, NombreFichero, 50);

    // Desactivamos eco y cursor
    noecho();
    curs_set(0);

    wrefresh(Wfichero);

    //Abrimos el fichero en modo para escritura
    ficheroTemp = fopen(NombreFichero, "w");
    if (ficheroTemp == NULL) {
        VentanaError("Error: No se pudo abrir el archivo.");
        return;
    }

    //Escribimos la cabecera del fichero
    int numDiscos = 0;
    fprintf(ficheroTemp, "Obra;ApellidoAutor;NombreAutor;Tonalidad;Opus;Duracion\n\n");

    //Por cada disco escribimos una línea en el fichero con sus datos separados por punto y coma
    for(int i = 0; i < Estadisticas.NumeroFichas; i++) {     
        fprintf(ficheroTemp, "%s;%s;%s;%s;%s;%s\n",
                (*Fichas)[i].Obra,
                (*Fichas)[i].ApellAutor,
                (*Fichas)[i].NomAutor,
                (*Fichas)[i].Tonalidad,
                (*Fichas)[i].Opus,
                (*Fichas)[i].Duracion);
        numDiscos++;
    }

    //Cerramos el fichero
    fclose(ficheroTemp);

    //Mostramos el numero de discos que han sido exportados, refrescamos la ventana y mostramos un mensaje de éxito
    mvwprintw(Wfichero,3,19,"%d discos han sido exportados",numDiscos);
    wrefresh(Wfichero);
    VentanaError("Los discos se han exportado correctamente.");
}