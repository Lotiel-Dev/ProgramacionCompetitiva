#include <bits/stdc++.h>
using namespace std;

static int best[305][305][305]; // best[mid][l][r]
static int dp[305][305];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("pieaters.in", "r", stdin);
    freopen("pieaters.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    // inicializar a 0 (ya está por defecto en static, pero lo dejamos explícito)
    for (int mid = 1; mid <= N; ++mid)
        for (int l = 1; l <= N; ++l)
            for (int r = 1; r <= N; ++r)
                best[mid][l][r] = 0;

    // Leer vacas: para cada vaca con [L,R] y peso w, para cada mid en [L,R]
    // podemos considerar que esa vaca "puede" comer el mid si su intervalo es exactamente [L,R].
    for (int i = 0; i < M; ++i) {
        int w, L, R;
        cin >> w >> L >> R;
        for (int mid = L; mid <= R; ++mid) {
            best[mid][L][R] = max(best[mid][L][R], w);
        }
    }

    // Para cada mid, propagamos valores a intervalos más grandes que contengan [l,r]:
    // best[mid][l][r] = max of:
    //  - itself (vacas con exactamente [l,r]),
    //  - best[mid][l+1][r],
    //  - best[mid][l][r-1]
    // Así best[mid][l][r] será la mejor vaca que cubre mid y cuyo [L,R] está dentro de [l,r].
    for (int mid = 1; mid <= N; ++mid) {
        for (int len = 1; len <= N; ++len) {
            for (int l = 1; l + len - 1 <= N; ++l) {
                int r = l + len - 1;
                if (l < r) {
                    best[mid][l][r] = max(best[mid][l][r], best[mid][l+1][r]);
                    best[mid][l][r] = max(best[mid][l][r], best[mid][l][r-1]);
                }
            }
        }
    }

    // DP sobre intervalos
    for (int len = 1; len <= N; ++len) {
        for (int l = 1; l + len - 1 <= N; ++l) {
            int r = l + len - 1;
            int bestVal = 0;
            // probar cada mid como la tarta que le permita a alguna vaca "comer ahora"
            for (int mid = l; mid <= r; ++mid) {
                int left = (mid > l) ? dp[l][mid-1] : 0;
                int right = (mid < r) ? dp[mid+1][r] : 0;
                int add = best[mid][l][r]; // la vaca que cubre mid y está dentro [l,r]
                bestVal = max(bestVal, left + add + right);
            }
            dp[l][r] = bestVal;
        }
    }

    cout << dp[1][N] << "\n";
    return 0;
}
