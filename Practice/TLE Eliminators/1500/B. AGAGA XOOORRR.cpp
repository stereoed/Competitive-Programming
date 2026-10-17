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
    int n; cin >> n;
    vector<int> v(n);

    int X = 0;
    for (auto& x : v) cin >> x;
    set<int> S;
    vector<int> Aux;

    for (auto& x : v) {
        X ^= x;
        Aux.push_back(X);
        if (X == 0){
            for (auto x : Aux) S.insert(x);
            Aux.clear();
        }
    }

    if (X == 0 || S.count(X)){
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}