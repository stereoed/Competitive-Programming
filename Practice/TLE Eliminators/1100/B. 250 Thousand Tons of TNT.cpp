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
    vector<long long> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    dump(v);
    
    long long ans = 0;
    for (int i = 1; i < n; i++){
        if (n % i) continue;

        long long ma = 0, mi = 1e18;
        for (int j = i; j <= n; j += i){
            long long sum = v[j] - v[j - i];
            ma = max(ma, sum);
            mi = min(mi, sum);
        }

        ans = max(ans, ma - mi);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}