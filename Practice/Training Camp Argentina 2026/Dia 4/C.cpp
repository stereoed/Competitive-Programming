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

const int MAXN = 1e5 + 5;

int n;
vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> depth, hashtag;

void dfs(int node, int p){
    up[0][node] = (p == -1 ? node : p);
    depth[node] = (p == -1 ? 0 : depth[p] + 1);

    for (int nxt : adj[node]){
        if (nxt == p) continue;
        dfs(nxt, node);
        hashtag[node] += hashtag[nxt];
    }
}

void build_binlift(int n){
    for (int i = 1; i < 30; i++){
        for (int j = 0; j < n; j++){
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
}

int lift(int node, int k){
    int a = 0;
    while (k){
        if (a < 30 && k & 1) node = up[a][node];
        k >>= 1;
        a++;
    }
    return node;
}

int lca(int a, int b){
    if (depth[a] < depth[b]) swap(a, b);
    a = lift(a, depth[a] - depth[b]);
    if (a == b) return a;

    for (int i = 29; i >= 0; --i){
        if (up[i][a] != up[i][b]){
            a = up[i][a];
            b = up[i][b];
        }
    }
    return up[0][a];
}

long long query(){
    long long a, b; cin >> a >> b; a--; b--;

    if (a == b){
        return n;
    }

    long long distance = depth[a] + depth[b] - 2*depth[lca(a, b)];
    if (distance & 1){
        return 0;
    }

    if (depth[a] < depth[b]) swap(a, b);
    long long mid = lift(a, distance / 2);

    if (depth[a] == depth[b]){
        long long ans = n;
        ans -= hashtag[lift(a, distance / 2 - 1)];
        ans -= hashtag[lift(b, distance / 2 - 1)];
        return ans;
    }

    long long ans = hashtag[mid];
    ans -= hashtag[lift(a, distance/2 - 1)];    
    return ans;

}

void solve() {
    cin >> n;
    adj = vector<vector<int>>(n);
    depth = vector<int>(n, -1);
    hashtag = vector<int>(n, 1);
    up = vector<vector<int>>(30, vector<int>(n));

    vector<int> parent(n);
    for (int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b; a--; b--;

        parent[b] = a;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);
    build_binlift(n);
    parent.clear();

    dump(adj)
    dump(depth)
    dump(hashtag)
    dump(up)

    //// Queries ////
    int q; cin >> q;
    for (int i = 0; i < q; i++){
        cout << query() << el;
    }
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}
