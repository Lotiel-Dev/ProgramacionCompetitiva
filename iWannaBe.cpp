#include <iostream>
#include <vector>
#include <string>



// ---- Nueva función para imprimir vectores ----
void imprimirVector(const std::vector<int>& vec, const std::string& nombre = "Vector") {
    std::cout << nombre << ": ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}




int main(){
        int levelmax;
        std::string resultado = "I become the guy.";
        std::cin>> levelmax;

        std::vector<int> levels(levelmax,-1);

        int x;
        std:: cin>> x;
        for(int i=0 ; i < x; i++){
            int a;
            std::cin>>a;
            levels[a-1]=a;
        }

        int z;
        std:: cin>>z;
        for(int i=0; i<z;i++){
            int b;
            std::cin>>b;
            levels[b-1]=b;
        }
        for(int c = 0 ; c < levelmax ; c++){
            if(levels[c] == -1){
                resultado= "Oh, my keyboard!";
            }
        }

        // Llamada a la función para imprimir el vector
        imprimirVector(levels, "Levels");

        std:: cout<< resultado << "\n";
        return 0;
}