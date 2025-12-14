using System.Collections.Generic;
using System;
using System.IO;

namespace Discoteca2
{
    public class Funciones
    {
        private static int OrdenOperadores(char operador)
        {
            //Con esto definimos el orden de los operadores con valores numericos
            if (operador == '+' || operador == '-')
            {
                return 1;
            }
            if (operador == '*' || operador == '/')
            {
                return 2;
            }
            if(operador == '^')
            {
                return 3;
            }
            return 0;
            //Si no es operador entonoces devolvemos 0
        }

        private static double EvaluarValorVariable(char variable)
        {
            //Con esto conseguinmos que el valor de la variable sea su valor ASCII menos el valor ASCII de 'Z'
            return (double)variable - (double)'Z';
        }

        public static List<string> ConvertirAPostfijo(string expresionInfija)
        {
            //Definimos la lista de salida y la pila de operadores
            List<string> salida = new List<string>();
            Stack<char> pilaOperadores = new Stack<char>();


            //Recorremos la expresion infija caracter por caracter
            for(int i = 0; i < expresionInfija.Length; i ++)
            {
                char parte = expresionInfija[i];

                //Si hay un espacio en blanco lo ignoramos
                if (char.IsWhiteSpace(parte))
                {
                    continue;
                }

                //Si es un operando (numero o variable) lo convertimos a string y lo agregamos a la salida
                if (char.IsLetterOrDigit(parte))
                {
                    salida.Add(parte.ToString());
                }
                else if (parte == '(')
                {
                    //Si encontramos un parentesis de apertura lo agregamos a la pila de operadores
                    pilaOperadores.Push(parte);
                }
                else if (parte == ')')
                {
                    //Al encontrar un parentesis de cierre, desapilamos hasta encontrar el parentesis de apertura
                    while (pilaOperadores.Count > 0 && pilaOperadores.Peek() != '(')
                    {
                        //Agregamos los operadores desapilados a la salida
                        salida.Add(pilaOperadores.Pop().ToString());
                    }

                    if (pilaOperadores.Count == 0)
                    {
                        //Si no encontramos el paréntesis de apertura, la expresión no es valida porque hay paréntesis desbalanceados
                        Console.WriteLine("Hay paréntesis desbalanceados en la expresión.");
                        return null;
                    }
                    //Desapilamos el paréntesis de apertura y lo descartamos
                    pilaOperadores.Pop(); 

                }
                else if ("+-*/^".Contains(parte))
                {
                    //Si la parte es un operador, desapilamos los operadores de mayor o igual precedencia llamando a OrdenOperadores y los agregamos a la salida
                    while (pilaOperadores.Count > 0 && OrdenOperadores(pilaOperadores.Peek()) >= OrdenOperadores(parte))
                    {
                        salida.Add(pilaOperadores.Pop().ToString());
                    }
                    //Finalmente apilamos el operador actual
                    pilaOperadores.Push(parte);
                } else if (parte != ' ')
                {
                    //Si encontramos un caracter no reconocido, la expresión no es válida
                    Console.WriteLine("Hay un caracter no reconocido en la expresión");
                    return null;
                }
            }   

            while (pilaOperadores.Count > 0)
            {
                //Ahora verificamos si hay paréntesis desbalanceados  
                if(pilaOperadores.Peek() == '(' || pilaOperadores.Peek() == ')')
                {
                    //Si al final quedan paréntesis en la pila, la expresión no es válida porque hay paréntesis desbalanceados
                    Console.WriteLine("Hay paréntesis desbalanceados en la expresión.");
                    return null;
                }
                //Finalemente, desapilamos todos los operadores restantes y los agregamos a la salida
                salida.Add(pilaOperadores.Pop().ToString());
            }

            return salida;
        }

        public static double EvaluarPostfijo(List<string> expresionPostfija)
        {
            //Definimos una pila para los operandos
            Stack<double> pilaOperandos = new Stack<double>();

            //Recorremos cada parte de la expresion postfija
            foreach (string parte in expresionPostfija)
            {
                //Si la parte es un solo operando (numero o variable)
                if (parte.Length == 1 && char.IsLetterOrDigit(parte[0]))
                {
                    //Intentamos convertir la parte a un numero
                    if (char.IsDigit(parte[0]))
                    {
                        //Si es un numero, lo tratamos como constante, lo convertimos a double y lo apilamos a la pila de operandos
                        double valor = double.Parse(parte);
                        pilaOperandos.Push(valor);
                    }
                    else if (char.IsLetter(parte[0]))
                    {
                        //Si es una letra, la tratamos como variable y evaluamos su valor con la funcion EvaluarValorVariable y lo apilamos a la pila de operandos  
                        double valor = EvaluarValorVariable(parte[0]);
                        pilaOperandos.Push(valor);
                    }
                }
                else if ("+-*/^".Contains(parte))
                {
                    if (pilaOperandos.Count < 2)
                    {
                        //Si no hay suficientes operandos en la pila, la expresion no es valida
                        throw new InvalidOperationException("Error de evaluación: Faltan operandos para el operador.");
                    }

                    //Si la parte es un operador, desapilamos los dos operandos superiores
                    double operando2 = pilaOperandos.Pop();
                    double operando1 = pilaOperandos.Pop();
                    double resultado = 0;

                    //Realizamos la operacion correspondiente
                    switch (parte)
                    {
                        case "+":
                            resultado = operando1 + operando2;
                            break;
                        case "-":
                            resultado = operando1 - operando2;
                            break;
                        case "*":
                            resultado = operando1 * operando2;
                            break;
                        case "/":
                            resultado = operando1 / operando2;
                            break;
                        case "^":
                            resultado = Math.Pow(operando1, operando2);
                            break;
                    }

                    //Apilamos el resultado de la operacion
                    pilaOperandos.Push(resultado);
                }
            }

            //Al final, el unico valor en la pila es el resultado final de la expresion
            return pilaOperandos.Pop();
        }
    }
    public class Program
    {
        public static void Main(string[] args)
        {
            //Solicitamos al usuario que ingrese una expresion infija
            Console.WriteLine("Ingrese una expresión infija:");
            string expresionInfija = Console.ReadLine();

            try
            {
                //Convertimos la expresion infija a postfija
                List<string> expresionPostfija = Funciones.ConvertirAPostfijo(expresionInfija);

                if (expresionPostfija != null)
                {
                    //Evaluamos la expresion postfija
                    double resultado = Funciones.EvaluarPostfijo(expresionPostfija);

                    //Mostramos el resultado al usuario
                    Console.WriteLine("Expresión postfija: " + string.Join("",expresionPostfija));
                    Console.WriteLine("El resultado de la expresión es: " + resultado);
                }
            } catch (Exception ex)
            {
                //FInalmente solo hay que considerar cualquier error que pueda ocurrir durante la conversion o evaluacion
                Console.WriteLine("Ocurrió un error al evaluar la expresión: " + ex.Message);
            }
        }

    }
}
