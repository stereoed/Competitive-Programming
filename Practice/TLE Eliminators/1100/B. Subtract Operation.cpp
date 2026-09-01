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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    sort(v.rbegin(), v.rend());

    set<int> seen;
    for (const auto x : v){
        dump(k + x, x);
        if (seen.count(k + x)){
            cout << "YES\n";
            return;
        }

        seen.insert(x);
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}