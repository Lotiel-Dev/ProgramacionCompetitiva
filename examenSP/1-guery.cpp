#include <bits/stdc++.h>
using namespace std;

int cantidadVagones, largoTren;
string engancheLocomotora;
vector<string> enganchesVagones;
int cantidadTipo[4];
int maxTipo0, maxTipo1, maxTipo2, maxTipo3;
int engancheInicial, engancheFinal;
vector<long long> memo;

int obtenerIndice(int u0, int u1, int u2, int u3, int lado) {
    int id = (((u0 * maxTipo1 + u1) * maxTipo2 + u2) * maxTipo3 + u3) * 2 + lado;
    return id;
}

long long contarFormas(int usados0, int usados1, int usados2, int usados3, int ladoActual) {
    int usadosTotales = usados0 + usados1 + usados2 + usados3;
    if (usadosTotales == largoTren) return ladoActual == engancheFinal ? 1LL : 0LL;
    int id = obtenerIndice(usados0, usados1, usados2, usados3, ladoActual);
    if (memo[id] != -1) return memo[id];

    long long formas = 0;

    if (ladoActual == 0) {
        if (usados0 < cantidadTipo[0]) formas += contarFormas(usados0 + 1, usados1, usados2, usados3, 0);
        if (usados1 < cantidadTipo[1]) formas += contarFormas(usados0, usados1 + 1, usados2, usados3, 1);
    } else {
        if (usados2 < cantidadTipo[2]) formas += contarFormas(usados0, usados1, usados2 + 1, usados3, 0);
        if (usados3 < cantidadTipo[3]) formas += contarFormas(usados0, usados1, usados2, usados3 + 1, 1);
    }

    memo[id] = formas;
    return formas;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> cantidadVagones >> largoTren;
    cin >> engancheLocomotora;

    enganchesVagones.resize(cantidadVagones);
    for (int i = 0; i < cantidadVagones; i++) cin >> enganchesVagones[i];

    memset(cantidadTipo, 0, sizeof(cantidadTipo));

    for (auto &s : enganchesVagones) {
        if (s == "XX") cantidadTipo[0]++;
        else if (s == "XY") cantidadTipo[1]++;
        else if (s == "YX") cantidadTipo[2]++;
        else cantidadTipo[3]++;
    }

    maxTipo0 = cantidadTipo[0] + 1;
    maxTipo1 = cantidadTipo[1] + 1;
    maxTipo2 = cantidadTipo[2] + 1;
    maxTipo3 = cantidadTipo[3] + 1;

    int totalEstados = maxTipo0 * maxTipo1 * maxTipo2 * maxTipo3 * 2;
    memo.assign(totalEstados, -1);

    engancheInicial = (engancheLocomotora[1] == 'X') ? 0 : 1;
    engancheFinal = (engancheLocomotora[0] == 'X') ? 0 : 1;

    long long resultado = contarFormas(0, 0, 0, 0, engancheInicial);

    cout << resultado << "\n";
    return 0;
}