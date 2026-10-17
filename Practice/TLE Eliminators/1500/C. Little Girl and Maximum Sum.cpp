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
    int N, Q; cin >> N >> Q;
    vector<int> V(N), P(N + 2);
    
    for (auto& x : V) cin >> x;
    
    for (int i = 0; i < Q; i++) {
        int l, r; cin >> l >> r;
        P[l]++;
        P[r + 1]--;
    }
    
    for (int i = 1; i < N + 2; i++) P[i] += P[i - 1];
    
    sort(V.rbegin(), V.rend());
    sort(P.rbegin(), P.rend());
    
    long long ans = 0;
    for (int i = 0; i < N; i++) ans += 1LL * P[i] * V[i];
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}