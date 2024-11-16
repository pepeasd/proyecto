using System;
using System.Windows.Forms;

namespace InterfazEstadistica  // Asegúrate de que el namespace coincida con el de Program.cs
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnCalcular_Click(object sender, EventArgs e)
        {
            // Verificar que la cantidad es un número válido
            int cantidad;
            if (!int.TryParse(txtCantidad.Text, out cantidad))
            {
                MessageBox.Show("Por favor ingrese un número válido para la cantidad.");
                return;
            }

            // Verificar que los números sean válidos
            string[] numerosTexto = txtNumeros.Text.Split(',');
            int[] numeros = new int[cantidad];
            for (int i = 0; i < cantidad; i++)
            {
                if (i < numerosTexto.Length && !int.TryParse(numerosTexto[i], out numeros[i]))
                {
                    MessageBox.Show($"El valor '{numerosTexto[i]}' no es un número válido.");
                    return;
                }
            }

            // Calcular media, mediana, moda, desviación estándar y rango (en tu código C++)
            double media = calcularMedia(numeros);
            double mediana = calcularMediana(numeros);
            int moda = calcularModa(numeros);
            double desviacionEstandar = calcularDesviacionEstandar(numeros, media);
            int rango = calcularRango(numeros);

            // Mostrar los resultados en el txtResultados
            txtResultados.Text = $"Media: {media}\r\nMediana: {mediana}\r\nModa: {moda}\r\nDesviación estándar: {desviacionEstandar}\r\nRango: {rango}";
        }

        // Métodos de cálculo en C# (ejemplo)

        private double calcularMedia(int[] datos)
        {
            double suma = 0;
            foreach (int num in datos)
            {
                suma += num;
            }
            return suma / datos.Length;
        }

        private double calcularMediana(int[] datos)
        {
            Array.Sort(datos);
            int n = datos.Length;
            if (n % 2 == 0)
            {
                return (datos[n / 2 - 1] + datos[n / 2]) / 2.0;
            }
            else
            {
                return datos[n / 2];
            }
        }

        private int calcularModa(int[] datos)
        {
            var frecuencia = new System.Collections.Generic.Dictionary<int, int>();
            foreach (int num in datos)
            {
                if (frecuencia.ContainsKey(num))
                    frecuencia[num]++;
                else
                    frecuencia[num] = 1;
            }

            int moda = datos[0];
            int maxFrecuencia = 0;
            foreach (var item in frecuencia)
            {
                if (item.Value > maxFrecuencia)
                {
                    maxFrecuencia = item.Value;
                    moda = item.Key;
                }
            }

            return moda;
        }

        private double calcularDesviacionEstandar(int[] datos, double media)
        {
            double suma = 0;
            foreach (int num in datos)
            {
                suma += Math.Pow(num - media, 2);
            }
            return Math.Sqrt(suma / datos.Length);
        }

        private int calcularRango(int[] datos)
        {
            int min = int.MaxValue;
            int max = int.MinValue;
            foreach (int num in datos)
            {
                if (num < min) min = num;
                if (num > max) max = num;
            }
            return max - min;
        }

        private void txtCantidad_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
