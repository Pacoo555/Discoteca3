/*****************************************
 * Nombre: Cuadrado
 * Argumentos: Window *Wventana :   Ventana donde se va a dibujar el cuadrado 
 *             int y            :   Coordenada y de la esquina superior izquierda
 *             int x            :   Coordenada x de la esquina superior izquierda
 *             int lineas       :   Alto del cuadrado medido en líneas
 *             int columnas     :   Ancho del cuadrado medido en columnas
 *             char tipo        :   SOLIDO -> Se dibuja el cuadrado con los caracteres gráficos sólidos
 *                              :   DOSRAYAS -> Se dibuja el cuadrado con los cracteres gráficos de dos rayas simples
 * Descripción: Dibuja un cuadrado en pantalla con los datos dados
 * Reglas de uso: 
 * Código de Retorno: N/A
 * Programador: 
 *****************************************/

//Include del módulo funcional
#include "Ventanas.h"

void Cuadrado(WINDOW *Wventana,int y, int x, int lineas, int columnas,char tipo)
{
    
    int i;
    char solido[7] = {76, 81, 75, 88, 77, 74, 0};
    char dosrayas[7] = {67, 82, 66, 89, 68, 65, 0};

    if (tipo == DOSRAYAS)
    {
        strcpy(solido, dosrayas);
    }
    wattron(Wventana, A_ALTCHARSET);

    mvwaddch(Wventana, y, x, solido[0]);
    mvwaddch(Wventana, y, x + columnas - 1, solido[2]);
    mvwaddch(Wventana, y + lineas - 1, x, solido[4]);
    mvwaddch(Wventana, y + lineas - 1, x + columnas - 1, solido[5]);

    //Líneas horizontales
    for (i = 1; i < columnas - 1; i++)
    {
        mvwaddch(Wventana, y, x + i, solido[1]);
        mvwaddch(Wventana, y + lineas - 1,x + i, solido[1]);
    }

    //Lineas verticales
    for (i = 1; i < lineas - 1; i++)
    {
        mvwaddch(Wventana, y + i, x, solido[3]);
        mvwaddch(Wventana, y + i, x + columnas - 1, solido[3]);
    }

    wattroff(Wventana, A_ALTCHARSET);
    return;
    
}