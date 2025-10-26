#include <bits/stdc++.h>
using namespace std;

const int MAX_NODOS = 1e5 + 5;

struct Arista {
	int to, next;
} aristas[MAX_NODOS << 1];

int cab[MAX_NODOS], cnt_ari;
int tam_sub[MAX_NODOS];
int prof[MAX_NODOS];
int grados_prof[MAX_NODOS];
int tam_max_sub[MAX_NODOS];
int extremos[MAX_NODOS];
int num_nodos;

void agregar_arista_dir(int u, int v) {
	aristas[cnt_ari].to = v;
	aristas[cnt_ari].next = cab[u];
	cab[u] = cnt_ari;
	cnt_ari++;
}

void agregar_arista(int u, int v) {
	agregar_arista_dir(u, v);
	agregar_arista_dir(v, u);
}

void inicializar() {
	memset(cab, -1, sizeof(cab));
	cnt_ari = 0;
}

void dfs_tam_prof(int u) {
	tam_sub[u] = 1;

	for (int i = cab[u]; i != -1; i = aristas[i].next) {
		int v = aristas[i].to;

		if (!prof[v]) {
			prof[v] = prof[u] + 1;
			dfs_tam_prof(v);
			tam_sub[u] += tam_sub[v];
		}
	}
}

int buscar_centroide() {
	memset(prof, 0, sizeof(prof));
	prof[1] = 1;

	dfs_tam_prof(1);

	int centroide = 0;
	tam_max_sub[0] = INT_MAX;

	for (int u = 1; u <= num_nodos; u++) {
		tam_max_sub[u] = 0;

		for (int i = cab[u]; i != -1; i = aristas[i].next) {
			int v = aristas[i].to;
			if (prof[v] == prof[u] + 1) {
				tam_max_sub[u] = max(tam_max_sub[u], tam_sub[v]);
			}
		}

		tam_max_sub[u] = max(tam_max_sub[u], num_nodos - tam_sub[u]);

		if (tam_max_sub[u] < tam_max_sub[centroide]) {
			centroide = u;
		}
	}

	return centroide;
}

bool verificar(int raiz) {
	memset(tam_sub, 0, sizeof(tam_sub));
	memset(prof, 0, sizeof(prof));
	memset(grados_prof, 0, sizeof(grados_prof));

	prof[raiz] = 1;

	dfs_tam_prof(raiz);

	for (int u = 1; u <= num_nodos; u++) {
		int grado_nodo = 0;

		for (int i = cab[u]; i != -1; i = aristas[i].next) {
			grado_nodo++;
		}

		if (grados_prof[prof[u]] == 0) {
			grados_prof[prof[u]] = grado_nodo;
		} else if (grados_prof[prof[u]] != grado_nodo) {
			return false;
		}
	}

	return true;
}

int dfs_fin_cadena(int u, int padre) {
	int cnt_hijos = 0;
	int hijo = 0;

	for (int i = cab[u]; i != -1; i = aristas[i].next) {
		if (aristas[i].to != padre) {
			cnt_hijos++;
			hijo = aristas[i].to;
		}
	}

	if (cnt_hijos == 0) return u;
	if (cnt_hijos > 1) return 0;

	return dfs_fin_cadena(hijo, u);
}

bool comparar_prof(const int& a, const int& b) {
	return prof[a] < prof[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	inicializar();

	cin >> num_nodos;

	if (num_nodos == 1) {
		cout << "1\n";
		return 0;
	}

	for (int i = 1; i < num_nodos; i++) {
		int u, v;
		cin >> u >> v;
		agregar_arista(u, v);
	}

	int centroide = buscar_centroide();
	if (verificar(centroide)) {
		cout << centroide << "\n";
		return 0;
	}

	int cnt_extremos = 0;
	for (int i = cab[centroide]; i != -1; i = aristas[i].next) {
		int vecino = aristas[i].to;
		int extremo = dfs_fin_cadena(vecino, centroide);

		if (extremo != 0) {
			extremos[++cnt_extremos] = extremo;
		}
	}

	sort(extremos + 1, extremos + cnt_extremos + 1, comparar_prof);

	if (cnt_extremos >= 1 && verificar(extremos[1])) {
		cout << extremos[1] << "\n";
		return 0;
	}

	if (cnt_extremos >= 1 && verificar(extremos[cnt_extremos])) {
		cout << extremos[cnt_extremos] << "\n";
		return 0;
	}

	cout << "-1\n";

	return 0;
}