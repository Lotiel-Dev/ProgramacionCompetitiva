#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimiza la velocidad de entrada y salida de datos.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numero_de_intervalos, divisor;
    cin >> numero_de_intervalos >> divisor;

    int posicion_actual = 1;
    int tiempo_total = 0;

    for (int i = 0; i < numero_de_intervalos; i++) {
        int inicio_intervalo, fin_intervalo;
        cin >> inicio_intervalo >> fin_intervalo;

        // Suma la duración del intervalo actual (ej: de 3 a 5, la duración es 5 - 3 + 1 = 3 minutos).
        tiempo_total += fin_intervalo - inicio_intervalo + 1;

        // Suma el tiempo de espera para llegar al inicio del intervalo.
        // Se calcula con el módulo del divisor.
        tiempo_total += (inicio_intervalo - posicion_actual) % divisor;

        // Actualiza la posición para el siguiente cálculo.
        posicion_actual = fin_intervalo + 1;
    }

    cout << tiempo_total << '\n';

    return 0;
}