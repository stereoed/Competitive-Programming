#pragma GCC optimize("Ofast")
using namespace std;

#if __has_include("stdc++.h")
    #include "stdc++.h"
#else
    #include <bits/stdc++.h>
#endif

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define el '\n'

int n, m;
vector<pair<int, int>> delta = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> adj;
vector<int> color;
vector<int> candidatos;
vector<bool> seen;
void dfs(int node){
    for (auto nxt : adj[node]){
        if (seen[nxt]) continue;
        seen[nxt] = true;

        if (color[nxt] != color[node]){
            candidatos.push_back(node);
            candidatos.push_back(nxt);
        } 

        dfs(nxt);
    }
}

void yes(int node){
    cout << "YES" << el;
    cout << node + 1 << el;
}

void no(){
    cout << "NO" << el;
}

void solve() {
    cin >> n;
    adj = vector<vector<int>>(n);
    color = vector<int>(n);
    seen = vector<bool>(n);
    candidatos.clear();

    for (int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (auto& c : color) cin >> c;
    // dump(adj); dump(color);

    seen[0] = true; dfs(0);
    sort(all(candidatos));
    dump(candidatos)

    if (candidatos.empty()){ // Todos son del mismo color
        yes(0);
        return;
    }

    if (candidatos.size() == 2){ // Solo hay un cambio de color en el grafo, cualquira sirve
        yes(candidatos.front());
        return;
    }

    int centre = -1;
    /*
        Aca la idea es que si hay uno que se repita mas de una vez actua como hlb
        A -> hub -> B. Debe si o si ser el nodo raiz, si hay mas de uno, imposible.
        Si no se repite ninguno entonces tengo A -> B y D -> G. Imposible.
    */

    for (int i = 1; i < candidatos.size(); i++){
        if (candidatos[i] == candidatos[i-1]){
            if (centre == -1 || centre == candidatos[i]) centre = candidatos[i];

            else {
                no();
                return;
            }
        }
    }

    if (centre == -1){
        no();
        return;
    }

    // Ahora todos los que quedan deben estar conectados al center
    for (const auto c : candidatos){
        if (c == centre) continue;
        bool flag = false;

        for (const auto nxt : adj[c]){
            if (nxt == centre){
                flag = true;
                break;
            }
        }

        if (flag) continue;

        no();
        return;
    }
    yes(centre);
    
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}