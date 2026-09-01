#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

void solve(){
    int n, q; cin >> n >> q;
    vector<vector<int>> mat(31);
    vector<int> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];

        for (int j = 0; j < 31; j++){
            mat[j].push_back(i);
            if (v[i] & (1 << j)) break;
        }
    }

    for (int i = 0; i < q; i++){
        int x; cin >> x;
        for (auto idx : mat[x]) {
            if (v[idx] % (1 << x)) continue;

            v[idx] += (1 << (x - 1));
            mat[x-1].push_back(idx);
        }
        mat[x].clear();
    }

    for (auto x : v) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}