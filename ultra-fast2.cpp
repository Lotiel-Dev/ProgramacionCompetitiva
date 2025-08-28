#include <iostream>
#include <string>
#include <bitset>
using namespace std;


string toBinary(unsigned long long n) {
    if (n == 0){
        return "0";
    }else{
        if (n == 1){
            return "1";
        }else{
            return toBinary(n / 2) + to_string(n % 2);
        }
    }
}

//string toBinary(int n, int width) {
    //string binary;               
    //for (int i = width - 1; i >= 0; i--) {  
        //binary += ((n >> i) & 1) ? '1' : '0';  
    //}
    //return binary;               
//}

int main() {
    string val1;
    string val2;

    cin >> val1;
    cin >> val2;

    unsigned long long decimalVal1 = std::stoull(val1, nullptr, 2);
    unsigned long long decimalVal2 = std::stoull(val2, nullptr, 2);
    unsigned long long resultadoDecimal = decimalVal1 ^ decimalVal2;

    string resultado = toBinary(resultadoDecimal);
    if (resultado.length() == val1.length()){
        cout << resultado << "\n";
    }else{
        for (int i= val1.length() - resultado.length() ; i > 0 ; i--){
            resultado = "0" + resultado;
        }
        cout << resultado << "\n";
    }
    
    //cout << toBinary(resultado,val1.length()) << "\n";
    return 0;
}