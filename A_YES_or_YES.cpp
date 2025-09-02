#include <iostream>
#include <vector>
using namespace std;

int main(){
    int casos;
    string cadenaAux;
    cin >> casos;
    vector<string> testcasos(casos);
    vector<string> respues(casos);

    for (int i = 0; i < casos; i++){
        cin >> testcasos[i];
    }

    for (int i = 0; i < casos; i++){
        cadenaAux = testcasos[i];
        if ((cadenaAux[0] == 'Y' || cadenaAux[0]== 'y') && (cadenaAux[1] == 'e' || cadenaAux[1]=='E') && (cadenaAux[2] == 's' || cadenaAux[2]=='S'))
        {
            respues[i] = "YES";
        }else{
            respues[i] = "NO";
        }
    }
    for (int i = 0; i < casos; i++)
    {
        cout << respues[i] << "\n";
    }
    return 0;
}