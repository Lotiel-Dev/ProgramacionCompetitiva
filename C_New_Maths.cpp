//////////////////////////////////////FUNCIONAL PERO DA TIME LIMITED ///////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

string mul_no_carry_base10(const string &sa, const string &sb) {
    int n = sa.size(), m = sb.size();
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) a[n-1-i] = sa[i]-'0';
    for (int j = 0; j < m; ++j) b[m-1-j] = sb[j]-'0';
    vector<int> res(n + m, 0);
    for (int i = 0; i < n; ++i) {
        if (!a[i]) continue;
        for (int j = 0; j < m; ++j) {
            if (!b[j]) continue;
            res[i+j] = (res[i+j] + a[i]*b[j]) % 10;
        }
    }

    
    int k = n + m - 1;
    while (k > 0 && res[k] == 0) --k;
    string out;
    for (int t = k; t >= 0; --t) out.push_back(char('0' + res[t]));
    return out;
}

int main() {
    int inicio,fin;
    string a; cin >> a;
    string aux = "-1"; 

    if(stoll(a)<999){
        inicio = 1;
        fin = 99;
    }else{
        int m = a.size();
        inicio = pow(10,m/2);
        fin = pow(10,(m/2)+1);
    }

    //cout << "Inicio: "<<inicio << endl;
    //cout << "Fin: "<< fin << endl;


    for (long long i = inicio; i < fin; i++){
        string multi = mul_no_carry_base10(to_string(i),to_string(i));

        if(multi == a){
            //cout << i << endl;
            aux = to_string(i);
            break;
        }
    }
    
    
    cout << aux << "\n";
}


///////////////////////////////////////////////OPTIMIZACION POR EL STOLL COCHINO QUE  SOLO RECIBE HASTA 18 DIGITOS///////////////////////
///////////////////////////////////////////////IGUAL DA TIME LIMITID////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

string mul_no_carry_base10(const string &sa, const string &sb) {
    int n = sa.size(), m = sb.size();
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) a[n-1-i] = sa[i]-'0';
    for (int j = 0; j < m; ++j) b[m-1-j] = sb[j]-'0';
    vector<int> res(n + m, 0);
    for (int i = 0; i < n; ++i) {
        if (!a[i]) continue;
        for (int j = 0; j < m; ++j) {
            if (!b[j]) continue;
            res[i+j] = (res[i+j] + a[i]*b[j]) % 10;
        }
    }

    
    int k = n + m - 1;
    while (k > 0 && res[k] == 0) --k;
    string out;
    for (int t = k; t >= 0; --t) out.push_back(char('0' + res[t]));
    return out;
}


int cmp_strnum(const string &a, const string &b) {
    if (a.size() != b.size()) return (a.size() < b.size() ? -1 : 1);
    if (a == b) return 0;
    return (a < b ? -1 : 1);
}


string pow10_str(int k) {
    string s = "1";
    s.append(k, '0');
    return s;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string inicio,fin;
    string a; cin >> a;
    string aux = "-1"; 

    if(cmp_strnum(a, "999") <= 0){
        inicio = "1";
        fin = "99";
    }else{
        int m = a.size();
        inicio = pow10_str(m/2);
        fin = pow10_str((m/2)+1);
    }

    long long ini = stoll(inicio);
    long long f = stoll(fin);

    //cout << "Inicio: "<<inicio << endl;
    //cout << "Fin: "<< fin << endl;


    if(a.size()%2 == 0){
        cout << aux << "\n";
        return 0;
    }else{
        for (long long i = ini; i < f; i++){
            string multi = mul_no_carry_base10(to_string(i),to_string(i));

            if(multi == a){
                //cout << i << endl;
                aux = to_string(i);
                break;
            }
        }
        cout << aux << "\n";
    }

    
}




////////////////////////////////////////////////FUNCIONA AL 100%/////////////////////////////////////////////////////////////////////////



#include <bits/stdc++.h>
using namespace std;

/*
  Encuentra el mínimo a (en valor decimal) tal que a ⊗ a = N,
  donde ⊗ es la multiplicación por convolución de dígitos sin acarreo:
  (c_k = sum_{i=0}^k a_i * a_{k-i} mod 10).

  Entrada: una línea con N (cadena decimal, sin signo).
  Salida: el menor a que satisface la ecuación, o -1 si no existe.
*/

