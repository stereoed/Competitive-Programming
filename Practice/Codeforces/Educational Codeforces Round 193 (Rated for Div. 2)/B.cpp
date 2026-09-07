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
    v.assign(n, 0);
    for (auto& x : v) cin >> x;
    int ans = 1;

    for (int i = 1; i < n; i++){
        if (v[i] != v[i-1]) ans++;
    }

    int onetwo = 0;
    for (int i = 0; i + 1 < n; ++i) {
        int testing = 0;
        if (i > 0) {
            testing += (v[i - 1] != v[i + 1]) - (v[i - 1] != v[i]);
        }

        if (i + 2 < n) {
            testing += (v[i] != v[i + 2]) - (v[i + 1] != v[i + 2]);
        }

        onetwo = max(onetwo, testing);
    }

    ans += onetwo;
    cout << ans << '\n';
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