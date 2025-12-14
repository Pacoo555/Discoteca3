using System;
using System.Collections.Generic;
using System.IO;
//Libreria para medir el tiempo de ejecución
using System.Diagnostics;

namespace Discoteca1.Ficheros
{
    //Declaramos una estructura para almacenar los datos del disco
    public struct DISCO
    {
        public string Obra;
        public string ApellAutor;
        public string NomAutor;
        public string Tonalidad;
        public string Opus;
        public string Duracion;
        //Declaramos la clase DISCO con su constructor
        public DISCO(string obra, string apellAutor, string nomAutor, string tonalidad, string opus, string duracion)
        {
            this.Obra = obra;
            this.ApellAutor = apellAutor;
            this.NomAutor = nomAutor;
            this.Tonalidad = tonalidad;
            this.Opus = opus;
            this.Duracion = duracion;
        }
    }
    public class ImportarDiscos
    {
        //Definimos las constantes de la ruta, el separador y el número de campos
        private const string Ruta = "discos.csv";
        private const char Separador = ';';
        private const int NumCampos = 6;
        public static void Main(string[] args)
        {
            //Iniciamos el cronómetro para medir el tiempo de ejecución
            Stopwatch reloj = Stopwatch.StartNew();
            reloj.Start();
            //Inicializamos una lista para almacenar los discos
            List<DISCO> listaDiscos = new List<DISCO>();
            int discosCargados = 0;
            int discosDescartados = 0;
            if(File.Exists(Ruta))
            {
            using (StreamReader sr = new StreamReader(Ruta))
            {
                //Declaramos una variable para almacenar cada línea
                string linea;
                sr.ReadLine(); //Saltamos la primera línea (cabecera)
                //Leemos el fichero línea por línea
                while ((linea = sr.ReadLine()) != null)
                {
                    //Separamos las lineas en campos y comprobamos que la línea tiene el número correcto de campos
                    //Con StringSplitOptions.None nos aseguramos de que se conserven los campos vacíos
                    string[] campos = linea.Split(Separador, StringSplitOptions.None);
                    //Si la línea está vacía, la descartamos
                    if (string.IsNullOrWhiteSpace(linea))
                    {
                        continue;
                    }
                    //Usamos dos booelanos para comprobar si la línea tiene los campos mínimos y si son válidos
                    bool tieneCamposMinimos = campos.Length >= 2;
                    bool tieneCamposMinimosValidos = tieneCamposMinimos && !string.IsNullOrWhiteSpace(campos[0]) && !string.IsNullOrWhiteSpace(campos[1]);
                    //Por cada linea con los campos mínimos validos, comprobamos con ternarios si existe el campo y lo asignamos. Si no existe, asignamos un string vacío
                    if (tieneCamposMinimosValidos)
                    {
                        string obra = (campos.Length > 0) ? campos[0] : string.Empty;
                        string apellAutor = (campos.Length > 1) ? campos[1] : string.Empty;
                        string nomAutor = (campos.Length > 2) ? campos[2] : string.Empty;
                        string tonalidad = (campos.Length > 3) ? campos[3] : string.Empty;
                        string opus = (campos.Length > 4) ? campos[4] : string.Empty;
                        string duracion = (campos.Length > 5) ? campos[5] : string.Empty;   
                        
                        //Creamos un nuevo disco y lo añadimos a la lista
                        DISCO disco = new DISCO(obra, apellAutor, nomAutor, tonalidad, opus, duracion);
                        listaDiscos.Add(disco);
                        discosCargados++;
                    }
                    else
                    {
                        discosDescartados++;
                    }
                }
            }
                
                //Mostramos los resultados, usamos long para mostrar los microsegundos como enteros
                reloj.Stop();
                Console.WriteLine($"Discos cargados: {discosCargados}");
                Console.WriteLine($"Discos descartados: {discosDescartados}");
                Console.WriteLine($"Tiempo de ejecución: {(long)reloj.Elapsed.TotalMicroseconds} ms");
            }
            else
            {
                Console.WriteLine("El fichero no existe.");
            }
        }
    }
}