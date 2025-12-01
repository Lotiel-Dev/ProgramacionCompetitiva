#include <bits/stdc++.h>
using namespace std;

string cadena;
int n;
vector<int> rankActual, rankTemp;
vector<int> sufArr, sufTemp;
vector<int> conteo;
vector<int> LCP, PLCP;

void countingSort(int k) {
    long long maxVal = max(300, n);
    conteo.assign(maxVal, 0);

    for (int i = 0; i < n; i++)
        conteo[i + k < n ? rankActual[i + k] : 0]++;

    for (int i = 0, sum = 0; i < maxVal; i++) {
        int tmp = conteo[i];
        conteo[i] = sum;
        sum += tmp;
    }

    for (int i = 0; i < n; i++) {
        if (sufArr[i] + k < n)
            sufTemp[conteo[rankActual[sufArr[i] + k]]++] = sufArr[i];
        else
            sufTemp[conteo[0]++] = sufArr[i];
    }

    for (int i = 0; i < n; i++)
        sufArr[i] = sufTemp[i];
}

void construirSA() {
    rankActual.assign(n, 0);
    rankTemp.assign(n, 0);
    sufArr.assign(n, 0);
    sufTemp.assign(n, 0);

    for (int i = 0; i < n; i++) rankActual[i] = cadena[i];
    for (int i = 0; i < n; i++) sufArr[i] = i;

    for (int k = 1; k < n; k <<= 1) {
        countingSort(k);
        countingSort(0);

        int r = 0;
        rankTemp[sufArr[0]] = 0;

        for (int i = 1; i < n; i++) {
            if (rankActual[sufArr[i]] == rankActual[sufArr[i - 1]] &&
                rankActual[sufArr[i] + k] == rankActual[sufArr[i - 1] + k])
                rankTemp[sufArr[i]] = r;
            else
                rankTemp[sufArr[i]] = ++r;
        }

        for (int i = 0; i < n; i++)
            rankActual[i] = rankTemp[i];

        if (rankActual[sufArr[n - 1]] == n - 1) break;
    }
}

void calcularLCP() {
    LCP.assign(n, 0);
    PLCP.assign(n, 0);
    vector<int> sufAnterior(n, -1);

    for (int i = 1; i < n; i++)
        sufAnterior[sufArr[i]] = sufArr[i - 1];

    for (int i = 0, L = 0; i < n; i++) {
        if (sufAnterior[i] == -1) {
            PLCP[i] = 0;
            continue;
        }
        while (i + L < n && sufAnterior[i] + L < n &&
               cadena[i + L] == cadena[sufAnterior[i] + L] &&
               cadena[i + L] != '$')
            L++;
        PLCP[i] = L;
        if (L) L--;
    }

    for (int i = 0; i < n; i++)
        LCP[i] = PLCP[sufArr[i]];
}

int main() {
    int t;
    bool primero = true;

    while (scanf("%d", &t), t != 0) {
        if (!primero) cout << endl;
        primero = false;

        cadena = "";
        string entrada;
        vector<int> propietario;

        for (int i = 0; i < t; i++) {
            cin >> entrada;
            cadena += entrada;
            cadena += "$";
            while (propietario.size() < cadena.length())
                propietario.push_back(i);
        }

        n = cadena.length();

        construirSA();
        calcularLCP();

        int mejorLCP = 0;
        int distintos = 0;
        vector<int> indicesLCS;
        vector<int> contadorProp(t);
        int low = t, high = t;

        while (high < n) {
            if (distintos <= t / 2) {
                int dueño = propietario[sufArr[high]];
                if (contadorProp[dueño]++ == 0)
                    distintos++;
                high++;
            } else {
                int minimo = INT_MAX, pos = low + 1;
                for (int i = low + 1; i < high; i++) {
                    if (LCP[i] < minimo) {
                        minimo = LCP[i];
                        pos = i;
                    }
                }

                if (LCP[pos] > mejorLCP) {
                    mejorLCP = LCP[pos];
                    indicesLCS.clear();
                }
                if (LCP[pos] == mejorLCP)
                    indicesLCS.push_back(pos);

                int dueño = propietario[sufArr[low]];
                if (--contadorProp[dueño] == 0)
                    distintos--;
                low++;
            }
        }

        if (mejorLCP == 0) {
            cout << "?" << endl;
        } else {
            string previo = "";
            for (int idx : indicesLCS) {
                string actual = cadena.substr(sufArr[idx], mejorLCP);
                if (actual == previo) continue;
                previo = actual;
                cout << actual << endl;
            }
        }
    }
}
