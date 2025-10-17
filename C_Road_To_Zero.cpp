#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long casos;
    cin >> casos;

    while (casos--) {
        long long x, y, costo_ind, costo_comb; // costo individual, costo combinado/diagonal
        cin >> x >> y >> costo_ind >> costo_comb;

        long long res = 0;

        // Comprueba si es más barato mover siempre individualmente.
        if (2 * costo_ind <= costo_comb) {
            // Si dos movimientos individuales son más baratos o iguales que uno diagonal,
            // nunca usamos el movimiento diagonal.
            res = costo_ind * (x + y);
        } else {
            // Si es más barato usar movimientos diagonales, los maximizamos.
            long long min_coord = std::min(x, y);
            long long max_coord = std::max(x, y);

            // Costo de los movimientos diagonales para llegar a (min_coord, min_coord)
            res = min_coord * costo_comb;
            
            // Costo de los movimientos individuales restantes para cubrir la distancia que falta.
            res += (max_coord - min_coord) * costo_ind;
        }

        cout << res << "\n";
    }

    return 0;
}