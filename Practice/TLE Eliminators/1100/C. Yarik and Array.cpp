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

    int min_idx = 0;
    long long ans = v[1];
    for (int i = 1; i <= n; i++){
        if (i > 1 && ((v[i]-v[i-1])&1) == ((v[i-1]-v[i-2])&1)) min_idx = i - 1; 
        ans = max(ans, v[i] - v[min_idx]);
        if (v[i] <= v[min_idx]) min_idx = i;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}