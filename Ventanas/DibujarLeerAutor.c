/*****************************************
 * Nombre: DibujarLeerAutor
 * Argumentos: Window *Wautor:   Ventana donde se va a dibujar el patrón
 * Descripción: Dibuja el patrón para leer el comienzo del apellido del autor(es) de los que se desean
 *              buscar y listar sus libros.
 * Reglas de uso: 
 * Código de Retorno: N/A
 * Programador: 
 *****************************************/

//Include del módulo funcional
#include "Ventanas.h"

void DibujarLeerAutor(WINDOW *Wautor)
{
    
    //Código del alumno

    char *Titulo="Busqueda por Autor";
    int x,y;

    x = 0;

    wattron(Wautor,COLOR_PAIR(9));

    if (Titulo != NULL) {
        y=(76-strlen(Titulo))/2;
        mvwprintw(Wautor,x,y,"%s",Titulo);
    }

    wattron(Wautor,COLOR_PAIR(9));

    //Rellena de espacios el interior del cuadrado (Hecho por IA)
    for (int i = 1; i < 3; i++) {
    mvwhline(Wautor, i, 2, ' ', 72);
    }

    //Texto
    mvwprintw(Wautor,2,3,"Apellidos del Autor:");
    wattroff(Wautor,COLOR_PAIR(9));

    //Dibuja el cuadrado en otro color
    wattron(Wautor,COLOR_PAIR(8));
    Cuadrado(Wautor,1,2,3,72,SOLIDO);
    wattroff(Wautor,COLOR_PAIR(8));
    
}