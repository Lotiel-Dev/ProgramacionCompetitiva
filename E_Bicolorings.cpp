#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;

int memo[4][1002][2002];

// calc = calcular
// est_ant = estado anterior (0:WW, 1:WB, 2:BW, 3:BB)
// idx = índice actual
// comps_rest = componentes restantes
// tam = tamaño total
int calc(int est_ant, int idx, int comps_rest, int tam)
{
    if (comps_rest < 0) {
        return 0;
    }

    if (idx == tam) {
        return (comps_rest == 0) ? 1 : 0;
    }

    if (memo[est_ant][idx][comps_rest] != -1) {
        return memo[est_ant][idx][comps_rest];
    }

    int maneras = 0;

    if (est_ant == 0) // WW
    {
        maneras = (maneras + calc(0, idx + 1, comps_rest, tam)) % mod;     // -> WW
        maneras = (maneras + calc(1, idx + 1, comps_rest - 1, tam)) % mod; // -> WB
        maneras = (maneras + calc(2, idx + 1, comps_rest - 1, tam)) % mod; // -> BW
        maneras = (maneras + calc(3, idx + 1, comps_rest - 1, tam)) % mod; // -> BB
    }
    else if (est_ant == 1) // WB
    {
        maneras = (maneras + calc(0, idx + 1, comps_rest, tam)) % mod;     // -> WW
        maneras = (maneras + calc(1, idx + 1, comps_rest, tam)) % mod;     // -> WB
        maneras = (maneras + calc(2, idx + 1, comps_rest - 2, tam)) % mod; // -> BW
        maneras = (maneras + calc(3, idx + 1, comps_rest, tam)) % mod;     // -> BB
    }
    else if (est_ant == 2) // BW
    {
        maneras = (maneras + calc(0, idx + 1, comps_rest, tam)) % mod;     // -> WW
        maneras = (maneras + calc(1, idx + 1, comps_rest - 2, tam)) % mod; // -> WB
        maneras = (maneras + calc(2, idx + 1, comps_rest, tam)) % mod;     // -> BW
        maneras = (maneras + calc(3, idx + 1, comps_rest, tam)) % mod;     // -> BB
    }
    else // est_ant == 3 (BB)
    {
        maneras = (maneras + calc(0, idx + 1, comps_rest - 1, tam)) % mod; // -> WW
        maneras = (maneras + calc(1, idx + 1, comps_rest - 1, tam)) % mod; // -> WB
        maneras = (maneras + calc(2, idx + 1, comps_rest - 1, tam)) % mod; // -> BW
        maneras = (maneras + calc(3, idx + 1, comps_rest, tam)) % mod;     // -> BB
    }

    return memo[est_ant][idx][comps_rest] = maneras;
}

void resolver_caso()
{
    int tam, comps;
    cin >> tam >> comps;
    memset(memo, -1, sizeof(memo));

    int resp = 0;
    resp = (resp + calc(0, 1, comps - 1, tam)) % mod;
    resp = (resp + calc(1, 1, comps - 2, tam)) % mod;
    resp = (resp + calc(2, 1, comps - 2, tam)) % mod;
    resp = (resp + calc(3, 1, comps - 1, tam)) % mod;

    cout << resp << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    resolver_caso();

    return 0;
}