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
#define pb(a) push_back(a)

int n, m;
string s1, s2;
long long danger = 1;

vector<bool> seen;
vector<vector<int>> adj;

void solve() {
    cin >> n >> m;
    danger = 1;

    seen = vector<bool>(n);
    adj = vector<vector<int>>(n);

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int exp = n;
    queue<int> q;

    for (int j = 0; j < n; j++){
        if (seen[j]) continue;
        seen[j] = true;

        exp--;
        q.push(j);

        while(!q.empty()){
            int cur = q.front(); q.pop();
            for (auto nxt : adj[cur]){
                if (seen[nxt]) continue;
                seen[nxt] = true;
                q.push(nxt);
            }
        }
    }

    for (int i = 0; i < exp; i++) danger *= 2;
    cout << danger << el;
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}
