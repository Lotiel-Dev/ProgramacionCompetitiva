#include <iostream>
#include <vector>
using namespace std;

int main(){
    int testcasos;
    cin >> testcasos;
    vector<string> respuesta(testcasos);
    int numA;
    int numB;
    int numC;
    for (int i = 0; i < testcasos; i++){
        cin >> numA;
        cin >> numB;
        cin >> numC;
        if((numA + numB == numC) || (numA + numC == numB) || (numC + numB == numA)){
            respuesta [i] = "YES";
        }else{
            respuesta [i] = "NO";
        }

    }
    for (int i = 0; i < testcasos; i++){
        cout << respuesta[i] << "\n";
    }
    
    return 0;
}