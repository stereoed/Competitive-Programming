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

void solve(){
    int n; cin >> n;
    vector<long long> v(n);
    for (auto& x : v) cin >> x;
    sort(v.begin(), v.end());

    if (v[0] != 1){
        cout << "NO\n";
        return;
    }

    for (int i = 1; i < n; i++) {
        if (v[i] > v[i - 1]){
            cout << "NO\n";
            return;
        }

        v[i] += v[i - 1];
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}