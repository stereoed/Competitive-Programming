#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const ll INFL = 4e18;
 
/* 
 
 Shortest Routes II - Floyd-Warshall Algorithm
 
 Algorithm info:
 n ^ 3 -> log (500^3) = 3 log (100) + log(125) = 8.01
 
 Se usa con n <= 500 cuando tengo multiples puntos de inicio / fin. No pueden
 haber loops negativos.
 
 Tengo dos matrices, la de distancia, y la de predecesor (que no aplica)
 
*/
 
void solve() {
    int n, m, query;
    cin >> n >> m >> query;
 
    vector<vector<ll>> dist(n, vector<ll>(n, INFL));
 
    for (int i = 0; i < n; i++) dist[i][i] = 0;
 
    for (int i = 0; i < m; i++) {
        int a, b;
        ll d;
        cin >> a >> b >> d;
        a--; b--;
 
        dist[a][b] = min(dist[a][b], d);
        dist[b][a] = min(dist[b][a], d);
    }
 
    // Floyd-Warshall
    for (int k = 0; k < n; k++) { // Loop de los nodos intermedios
        for (int i = 0; i < n; i++) { // Loop de inicio
            for (int j = 0; j < n; j++) { // Loop final
                if (dist[i][k] == INFL || dist[k][j] == INFL) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
 
    for (int i = 0; i < query; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
 
        if (dist[a][b] == INFL) cout << -1 << '\n';
        else cout << dist[a][b] << '\n';
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
    return 0;
}