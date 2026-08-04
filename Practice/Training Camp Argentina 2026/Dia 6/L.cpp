#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

int n, m, k;

struct DSU {
    int n;
    vector<int> size;
    vector<int> dad;
    DSU(int node_amount){
        n = node_amount;
        size.assign(n, 1);
        dad.resize(n);
        iota(dad.begin(), dad.end(), 0);
    }

    int find(int u){
        if (dad[u] == u) return u;
        return dad[u] = find(dad[u]);
    }

    void unite(int u, int v){
        u = find(u);
        v = find(v);
        if (size[u] < size[v]) swap(u, v);
        dad[v] = u;
        size[u] += size[v];
    }
};

void solve(){
    cin >> n >> m >> k;
    
    DSU dsu(n);
    vector<bool> is_dad(n, true);
    vector<pair<int, pair<int, int>>> edges(m);

    for (auto& [limit, cities] : edges){
        auto& [a, b] = cities;
        cin >> a >> b >> limit; a--; b--;
    }

    sort(edges.begin(), edges.end()); dump(edges);
    long long ans = 1e18;

    int i = 0;
    for (; i < m; i++){
        const auto& [limit, cities] = edges[i];
        const auto& [a, b] = cities;

        if (limit > k) break;

        ans = min<long long>(ans, k - limit);

        dsu.unite(a, b);
    }

    // CASO A: COMPLETO
    int number_of_scc = 0;
    for (int x = 0; x < n; x++){
        number_of_scc += (dsu.find(x) == x);
    } 

    if (number_of_scc == 1){
        long long ans_above = (i < m ? edges[i].first - k : 1e18);
        cout << min(ans_above, ans) << '\n';
        return;
    }

    // CASO B: Faltan SCC
    ans = 0;

    for (; i < m; i++){
        const auto& [limit, cities] = edges[i];
        const auto& [a, b] = cities;

        if (dsu.find(a) != dsu.find(b)){
            ans += limit - k;
            dsu.unite(a, b);
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
