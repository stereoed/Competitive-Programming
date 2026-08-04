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
vector<int> v;

void solve(){
    cin >> n;
    v.assign(n, 0);
    for (auto& x : v) cin >> x;

    bool ok = false;

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            ok |= gcd(v[i], v[j]) <= 2;
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
