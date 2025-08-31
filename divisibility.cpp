#include <iostream>
#include <vector>
using namespace std;

int main(){
    int testCasos;
    int limiteCasos = 0;

    cin >> testCasos;       
    vector<int> casos(testCasos*2);

    for (int i = 0; i < testCasos*2; i++){
        cin >> casos[i];
    }


    while(limiteCasos < (casos.size() -1) ){
        int a = casos[limiteCasos];
        int b = casos[limiteCasos + 1];

        if((a%b) == 0){
            cout << "0" << "\n";
        }else{
            if (a<b){
                cout << b - a << "\n";
            }else{
                cout << b - (a%b) << "\n";
            }
        }
        limiteCasos += 2;
    }
    return 0;
    
}
