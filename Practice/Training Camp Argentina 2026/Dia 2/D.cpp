#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repk(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

void solve() {
    int n; cin >> n;
    vector<vector<int>> G(n);

    rep(i, n - 1){
        int x, y; cin >> x >> y; x--; y--;
        G[x].push_back(y); G[y].push_back(x);
    }

    int k = 0;
    rep(i, n){
        k = max(k, (int)G[i].size() + 1);
    }
    cout << k << endl;

    vector<int> color(n, -1);
    queue<p> q; q.push({0, -1});
    color[0] = 0;

    while(!q.empty()){
        auto [u, f_c] = q.front(); q.pop();

        int c = 0;
        rep(i, (int)G[u].size()){
            int v = G[u][i];
            if (color[v] != -1) {
                continue;
            }
            if (c == color[u] || c == f_c) c++;
            if (c == color[u] || c == f_c) c++;
            color[v] = c;
            q.push({v, color[u]});
            c++;
        }
    }
    rep(i, n){
        cout << color[i] + 1 << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}