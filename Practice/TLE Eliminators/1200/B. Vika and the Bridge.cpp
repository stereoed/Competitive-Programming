#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

int n, k;
string s;

void solve(){
    cin >> n >> k;
    vector<int> color(n), prev(k + 1, -1);
    vector<vector<int>> until_next_same_color(k + 1);

    for (auto& c : color) cin >> c;

    for (int i = n - 1; i >= 0; i--){
        const int c = color[i];

        int nxt = (prev[c] == -1 ? n : prev[c]);
        until_next_same_color[c].push_back(nxt - i - 1);
        
        prev[c] = i;
    }

    int ans = n;
    for (int c = 1; c < k + 1; c++){
        if (until_next_same_color[c].empty()) continue;

        until_next_same_color[c].push_back(prev[c]);
        sort(until_next_same_color[c].rbegin(), until_next_same_color[c].rend());
        ans = min(ans, max(until_next_same_color[c][0]/2, until_next_same_color[c][1]));
    }

    dump(until_next_same_color);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}