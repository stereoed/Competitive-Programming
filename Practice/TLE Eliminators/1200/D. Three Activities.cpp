#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

int n;
string s;
vector<bool> blocked;
vector<bool> lpft;
vector<vector<pair<int, int>>> mat;

int dfs(int cnt) {
    if (cnt == 3) return 0;

    int best = 0;
    for (int i = 0; i < 3; i++) {
        if (!lpft[i]) continue;
        lpft[i] = false;

        for (int j = 0; j < 3; j++) {
            int day = mat[i][j].second;
            if (blocked[day]) continue;

            blocked[day] = true;
            best = max(best, mat[i][j].first + dfs(cnt + 1));
            blocked[day] = false;
        }

        lpft[i] = true;
    }
    return best;
}
void solve(){
    cin >> n;
    mat.assign(3, vector<pair<int, int>>(n, {0, 0}));
    blocked.assign(n, false);
    lpft.assign(min(3, n), true);

    for (auto& act : mat) {
        for (int i = 0; i < n; i++) { 
            cin >> act[i].first;
            act[i].second = i;
        }
        sort(act.rbegin(), act.rend());
        act.resize(min(3, n));
    }

    int ans = dfs(0);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}