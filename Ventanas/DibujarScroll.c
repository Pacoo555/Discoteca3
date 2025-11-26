/*****************************************
 * Nombre: DibujarScroll
 * Argumentos: Window *Wlistado:   Ventana donde se va a dibujar el patrón
 * Descripción: Dibuja el patrón para los listados de libros, con 10 fichas por pantalla.
 * Reglas de uso: 
 * Código de Retorno: N/A
 * Programador: 
 *****************************************/

////Include del módulo funcional
#include "Ventanas.h"

void DibujarScroll(WINDOW *Wlistado)
{
        
    //Código del alumno

    char *Titulo="Listado de Discos";
    int x,y;

    x = 0;

    wattron(Wlistado,COLOR_PAIR(9));

    if (Titulo != NULL) {
        y=(76-strlen(Titulo))/2;
        mvwprintw(Wlistado,x,y,"%s",Titulo);
    }

    //Rellena de espacios el interior del cuadrado (Hecho por IA)
    for (int i = 2; i < 14; i++) {
    mvwhline(Wlistado, i, 2, ' ', 72);
    }

    //Texto
    mvwprintw(Wlistado,2,3," Numero                    Obra                    Autor");

    wattroff(Wlistado,COLOR_PAIR(9));

    //Dibuja los cuadrados en otro color
    wattron(Wlistado,COLOR_PAIR(8));
    Cuadrado(Wlistado,1,2,3,72,SOLIDO);
    Cuadrado(Wlistado,1,2,13,72,SOLIDO);
    wattroff(Wlistado,COLOR_PAIR(8));

    //Texto en un color distinto
    wcolor_set(Wlistado,2,NULL);
    mvwprintw(Wlistado,14,3,"   ESC=Salir Flechas=Subir/Bajar AvPag/RePag=Pag siguiente/anterior");

    
}