/*****************************************
 * Nombre: DibujarGestionFichero
 * Argumentos: Window *Wfichero :   Ventana donde se va a dibujar el patrón
 * Descripción: Dibuja el patrón para leer el nombre del fichero y después de tratarlo mostrar
 *              el número de fichas de libros leídas y descartadas.
 * Reglas de uso: 
 * Código de Retorno: N/A
 * Programador: 
 *****************************************/

//Include del módulo funcional
#include "Ventanas.h"

void DibujarGestionFichero(WINDOW *Wfichero)
{
    
    //Código del alumno

    wattron(Wfichero,COLOR_PAIR(9));

    //Rellena de espacios el interior del cuadrado (Hecho por IA)
    for (int i = 1; i < 4; i++) {
    mvwhline(Wfichero, i, 2, ' ', 76);
    }

    //Texto
    mvwprintw(Wfichero,2,3,"Nombre del fichero:");
    mvwprintw(Wfichero,3,3,"Fichas tratadas:                 Fichas descartadas:");

    wattroff(Wfichero,COLOR_PAIR(9));

    //Dibuja el cuadrado en otro color
    wattron(Wfichero,COLOR_PAIR(8));
    Cuadrado(Wfichero,1,2,4,74,SOLIDO);
    wattroff(Wfichero,COLOR_PAIR(8));

    wattron(Wfichero,COLOR_PAIR(9));
}