#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

long long n, m;
vector<long long> v; 
string s;

//freq of the second most repeated card?

void solve(){
    cin >> n >> m; dump(n, m);

    vector<int> stab(n);
    for (auto& x : stab) cin >> x;
    int ans = m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (auto& line : grid) for (auto& x : line) cin >> x;

    vector<int> gain;
    for (int i = n - 1; i >= 0; i--){
        for (int x : grid[i]) gain.push_back(x);
        sort(gain.rbegin(), gain.rend());
        gain.resize(m);

        for (int j = 0; j < m; j++){
            stab[i] -= gain[j];
            if (stab[i] <= 0){
                ans = min(ans, j + 1);
                break;
            }
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