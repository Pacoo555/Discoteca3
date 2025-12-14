using System;
using System.Collections.Generic;
using System.IO;
using System.Diagnostics;

namespace Discoteca.Ordenacion
{
    //Datos del disco
    public struct DISCO
    {
        public string Obra;
        public string ApellAutor;
        public string NomAutor;
        public string Tonalidad;
        public string Opus;
        public string Duracion;

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

    public class OrdenacionSort
        {
        private const string Ruta = "Discoteca.csv";
        private const char Separador = ';';

        public static void Main(string[] args)
        {
            Stopwatch reloj = Stopwatch.StartNew();

            //Lista para almacenar discos
            List<DISCO> listaDiscos = new List<DISCO>();
            int discosCargados = 0;
            int discosDescartados = 0;

            if (File.Exists(Ruta))
            {
                //Leemos el CSV
                using (StreamReader sr = new StreamReader(Ruta))
                {
                    string linea;
                    sr.ReadLine();

                    while ((linea = sr.ReadLine()) != null)
                    {
                        string[] campos = linea.Split(Separador, StringSplitOptions.None);

                        if (string.IsNullOrWhiteSpace(linea))
                        {
                            continue;
                        }

                        bool tieneCamposValidos = campos.Length >= 2 && !string.IsNullOrWhiteSpace(campos[0]) && !string.IsNullOrWhiteSpace(campos[1]);

                        if (tieneCamposValidos)
                        {
                            string obra = campos[0];
                            string apellAutor = campos[1];
                            string nomAutor = (campos.Length > 2) ? campos[2] : string.Empty;
                            string tonalidad = (campos.Length > 3) ? campos[3] : string.Empty;
                            string opus = (campos.Length > 4) ? campos[4] : string.Empty;
                            string duracion = (campos.Length > 5) ? campos[5] : string.Empty;

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

                //Ordenamos la lista usando sort por obra
                listaDiscos.Sort((a, b) => a.Obra.CompareTo(b.Obra));

                reloj.Stop();

                //Resultados
                Console.WriteLine("=== ORDENACIÓN CON SORT DE .NET ===");
                Console.WriteLine($"Discos cargados: {discosCargados}");
                Console.WriteLine($"Discos descartados: {discosDescartados}");
                Console.WriteLine($"Tiempo de ejecución: {reloj.Elapsed.TotalMilliseconds:F4} ms");
                Console.WriteLine();
                Console.WriteLine("=== Primeros 10 discos ordenados por Obra ===");

                int contador = 0;
                foreach (DISCO disco in listaDiscos)
                {
                    if (contador >= 10)
                        break;

                    Console.WriteLine($"{contador + 1}. {disco.Obra} - {disco.ApellAutor}, {disco.NomAutor}");
                    contador++;
                }
            }
            else
            {
                Console.WriteLine("Error: El fichero Discoteca.csv no existe.");
            }
        }
    }
}
