#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif
const int MAXN = 1e6 + 5;
const int MOD = 998244353;

long long fact[MAXN]{};

long long binexp(long long a, long long b){
    long long o = 1;
    while (b > 0){
        if (b & 1) o = (o * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return o;
}

long long invmod(long long a){
    return binexp(a, MOD - 2);
}

long long nCr(long long n, long long r){
    if (n < 0 || r < 0 || r > n) return 0;

    long long num = fact[n];
    long long denom = (fact[n - r] * fact[r]) % MOD;
    return (num * invmod(denom)) % MOD;
}

void solve(){
    int N, K, A; cin >> N >> K >> A;
    long long ans = (binexp(A, min(2, N)) * binexp(A - 1, max(N - K - 2, 0))) % MOD;

    if (K == 0){
        cout << ans << '\n';
        return;
    }

    if (N <= 2) {
        cout << "0\n";
        return;
    }

    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;

    cout << (ans * nCr(N - 2, K)) % MOD << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}