string normalize_no_leading(const string &s) {
    // quita ceros a la izquierda; si queda vacío, retorna "0"
    size_t i = 0;
    while (i < s.size() && s[i] == '0') ++i;
    if (i == s.size()) return "0";
    return s.substr(i);
}

int toInt(char c){ return c - '0'; }
char toChar(int d){ return char('0' + d); }

// compara dos números en forma de string decimal sin signos y sin ceros iniciales
// devuelve true si a < b (numéricamente)
bool less_strnum(const string &a, const string &b){
    string A = normalize_no_leading(a);
    string B = normalize_no_leading(b);
    if (A.size() != B.size()) return A.size() < B.size();
    return A < B;
}

// calcula c = a ⊗ a (convolution mod 10), devuelve string de dígitos con msd primero (sin ceros iniciales salvo "0")
string conv_square_to_string(const vector<int> &a) {
    int k = (int)a.size();
    int maxc = 2*k - 1;
    vector<int> c(maxc, 0);
    for (int i = 0; i < k; ++i){
        for (int j = 0; j < k; ++j){
            c[i+j] = (c[i+j] + a[i]*a[j]) % 10;
        }
    }
    // convertir c (LSB en índice 0) a string msd..lsd y normalizar
    int last = maxc-1;
    while (last > 0 && c[last] == 0) --last;
    string s;
    for (int i = last; i >= 0; --i) s.push_back(toChar(c[i]));
    return normalize_no_leading(s);
}

string Nstr;
vector<int> Ndig; // Ndig[i] = dígito en posición i (LSB = 0)
int l, k;
string best = ""; // mejor solución encontrada (numérica, msd..lsd)

vector<int> a_digits; // a_digits[pos] where pos=0 es LSB

// Comprueba si rellenando los dígitos más significativos (pos+1..k-1) con ceros
// ya no podemos mejorar best. Devuelve true si se puede podar.
bool prune_by_bound(int pos) {
    if (best.empty()) return false;
    // construir número mínimo posible de la rama actual:
    // msd..lsd: indices k-1 .. 0
    string cand;
    // msd.. (pos+1..k-1) unknown -> asumo 0 para minimizar
    for (int i = k-1; i >= pos+1; --i) cand.push_back('0');
    // luego los dígitos conocidos desde pos..0
    for (int i = pos; i >= 0; --i) cand.push_back(toChar(a_digits[i]));
    cand = normalize_no_leading(cand);
    // comparar cand >= best -> no mejora posible -> podar
    if (!less_strnum(cand, best)) return true;
    return false;
}

