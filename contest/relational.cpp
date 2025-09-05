#include <bits/stdc++.h>
using namespace std;

int main(){

    int a;
    cin >> a; 
    vector<string> resultado(a); 
    for (int i = 0; i < a; i++)
    {
        int b,c;
        cin >> b >> c;

        if(b>c){
            resultado[i] = ">";
        }else{
            if(b<c){
                resultado[i] = "<";
            }else{
                resultado[i] = "=";
                
            }
        }
    }
    for (int i = 0; i < a; i++)
    {
        cout << resultado[i] << "\n";  
    }
    
    
    return 0;
}