/*****************************************
 * Nombre: DibujarEstadisticas
 * Argumentos: Window *Westad :   Ventana donde se va a dibujar el patrón
 * Descripción: Dibuja el patrón para er las estadísticas del programa
 * Reglas de uso: 
 * Código de Retorno: N/A
 * Programador: 
 *****************************************/

//Include del módulo funcional
#include "Ventanas.h"

void DibujarEstadisticas(WINDOW *Westad)
{
    
    //Código del alumno


    char *Titulo="Estadisticas";
    int x,y;

    x = 0;

    wattron(Westad,COLOR_PAIR(9));

    if (Titulo != NULL) {
        y=(76-strlen(Titulo))/2;
        mvwprintw(Westad,x,y,"%s",Titulo);
    }

    //Rellena de espacios el interior del cuadrado (Hecho por IA)
    for (int i = 1; i < 14; i++) {
    mvwhline(Westad, i, 1, ' ', 76);
    }

    //Texto
    mvwprintw(Westad,2,1," Nombre del fichero:");
    mvwprintw(Westad,3,1," Fichas de discos:");
    mvwprintw(Westad,4,1," Numero de discos con memoria reservada:");
    mvwprintw(Westad,5,1," Microsegundos en Importar:");
    mvwprintw(Westad,6,1," Microsegundos en ordenar por Seleccion:");
    mvwprintw(Westad,7,1," Microsegundos en ordenar por Burbuja:");
    mvwprintw(Westad,8,1," Microsegundos en ordenar por Insercion:");
    mvwprintw(Westad,9,1," Microsegundos en ordenar por Quicksort:");
    mvwprintw(Westad,10,1," Microsegundos en crear el arbol Binario:");
    mvwprintw(Westad,11,1," Microsegundos en buscar por Obra:");
    mvwprintw(Westad,12,1," Microsegundos en buscar por Autor:");

    wattroff(Westad,COLOR_PAIR(9));

    //Dibuja el cuadrado en otro color
    wattron(Westad,COLOR_PAIR(8));
    Cuadrado(Westad,1,0,13,76,SOLIDO);
    wattroff(Westad,COLOR_PAIR(8));

    wattron(Westad,COLOR_PAIR(9));

    
}