//En resumen: stoll sirve para convertir cadenas en enteros largos (long long)
//de manera segura y controlando base numérica.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "12345";
    string s2 = "1010";
    
    long long num1 = stoll(s1);            // base 10 -> 12345
    long long num2 = stoll(s2, nullptr, 2); // base 2 -> 10

    cout << num1 << endl;  // 12345
    cout << num2 << endl;  // 10

    return 0;
}

//otro para manejar enteros y convertir en string

        ll a,b=0;
        cin >> a;
        int d = to_string(a).size();

        for(int i = 1; i <= (int)pow(10,d); i++)