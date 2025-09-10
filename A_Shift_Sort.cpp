#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases,aux=0; cin >> testCases;
    int tamanio;
    string caso;
    string caso2;
    vector<int> resultado;

    while (testCases--){
        cin >> tamanio;
        cin >> caso;
        string ordenado = caso;  
        sort(ordenado.begin(), ordenado.end());
        if(caso == ordenado){
            resultado.push_back(0);
        }else{
            if(caso[tamanio-1] == '0'){
                for (int i = tamanio - 1; i > 0; i--){
                    if(caso[i] == '0'){
                        aux++;
                    }else{
                            break;
                    }
                
                }
                //cout << "aquisito " << aux<< endl;
                resultado.push_back(aux);
                aux = 0;

            }else{
                for (int i = tamanio - 1; i > 0; i--){
                    //cout << "haber " << caso[i] << endl;
                    if(caso[i] == '0'){
                        aux++;
                        //break;
                    }else{
                        if(caso[i-1] == '0' && caso[i-2] == '1'){
                            aux++;
                            break;
                        }
                    }
                    
                }
                //cout << "aquisito " << aux<< endl;
                resultado.push_back(aux);
                aux = 0;
            }
            
        
        }
    }
    for (int i : resultado){
        cout << i << endl;
    }
    

    return 0;
}