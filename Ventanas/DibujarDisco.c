/*****************************************
 * Nombre: DibujarDisco
 * Argumentos: Window *Wdisco:   Ventana donde se va a dibujar el patrón
 * Descripción: Dibuja el patrón para mostrar o capturar los datos de las fichas de un disco.
 * Reglas de uso: 
 * Código de Retorno: N/A
 * Programador: 
 *****************************************/

//Include del módulo funcional
#include "Ventanas.h"

void DibujarDisco(WINDOW *Wdisco)
{
        
    //Código del alumno

    char *Titulo="Gestion de Discos";
    int x,y;

    x = 0;

    wattron(Wdisco,COLOR_PAIR(9));

    //Centra el título
    if (Titulo != NULL) {
        y=(76-strlen(Titulo))/2;
        mvwprintw(Wdisco,x,y,"%s",Titulo);
    }

    //Rellena de espacios el interior del cuadrado (Hecho por IA)
    for (int i = 1; i < 12; i++) {
    mvwhline(Wdisco, i, 0, ' ', 76);
    }

    //Texto
    mvwprintw(Wdisco,2,2,"Numero de Disco:");
    mvwprintw(Wdisco,3,2,"Obra:");
    mvwprintw(Wdisco,4,2,"Apellidos del autor:");
    mvwprintw(Wdisco,5,2,"Nombre del autor:");
    mvwprintw(Wdisco,6,2,"Tonalidad:");
    mvwprintw(Wdisco,7,2,"Opus:");
    mvwprintw(Wdisco,8,2,"Duracion:");

    wattroff(Wdisco,COLOR_PAIR(9));

    //Dibuja el cuadrado en otro color
    wattron(Wdisco,COLOR_PAIR(8));
    Cuadrado(Wdisco,1,0,11,76,SOLIDO);
    wattroff(Wdisco,COLOR_PAIR(8));
}