void dfs(int pos) {
    if (pos == k) {
        // tenemos todos los dígitos candidate de a (0..k-1). Verificar conv.
        string conv = conv_square_to_string(a_digits);
        string Nnorm = normalize_no_leading(Nstr);
        if (conv == Nnorm) {
            // formar número a en forma msd..lsd sin ceros iniciales
            string astr;
            for (int i = k-1; i >= 0; --i) astr.push_back(toChar(a_digits[i]));
            astr = normalize_no_leading(astr);
            if (best.empty() || less_strnum(astr, best)) best = astr;
        }
        return;
    }

    if (pos == 0) {
        // elegir a0: a0^2 % 10 == Ndig[0]
        int target = (Ndig.size() > 0 ? Ndig[0] : 0);
        vector<int> cand;
        for (int d = 0; d <= 9; ++d){
            if ((d*d) % 10 == target) cand.push_back(d);
        }
        sort(cand.begin(), cand.end());
        for (int d : cand) {
            a_digits[0] = d;
            // poda
            if (prune_by_bound(0)) continue;
            dfs(1);
        }
    } else {
        // calcular M_pos = sum_{i=1}^{pos-1} a_i * a_{pos-i} mod 10
        int M = 0;
        for (int i = 1; i <= pos-1; ++i) {
            M = (M + a_digits[i] * a_digits[pos - i]) % 10;
        }
        int target = (pos < (int)Ndig.size() ? Ndig[pos] : 0);
        int rhs = (target - M) % 10;
        if (rhs < 0) rhs += 10;
        int A = (2 * a_digits[0]) % 10; // coeficiente multiplicando a_pos
        vector<int> cand;
        if (A == 0) {
            // 0 * x ≡ rhs (mod 10) => sólo posible si rhs == 0 => cualquier x 0..9
            if (rhs == 0) {
                for (int x = 0; x <= 9; ++x) cand.push_back(x);
            } // else no solución en este camino
        } else {
            // probar x = 0..9
            for (int x = 0; x <= 9; ++x) {
                if ((A * x) % 10 == rhs) cand.push_back(x);
            }
        }
        sort(cand.begin(), cand.end());
        for (int x : cand) {
            a_digits[pos] = x;
            if (prune_by_bound(pos)) continue;
            dfs(pos+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> Nstr)) return 0;
    Nstr = normalize_no_leading(Nstr);
    // construir Ndig (LSB first)
    l = (int)Nstr.size();
    Ndig.clear();
    for (int i = l-1; i >= 0; --i) Ndig.push_back(toInt(Nstr[i]));
    // longitud de a en dígitos
    k = (l + 1) / 2; // ceil(l/2)
    a_digits.assign(k, 0);
    best = "";

    // iniciar DFS
    dfs(0);

    if (best.empty()) cout << "-1\n";
    else cout << best << "\n";
    return 0;
}


////////////////////////////////////////////////MAS CORTO////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

string N;
int L, K;
vector<int> n;      // dígitos de N, n[0] = LSD
vector<int> a;      // dígitos de a (LSD-first), longitud K
string best = "";   // mejor solución (msd-first), vacía si no hay
bool any_found = false;

string build_string_from_digits(const vector<int>& v) {
    // v es LSD-first; convertir a msd-first string, sin ceros a la izquierda
    string s;
    for (int i = (int)v.size()-1; i >= 0; --i) s.push_back(char('0' + v[i]));
    return s;
}

bool full_check_and_accept() {
    // calcula convolución carryless de a con a y compara con n
    vector<int> res(2*K, 0);
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            res[i+j] = (res[i+j] + a[i]*a[j]) % 10;
        }
    }
    // Ajustar longitud: N tiene L = 2*K - 1 (porque L es impar)
    for (int t = 0; t < L; ++t) {
        if (res[t] != n[t]) return false;
    }
    // no puede tener ceros a la izquierda (msd no debe ser 0)
    if (a[K-1] == 0) return false;
    string cand = build_string_from_digits(a);
    if (!any_found || cand < best) {
        best = cand;
        any_found = true;
    }
    return true;
}

