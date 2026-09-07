#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const long long MOD = 1e9 + 7;
const int MAXN = 2 * 1e5 + 5;
long long fac[MAXN];

void solve(){
    int n; cin >> n;
    vector<int> v(n);

    long long A = (1LL << 31) - 1; 
    for (auto& x : v){
        cin >> x;
        A &= x;
    }

    int cnt = 0;
    for (auto x : v) cnt += (x == A);
    long long cntMOD = 1LL * cnt * (cnt - 1) % MOD;
    cout << fac[n - 2] * cntMOD % MOD << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) fac[i] = i * fac[i - 1] % MOD;

    int t = 1; cin >> t;
    while (t--) solve();
}