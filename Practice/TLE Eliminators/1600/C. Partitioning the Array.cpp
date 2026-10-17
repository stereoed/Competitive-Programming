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
    int N; cin >> N;
    vector<long long> V(N);
    for (auto& x : V) cin >> x;
    
    int ans = 0;

    for (int k = 1; k <= N; k++){
        if (N % k) continue;

        int g = 0;
        for (int i = 0; i < k; i++){
            for (int j = i + k; j < N; j += k){
                g = gcd(g, abs(V[j] - V[j - k]));
            }
        }
        if (g != 1) ans++;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}