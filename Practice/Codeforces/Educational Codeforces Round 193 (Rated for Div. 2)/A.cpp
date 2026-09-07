#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

int n, m;
vector<int> v;
vector<bool> is_prime(1e6 + 5, true);


void solve(){
    cin >> n;
    //v.assign(n, 0);
    //for (auto& x : v) cin >> x;
    //int ans = 0;

    bool ok = is_prime[n+1]; dump(n+1, is_prime[n+1], is_prime);
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    for (int i = 2; i < 1000; i++){
        if (!is_prime[i]) continue;
        for (int j = i*i; j < 1000005; j += i) is_prime[j] = false;
    }

    while (t--) {
        solve();
    }
}