//https://codeforces.com/problemset/problem/2135/F
//https://codeforces.com/contest/2135/submission/336882135
#include <bits/stdc++.h>
#define in(x) freopen(#x".in","r",stdin)
#define out(x) freopen(#x".out","w",stdout)
#define make(x) freopen(#x".in","w",stdout)
#define ll long long
#define int long long
#define ui unsigned int
#ifdef MY_COMPUTER
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#define _GLIBCXX_DEBUG
#else
#define debug(...) void(0)
#endif
#define vector basic_string
#define pii array<int,2>

using namespace std;

inline int leer()
{
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*f;
}

template<typename _it>
void leer(_it a,_it b){
    while(a!=b) (*a)=leer(),a++;
}
template<typename _it>
void escribir(const char* form,_it a,_it b,int op=0){
    while(a!=b) printf(form,*a),a++;
    if(op) puts("");
}

int t, n;
int hijo_izq[400010], hijo_der[400010], grado_entrada[400010];
int contador_nodos, rango[400010], padre[400010], raiz_arbol[400010];
ui hash_valor[400010];
mt19937_64 GeneradorAleatorio(chrono::system_clock::now().time_since_epoch().count());
const ui constante_magica = GeneradorAleatorio();

// Función para generar valores hash únicos
ui generar_hash(ui x) {
    x ^= constante_magica;
    x ^= x << 9;
    x ^= x >> 4;
    x ^= x << 13;
    x ^= constante_magica;
    return x;
}

// Variables para el árbol de segmentos persistente
int contador_segmentos;
int tamaño[10000010], hijo_izq_seg[10000010], hijo_der_seg[10000010];
ui suma_hash[10000010];

// Añadir un nodo al árbol de segmentos persistente
void añadir_nodo(int &id, int l, int r, int x, ui valor_hash) {
    ++contador_segmentos;
    hijo_izq_seg[contador_segmentos] = hijo_izq_seg[id];
    hijo_der_seg[contador_segmentos] = hijo_der_seg[id];
    tamaño[contador_segmentos] = tamaño[id];
    suma_hash[contador_segmentos] = suma_hash[id];
    id = contador_segmentos;
    
    tamaño[id]++;
    suma_hash[id] += valor_hash;
    
    if(l == r) return;
    
    int medio = l + r >> 1;
    if(x <= medio) 
        añadir_nodo(hijo_izq_seg[id], l, medio, x, valor_hash);
    else 
        añadir_nodo(hijo_der_seg[id], medio+1, r, x, valor_hash);
}

// Comparar dos árboles de segmentos
int comparar_arboles(int p, int q, int l, int r) {
    if(l == r) return tamaño[p] > tamaño[q];
    
    int medio = l + r >> 1;
    if(suma_hash[hijo_der_seg[p]] == suma_hash[hijo_der_seg[q]]) 
        return comparar_arboles(hijo_izq_seg[p], hijo_izq_seg[q], l, medio);
    
    return comparar_arboles(hijo_der_seg[p], hijo_der_seg[q], medio+1, r);
}

// Estructura para comparar nodos en la cola de prioridad
struct Nodo {
    int id;
    Nodo(int x) : id(x) {}
    bool operator <(const Nodo otro) const {
        if(hash_valor[id] == hash_valor[otro.id])
            return id > otro.id;
        return comparar_arboles(raiz_arbol[id], raiz_arbol[otro.id], 1, n);
    }
};

priority_queue<Nodo> cola_prioridad;

// Procesar un nodo y añadirlo a la cola
void procesar_nodo(int u) {
    // Calcular hash combinando los hashes de los hijos
    hash_valor[u] = hash_valor[hijo_izq[u]] + generar_hash(hash_valor[hijo_der[u]]);
    
    // Construir árbol de segmentos persistente
    añadir_nodo(raiz_arbol[u] = raiz_arbol[hijo_izq[u]], 1, n, rango[hijo_der[u]], generar_hash(hash_valor[hijo_der[u]]));
    
    cola_prioridad.push(u);
}

signed main()
{
    t = leer();
    while(t--) {
        n = leer();
        contador_segmentos = contador_nodos = 0;
        
        // Inicializar arrays
        for(int i = 1; i <= n; i++) {
            raiz_arbol[i] = grado_entrada[i] = hash_valor[i] = padre[i] = 0;
        }
        
        // Leer entrada: árbol binario
        for(int i = 1; i <= n; i++) {
            hijo_izq[i] = leer();
            hijo_der[i] = leer();
            
            // Calcular grado de entrada (número de padres que referencian este nodo)
            grado_entrada[i] = (hijo_izq[i] != 0) + (hijo_der[i] != 0);
            
            // Establecer padres de los hijos
            if(hijo_izq[i]) padre[hijo_izq[i]] = i;
            if(hijo_der[i]) padre[hijo_der[i]] = i;
        }
        
        // Añadir hojas (nodos sin hijos) a la cola
        for(int i = 1; i <= n; i++) {
            if(grado_entrada[i] == 0) {
                hash_valor[i] = 1;
                cola_prioridad.push(i);
            }
        }
        
        int ultimo_procesado = 0;
        vector<int> resultado;
        
        // Procesamiento topológico
        while(!cola_prioridad.empty()) {
            int u = cola_prioridad.top().id;
            cola_prioridad.pop();
            
            // Asignar rango único si el hash cambió
            if(hash_valor[u] != hash_valor[ultimo_procesado]) 
                contador_nodos++;
            
            rango[ultimo_procesado = u] = contador_nodos;
            resultado.push_back(u);
            
            // Reducir grado de entrada del padre y procesarlo si está listo
            if(padre[u] && --grado_entrada[padre[u]] == 0) 
                procesar_nodo(padre[u]);
        }
        
        // Imprimir resultado (orden topológico)
        for(int nodo : resultado) 
            printf("%lld ", nodo);
        puts("");
    }
    return 0;
}