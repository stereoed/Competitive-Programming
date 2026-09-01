#pragma GCC optimize("Ofast")
using namespace std;
#include <bits/stdc++.h>

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, k;
string s;

int dfs(int id, int& ans, vector<vector<int>>& child){
    int score = (s[id] == 'W' ? 1 : -1);
    for (const auto nxt : child[id]) score += dfs(nxt, ans, child);
    if (score == 0) ans++;
    return score;
}

void solve() {
    cin >> n;

    vector<vector<int>> child(n);
    for (int i = 1; i < n; i++){
        int a; cin >> a; a--;
        child[a].push_back(i);
    }

    cin >> s;
    int ans = 0;
    dfs(0, ans, child);

    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}