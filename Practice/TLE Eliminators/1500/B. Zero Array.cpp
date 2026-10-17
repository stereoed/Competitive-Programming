#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const int MOD = 1e9 + 7;

struct DSU {
    int n;
    vector<int> size;
    vector<int> dad;
    DSU(int node_amount){
        n = node_amount;
        size.assign(n, 1);
        dad.resize(n); // Que el padre de cada indice sea si mismo.
        iota(dad.begin(), dad.end(), 0);
    }

    int find(int u){
        if (dad[u] == u) return u;
        return dad[u] = find(dad[u]);
    }

    void unite(int u, int v){
        u = find(u);
        v = find(v);
        if (u == v) return;

        if (size[u] < size[v]) swap(u, v);
        dad[v] = u; // la raiz chica se concatena a la raiz grande
        size[u] += size[v];
    }
};

long long llpow(long long base, long long exp){
    long long o = 1;
    for (int i = 0; i < exp; i++) o = (o * base) % MOD;
    return o;
}

void solve(){
    int N; cin >> N;
    long long sum = 0, max_num = 0;

    for (int i = 0; i < N; i++){
        int a; cin >> a;
        max_num = max(max_num, 1LL * a);
        sum += a;
    }
    
    cout << (sum >= 2 * max_num && sum % 2 == 0 ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}