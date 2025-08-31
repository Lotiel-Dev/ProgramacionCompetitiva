#include <iostream>
#include <vector>
using namespace std;

int main() {
    int Soldados;
    cin >> Soldados;
    vector<int> listSoldados(Soldados);
    
    for (int i = 0; i < Soldados; i++) {
        cin >> listSoldados[i];
    }
    

    int elMenor = Soldados - 1;
    for (int i = Soldados - 1; i >= 0; i--) {
        if (listSoldados[i] < listSoldados[elMenor]) {
            elMenor = i;
        }
    }
    

    int elMayor = 0;
    for (int i = 0; i < Soldados; i++) {
        if (listSoldados[i] > listSoldados[elMayor]) {
            elMayor = i;
        }
    }
    
    int respuesta;
    if (elMayor == 0 && elMenor == Soldados - 1) {
        respuesta = 0;
    } else if (elMenor > elMayor) {
        respuesta = elMayor + (Soldados - 1 - elMenor);
    } else {
        respuesta = elMayor + (Soldados - 1 - elMenor) - 1;
    }
    
    cout << respuesta << endl;
    return 0;
}