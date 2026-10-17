#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const int MAXN = 1e5 + 6;
const int MOD = 998244353;
long long fact[MAXN]{};

long long binpow(long long a, long long b){
    a %= MOD;
    long long o = 1;

    while (b){
        if (b & 1) o = (o * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }

    return o % MOD;
}

long long nCr(long long a, long long b){
    long long num = fact[a] % MOD;
    long long denom = fact[b] * fact[a - b] % MOD;
    return (num * binpow(denom, MOD - 2)) % MOD;
}

void solve(){
    int N; cin >> N;
    vector<int> V(N);
    for (auto& x : V) cin >> x;
    
    long long ans = nCr(N / 3, N / 6); dump(ans);
    for (int i = 0; i < N; i += 3){
        int O[] = {V[i], V[i + 1], V[i + 2]};
        sort(O, O + 3);
        dump(O);

        if (O[0] == O[2]) ans *= 3;
        else if (O[0] == O[1]) ans *= 2;
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    fact[0] = 1;
    for (long long i = 1; i < MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;

    int t = 1; //cin >> t;
    while (t--) solve();
}