void dfs(int t, const vector<char>& allowed_msd) {
    if (t == K) {
        full_check_and_accept();
        return;
    }

    // Calculamos S = sum_{i=1..t-1} a[i]*a[t-i]  (mod 10)
    int S = 0;
    for (int i = 1; i <= t-1; ++i) S = (S + a[i]*a[t-i]) % 10;

    int coef = (2 * a[0]) % 10;                   // coeficiente multiplicando a_t
    int rhs = (n[t] - S) % 10; if (rhs < 0) rhs += 10;

    vector<int> candidates;
    if (coef == 0) {
        // ecuación 0 * a_t ≡ rhs (mod 10) -> si rhs != 0 no hay solución
        if (rhs != 0) return;
        // si rhs == 0, cualquier dígito 0..9 es candidato
        candidates.reserve(10);
        for (int d = 0; d <= 9; ++d) candidates.push_back(d);
    } else {
        // probar 0..9 para soluciones de coef * x % 10 == rhs
        for (int d = 0; d <= 9; ++d) if ((coef * d) % 10 == rhs) candidates.push_back(d);
    }

    // Si estamos en la última posición (más significativa), aplicar restricciones:
    // - no puede ser 0
    // - debe cumplir a_k*a_k %10 == n[2k] (c_{2k})
    if (t == K-1) {
        vector<int> tmp;
        tmp.reserve(candidates.size());
        for (int d : candidates) {
            if (d == 0) continue;                      // sin ceros a la izquierda
            if (!allowed_msd.empty() && !allowed_msd[d]) continue;
            tmp.push_back(d);
        }
        candidates.swap(tmp);
    }

    // Explorar candidatos (orden natural 0..9). Número de candidatos por posición es muy pequeño.
    for (int d : candidates) {
        a[t] = d;
        dfs(t+1, allowed_msd);
        // opcional: si quieres parar al primer hallazgo (no siempre el mínimo), puedes:
        // if (any_found) return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> N)) return 0;

    L = (int)N.size();
    if (L % 2 == 0) { cout << "-1\n"; return 0; }
    K = (L + 1) / 2;

    // llenar n[] con dígitos LSD-first
    n.assign(L, 0);
    for (int i = 0; i < L; ++i) n[i] = N[L-1-i] - '0';

    // precomputar candidatos para a_0: d^2 %10 == n[0]
    vector<int> a0_cands;
    for (int d = 0; d <= 9; ++d) if ((d*d) % 10 == n[0]) a0_cands.push_back(d);
    if (a0_cands.empty()) { cout << "-1\n"; return 0; }

    // precomputar conjunto permitido para el MSD a_{K-1} según n[2k] (c_{2k} = a_k*a_k %10)
    vector<char> allowed_msd(10, 0);
    int top_digit = n[2*K - 2 + 1 - 1]; // careful: but simpler compute index 2k = L-1
    // actually 2k = L-1
    int idx_2k = L - 1;
    for (int d = 0; d <= 9; ++d) if ((d*d) % 10 == n[idx_2k]) allowed_msd[d] = 1;

    a.assign(K, 0);

    // Para cada candidato de a0, hacemos DFS construyendo los demás dígitos
    for (int d0 : a0_cands) {
        a[0] = d0;
        // Si K == 1 (N tiene 1 dígito), entonces a has only a0; validar inmediatamente:
        if (K == 1) {
            // verificar a0*a0 %10 == n[0], ya lo cumple por construcción, pero verificar full
            if ((d0*d0) % 10 == n[0]) {
                // pero también check no-leading-zero: single digit can't be 0 unless N is 0 (N>0)
                if (d0 != 0) {
                    string s(1, char('0' + d0));
                    if (!any_found || s < best) { best = s; any_found = true; }
                }
            }
            continue;
        }
        dfs(1, allowed_msd);
        // Nota: no rompemos aquí porque puede haber varias soluciones con distintos a0.
    }

    if (!any_found) cout << "-1\n";
    else cout << best << "\n";
    return 0;
}


//////////////////////////////////////////////////EN ESPANIOL DEL PRIMER 100%/////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

// Normaliza un número eliminando ceros a la izquierda
string normalizar_sin_ceros_izquierda(const string &s) {
    size_t i = 0;
    while (i < s.size() && s[i] == '0') ++i;
    if (i == s.size()) return "0";
    return s.substr(i);
}

// Convierte carácter a entero
int aEntero(char c){ return c - '0'; }

// Convierte entero a carácter
char aCaracter(int d){ return char('0' + d); }

// Compara dos números representados como cadenas
bool menor_numero_cadena(const string &a, const string &b){
    string A = normalizar_sin_ceros_izquierda(a);
    string B = normalizar_sin_ceros_izquierda(b);
    if (A.size() != B.size()) return A.size() < B.size();
    return A < B;
}

// Convierte el cuadrado de un número (representado como dígitos) a cadena
string convertir_cuadrado_a_cadena(const vector<int> &a) {
    int k = (int)a.size();
    int maxc = 2*k - 1;
    vector<int> c(maxc, 0);
    for (int i = 0; i < k; ++i){
        for (int j = 0; j < k; ++j){
            c[i+j] = (c[i+j] + a[i]*a[j]) % 10;
        }
    }
    int ultimo = maxc-1;
    while (ultimo > 0 && c[ultimo] == 0) --ultimo;
    string s;
    for (int i = ultimo; i >= 0; --i) s.push_back(aCaracter(c[i]));
    return normalizar_sin_ceros_izquierda(s);
}

string numero_entrada;
vector<int> digitos_entrada; 
int longitud, k;
string mejor = ""; 

vector<int> digitos_a; 

// Poda por límite: verifica si la solución actual no puede mejorar la mejor encontrada
bool podar_por_limite(int posicion) {
    if (mejor.empty()) return false;
    string candidato;
    for (int i = k-1; i >= posicion+1; --i) candidato.push_back('0');
    for (int i = posicion; i >= 0; --i) candidato.push_back(aCaracter(digitos_a[i]));
    candidato = normalizar_sin_ceros_izquierda(candidato);
    if (!menor_numero_cadena(candidato, mejor)) return true;
    return false;
}

// Búsqueda en profundidad (DFS) para encontrar la raíz cuadrada
void busqueda_profundidad(int posicion) {
    if (posicion == k) {
        string conversion = convertir_cuadrado_a_cadena(digitos_a);
        string numero_normalizado = normalizar_sin_ceros_izquierda(numero_entrada);
        if (conversion == numero_normalizado) {
            string cadena_a;
            for (int i = k-1; i >= 0; --i) cadena_a.push_back(aCaracter(digitos_a[i]));
            cadena_a = normalizar_sin_ceros_izquierda(cadena_a);
            if (mejor.empty() || menor_numero_cadena(cadena_a, mejor)) mejor = cadena_a;
        }
        return;
    }

    if (posicion == 0) {
        int objetivo = (digitos_entrada.size() > 0 ? digitos_entrada[0] : 0);
        vector<int> candidatos;
        for (int d = 0; d <= 9; ++d){
            if ((d*d) % 10 == objetivo) candidatos.push_back(d);
        }
        sort(candidatos.begin(), candidatos.end());
        for (int d : candidatos) {
            digitos_a[0] = d;
            if (podar_por_limite(0)) continue;
            busqueda_profundidad(1);
        }
    } else {
        int suma_parcial = 0;
        for (int i = 1; i <= posicion-1; ++i) {
            suma_parcial = (suma_parcial + digitos_a[i] * digitos_a[posicion - i]) % 10;
        }
        int objetivo = (posicion < (int)digitos_entrada.size() ? digitos_entrada[posicion] : 0);
        int lado_derecho = (objetivo - suma_parcial) % 10;
        if (lado_derecho < 0) lado_derecho += 10;
        int coeficiente = (2 * digitos_a[0]) % 10; 
        vector<int> candidatos;
        if (coeficiente == 0) {
            if (lado_derecho == 0) {
                for (int x = 0; x <= 9; ++x) candidatos.push_back(x);
            } 
        } else {
            for (int x = 0; x <= 9; ++x) {
                if ((coeficiente * x) % 10 == lado_derecho) candidatos.push_back(x);
            }
        }
        sort(candidatos.begin(), candidatos.end());
        for (int x : candidatos) {
            digitos_a[posicion] = x;
            if (podar_por_limite(posicion)) continue;
            busqueda_profundidad(posicion+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> numero_entrada)) return 0;
    numero_entrada = normalizar_sin_ceros_izquierda(numero_entrada);
    
    longitud = (int)numero_entrada.size();
    digitos_entrada.clear();
    for (int i = longitud-1; i >= 0; --i) digitos_entrada.push_back(aEntero(numero_entrada[i]));
    k = (longitud + 1) / 2; 
    digitos_a.assign(k, 0);
    mejor = "";

    busqueda_profundidad(0);

    if (mejor.empty()) cout << "-1\n";
    else cout << mejor << "\n";
    return 0;
}


//Explicación del código:
//Este programa encuentra la raíz cuadrada más pequeña de un número dado, donde la multiplicación se 
//realiza sin llevar acarreo (solo se mantiene el último dígito de cada operación).
//Funciones principales:
//normalizar_sin_ceros_izquierda(): Elimina ceros innecesarios al inicio
//convertir_cuadrado_a_cadena(): Calcula el cuadrado sin acarreo de un número
//busqueda_profundidad(): DFS que explora posibles dígitos de la raíz cuadrada
//podar_por_limite(): Optimización que evita explorar ramas que no pueden mejorar la solución
//El algoritmo:
//Lee el número de entrada y lo normaliza
//Calcula la longitud esperada de la raíz cuadrada
//Usa DFS para probar combinaciones de dígitos
//En cada paso, verifica restricciones matemáticas para podar búsquedas innecesarias
//Encuentra la raíz cuadrada más pequeña que cumple la condición



///////////////////////////////////  100% optimizado Solucion del chino: ////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, L;
bool f;
int mp[10][10]; // nueva tabla de multiplicación
char s[100];
int p[100];
int a[100];

void dfs(int x) {
    if (f) return;
    if (x == L + 1) {
        f = true;
        // imprimir resultado
        for (int i = 1; i <= n; i++) cout << a[i];
        cout << endl;
        return;
    }
    for (int d = 0; d <= 9; d++) {
        int tp = 0;
        a[x] = d;
        if (x > n && d) return;
        for (int j = 1; j <= x; j++) {
            if (x - j + 1 > n) continue;
            if (j > n) continue;
            tp += mp[a[j]][a[x - j + 1]];
            tp %= 10;
        }
        if (tp == p[x]) dfs(x + 1);
    }
}

int main() {
    // tabla de multiplicación sin acarreo
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++) 
            mp[i][j] = (i * j) % 10;
    
    cin >> s;
    // longitud de la cadena
    L = strlen(s);
    // la longitud de la raíz cuadrada es (L + 1) / 2
    n = (L + 1) / 2;
    for (int i = 1; i <= L; i++) p[i] = s[i - 1] - '0';
    
    f = false;
    dfs(1); // empezar desde el primer dígito
    
    if (!f) cout << -1 << endl;
    return 0;
}