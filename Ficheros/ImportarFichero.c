/*****************************************
 * Nombre: ImortarFichero
 * Argumentos: DISCO **Fichas:   Puntero al array de discos
 *             WINDOW *Wfichero: Ventana para capturar el nombre del fichero
 *             bool sumar:       Si es true las fichas de discos se añaden a las existentes,
 *                               si es false la lista de discos tiene que estar vacía.
 * Descripción: Lee el nombre del fichero que contendrá los datos a importar. Carga los discos del fichero
 *              en el array de discos, dimensionándolo si es necesario y descartando los que no tengan título o autor.
 * Reglas de uso: 
 * Código de Retorno:
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "Ficheros.h"

void ImportarFichero(DISCO **Fichas,WINDOW *Wfichero,bool sumar)
{
   
    // Código del alumno

    FILE *ficheroTemp;
    struct timeval inicio, fin;

    // Verificar si ya existen discos y mostrar error si es necesario
    if (sumar == false) {
        if (Estadisticas.NumeroFichas != 0) {
            VentanaError("Error: La lista de discos debe estar vacia para importar sin sumar.");
            return;
        }
    }

    if (sumar == true) {
        if (Estadisticas.NumeroFichas <= 0) {
            VentanaError("Error: La lista de discos debe tener discos para sumar.");
            return;
        }
    }


    // Limpio la ventana y la vuelvo a dibujar (Es la única forma que he encontrado de que no desaparezca después)
    wclear(Wfichero);
    DibujarGestionFichero(Wfichero);
    wrefresh(Wfichero);

    char NombreFichero[50];

    // Activar eco y cursor
    echo();
    curs_set(1);

    // Capturar el nombre del fichero
   mvwgetnstr(Wfichero, 2, 22, NombreFichero, 50);

    // Desactivar eco y cursor
    noecho();
    curs_set(0);

    wrefresh(Wfichero);

    // Abrir el fichero para lectura y verificar que existe
    ficheroTemp = fopen(NombreFichero, "r");
    if (ficheroTemp == NULL) {
        VentanaError("Error: No se pudo abrir el archivo.");
        return;
    }

    // Iniciar cronómetro
    gettimeofday(&inicio, NULL);

    int numDiscos = 0;
    char linea[256];

    // Contar el número de discos en el fichero
    while (fgets(linea, sizeof(linea), ficheroTemp) != NULL)
    {
        numDiscos++;
    }
    numDiscos--; // Resto 1 por la cabecera

    // Verificar que hay al menos 2 discos (1 disco + cabecera)
    if (numDiscos < 2) {
        VentanaError("Error: El archivo no contiene discos.");
        fclose(ficheroTemp);
        return;
    }

    // Asignar o reasignar memoria para los discos en funcion de sumar y el número de discos
    if (sumar == false) {
        *Fichas = (DISCO *)malloc(sizeof(DISCO) * numDiscos);
        if (*Fichas == NULL) {
            VentanaError("Error: No se pudo asignar memoria.");
            fclose(ficheroTemp);
            return;
        }
    }
    if (sumar == true) {
        *Fichas = (DISCO *)realloc(*Fichas, sizeof(DISCO) * (Estadisticas.NumeroFichas + numDiscos));
        if (*Fichas == NULL) {
            VentanaError("Error: No se pudo reasignar memoria.");
            fclose(ficheroTemp);
            return;
        }
    }

    // Volver al inicio del fichero para leer los discos
    rewind(ficheroTemp);
    fgets(linea, sizeof(linea), ficheroTemp); // Saltar la cabecera

    // Variables necesarias para procesar los discos
    char *token[6];
    char *lineaPtr;
    int i;
    int contadorFichas = 0;
    int contadorFichasDescartadas = 0;

    // Si se van a sumar discos, empezar a contar desde el final de los existentes
    if (sumar == true) {
        contadorFichas = Estadisticas.NumeroFichas;
    }

    // Leer y procesar cada línea del fichero
    while (fgets(linea, sizeof(linea), ficheroTemp) != NULL)
    {
        // Separar la línea en tokens con strsep, delimitados por ";"
        lineaPtr = linea;
        for (i = 0; i < 6; i++) {
            token[i] = strsep(&lineaPtr, ";");
        }

        // Descartar discos sin título o apellido
        if (token[0] == NULL || strlen(token[0]) == 0 || token[1] == NULL || strlen(token[1]) == 0) {
            contadorFichasDescartadas++;
            continue; // Saltar este disco
        }

        // Asignar memoria y copiar los datos del disco
        (*Fichas)[contadorFichas].Obra = malloc(strlen(token[0]) + 1);
        (*Fichas)[contadorFichas].ApellAutor = malloc(strlen(token[1]) + 1);
        (*Fichas)[contadorFichas].NomAutor = malloc(strlen(token[2]) + 1);
        (*Fichas)[contadorFichas].Tonalidad = malloc(strlen(token[3]) + 1);
        (*Fichas)[contadorFichas].Opus = malloc(strlen(token[4]) + 1);
        (*Fichas)[contadorFichas].Duracion = malloc(strlen(token[5]) + 1);

        strcpy((*Fichas)[contadorFichas].Obra, token[0]);
        strcpy((*Fichas)[contadorFichas].ApellAutor, token[1]);
        strcpy((*Fichas)[contadorFichas].NomAutor, token[2]);
        strcpy((*Fichas)[contadorFichas].Tonalidad, token[3]);
        strcpy((*Fichas)[contadorFichas].Opus, token[4]);
        strcpy((*Fichas)[contadorFichas].Duracion, token[5]);

        contadorFichas++;
    }

    // Ajustar el contador en caso de sumar
    if (sumar == true)
    {
    contadorFichas = contadorFichas - Estadisticas.NumeroFichas;
    }

    // Actualizar la ventana con el número de discos importados y descartados
    mvwprintw(Wfichero,3,19,"%d",contadorFichas);
    mvwprintw(Wfichero,3,55,"%d",contadorFichasDescartadas);
    wrefresh(Wfichero);

    // Finalizar cronómetro y actualizar estadísticas
    fclose(ficheroTemp);
    gettimeofday(&fin, NULL);
    Estadisticas.TiempoCarga = DifTiempo(inicio, fin);
    Estadisticas.NumeroFichas += contadorFichas;

    // Mostrar mensaje
    VentanaError("Fichero importado correctamente.");

    return;
}