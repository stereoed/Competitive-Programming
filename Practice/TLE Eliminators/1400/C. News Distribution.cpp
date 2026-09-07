#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

struct DSU {
    long long n;
    vector<long long> size;
    vector<long long> dad;
    DSU(long long node_amount){
        n = node_amount;
        size.assign(n, 1);
        dad.resize(n);
        iota(dad.begin(), dad.end(), 0);
    }

    long long find(long long u){
        if (dad[u] == u) return u;
        return dad[u] = find(dad[u]);
    }

    void unite(long long u, long long v){
        u = find(u);
        v = find(v);

        if (u == v) return;
        if (size[u] < size[v]) swap(u, v);
        dad[v] = u; // la raiz chica se concatena a la raiz grande
        size[u] += size[v];
    }
};

void solve(){
    int n, m; cin >> n >> m;

    DSU dsu(n + 1);
    for (int i = 0; i < m; i++){
        int k; cin >> k;
        int prev = -1;

        for (int j = 0; j < k; j++){
            int u; cin >> u;
            if (prev > 0) dsu.unite(prev, u);
            prev = u;
        }
    }

    for (int i = 1; i <= n; i++) cout << dsu.size[dsu.find(i)] << ' ';
    cout << '\n';    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}