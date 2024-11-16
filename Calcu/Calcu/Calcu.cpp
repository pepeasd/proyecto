#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

double calcularMedia(const vector<int>& datos) {
    int suma = 0;
    int n = datos.size();

    __asm {
        xor ecx, ecx; ECX = 0, contador
        xor eax, eax; EAX = 0, acumulador
        xor edx, edx; EDX = 0, acumulador temporal

        loop_start :
        mov edx, datos[ecx * 4]; ; Cargar datos[ecx] en EDX
            add eax, edx; EAX += datos[ecx]
            inc ecx; ECX++
            cmp ecx, n; Comparar ECX con n
            jl loop_start; Si ECX < n, repetir

            mov suma, eax; Guardar resultado en suma
    }
    return static_cast<double>(suma) / n; 
}

double calcularMediana(vector<int> datos) {
    int n = datos.size();
    __asm {
        xor ecx, ecx; ECX = 0 
        xor edx, edx; EDX = 0 
        sort_start:
        mov eax, datos[ecx * 4]; 
            cmp eax, datos[ecx * 4 + 4]; 
            jg swap_elements; 
            inc ecx; ECX++
            cmp ecx, n - 1; 
            jl sort_start; 
            jmp done_sort

            swap_elements :
        mov ebx, datos[ecx * 4]; ; Cargar datos[ecx] en EBX
            mov edx, datos[ecx * 4 + 4]; ; Cargar datos[ecx + 1] en EDX
            mov datos[ecx * 4], edx; Intercambiar datos[ecx] con datos[ecx + 1]
            mov datos[ecx * 4 + 4], ebx; Intercambiar datos[ecx + 1] con datos[ecx]

            inc ecx
            cmp ecx, n - 1
            jl sort_start
            done_sort :

        ; Cálculo de la mediana
            mov eax, n; Cargar n
            and eax, 1; Verificar si n es impar o par
            jz even_size; Si es par, saltar a even_size

            ; Si es impar
            mov eax, datos[n / 2]; Tomar el elemento central
            jmp done_mediana

            even_size :
        ; Si es par
            mov eax, datos[n / 2 - 1]; Tomar el promedio de los dos elementos centrales
            add eax, datos[n / 2]
            sar eax, 1; Dividir entre 2
            done_mediana:
    }
    return static_cast<double>(eax);
}

int calcularModa(const vector<int>& datos) {
    map<int, int> frecuencia;
    for (int num : datos) frecuencia[num]++;

    int moda = datos[0];
    int maxFrecuencia = 0;

    for (const auto& par : frecuencia) {
        __asm {
            mov eax, par.second; Cargar frecuencia en EAX
            cmp eax, maxFrecuencia; Comparar con la máxima frecuencia
            jle skip_update; Si es menor o igual, saltar
            mov maxFrecuencia, eax; Actualizar maxFrecuencia
            mov eax, par.first; Cargar el número
            mov moda, eax; Actualizar moda
            skip_update :
        }
    }

    return moda;
}

int calcularRango(const vector<int>& datos) {
    int min = datos[0];
    int max = datos[0];

    __asm {
        xor ecx, ecx; ECX = 0
        mov eax, datos[ecx * 4]; Cargar datos[0] en EAX
        mov min, eax; Asignar min = datos[0]
        mov max, eax; Asignar max = datos[0]

        loop_start:
        mov eax, datos[ecx * 4]; Cargar datos[ecx] en EAX
            cmp eax, min; Comparar con min
            jge skip_min_update
            mov min, eax; Actualizar min
            skip_min_update :

        cmp eax, max; Comparar con max
            jle skip_max_update
            mov max, eax; Actualizar max
            skip_max_update :

        inc ecx; ECX++
            cmp ecx, datos.size(); Comparar ECX con el tamaño de datos
            jl loop_start; Si ECX < tamaño, continuar
    }

    return max - min; 
}
double calcularDesviacionEstandar(const vector<int>& datos, double media) {
    double suma = 0;
    for (int num : datos) {
        suma += pow(num - media, 2);
    }
    return sqrt(suma / datos.size());
}

int main() {
    int cantidad;
    cout << "Ingrese la cantidad de numeros: ";
    cin >> cantidad;

    vector<int> datos(cantidad);
    cout << "Ingrese los numeros:" << endl;
    for (int i = 0; i < cantidad; ++i) cin >> datos[i];

    double media = calcularMedia(datos);
    double mediana = calcularMediana(datos);
    int moda = calcularModa(datos);
    double desviacionEstandar = calcularDesviacionEstandar(datos, media);
    int rango = calcularRango(datos);

    cout << "Media: " << media << endl;
    cout << "Mediana: " << mediana << endl;
    cout << "Moda: " << moda << endl;
    cout << "Desviación estandar: " << desviacionEstandar << endl;
    cout << "Rango: " << rango << endl;

    return 0;
}