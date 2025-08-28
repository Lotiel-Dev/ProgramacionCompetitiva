//1 Usando std::cin (forma básica)
#include <iostream>
#include <string>
using namespace std;

int main() {
    string texto;
    cout << "Ingresa un texto: ";
    cin >> texto; // Lee hasta el primer espacio
    
    cout << "Texto ingresado: " << texto << endl;
    return 0;
}




//2 Usando std::getline() (recomendado)

#include <iostream>
#include <string>
using namespace std;

int main() {
    string texto;
    cout << "Ingresa un texto: ";
    getline(cin, texto); // Lee toda la línea incluyendo espacios
    
    cout << "Texto completo: " << texto << endl;
    return 0;
}


//3 Combinando cin y getline()

#include <iostream>
#include <string>
using namespace std;

int main() {
    int edad;
    string nombre;
    
    cout << "Ingresa tu edad: ";
    cin >> edad;
    
    // Limpiar el buffer antes de usar getline
    cin.ignore(); 
    
    cout << "Ingresa tu nombre completo: ";
    getline(cin, nombre);
    
    cout << "Hola " << nombre << ", tienes " << edad << " años." << endl;
    return 0;
}


//4. Leyendo múltiples líneas

#include <iostream>
#include <string>
using namespace std;

int main() {
    string linea;
    cout << "Escribe varias líneas (termina con una línea vacía):" << endl;
    
    while (getline(cin, linea)) {
        if (linea.empty()) break; // Termina con línea vacía
        cout << "Leíste: " << linea << endl;
    }
    
    return 0;
}


//5. Con validación de entrada

#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    
    while (true) {
        cout << "Ingresa algo (mínimo 3 caracteres): ";
        getline(cin, input);
        
        if (input.length() >= 3) {
            break;
        }
        cout << "Muy corto. Intenta de nuevo." << endl;
    }
    
    cout << "Texto válido: " << input << endl;
    return 0;
}


//Recomendaciones:
//Usa getline(cin, variable) para leer textos con espacios
//Usa cin.ignore() después de usar cin >> antes de getline()
//Valida la entrada para evitar errores
//Incluye <string> para usar la clase string