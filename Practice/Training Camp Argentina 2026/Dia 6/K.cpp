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

struct DSU {
    int n;
    vector<int> size;
    vector<int> dad;
    DSU(int node_amount){
        n = node_amount;
        size.assign(n, 1);
        dad.resize(n); // Que el padre de cada indice sea si mismo.
        iota(all(dad), 0);
    }

    int find(int u){
        if (dad[u] == u) return u;
        return dad[u] = find(dad[u]);
    }

    void unite(int u, int v){
        u = find(u);
        v = find(v);
        if (size[u] < size[v]) swap(u, v);
        dad[v] = u; // la raiz chica se concatena a la raiz grande
        size[u] += size[v];
    }
};

void solve() {
    cin >> n >> m;
    DSU dsu(n);

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        dsu.unite(a, b);
    }

    dump(dsu.dad);

    vector<int> open;
    set<int> seen;

    int ans = 0;
    for (int i = 0; i < n; i++){
        int dad = dsu.find(i);

        if (seen.count(dad)){
            while (!open.empty() && dsu.find(open.back()) != dad){
                dump("seen", i, dad, dsu.find(open.back()))

                dsu.unite(dad, open.back());
                dad = dsu.find(dad);

                ans++;
                open.pop_back();
            }
            continue;
        }

        seen.insert(dad);
        open.push_back(i);
    }

    cout << ans << el;
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}