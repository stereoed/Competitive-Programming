#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
#include "cpp-dump.hpp"
#define dump(...) cpp_dump(__VA_ARGS__);
#else
#define dump(...)
#endif

const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 5;
long long fact[MAXN]{};

long long binpow(long long a, long long b){
    a %= MOD;
    b %= MOD;

    long long o = 1;

    while (b){
        if (b & 1) o = (o * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return o;
}

long long nCr(long long n, long long r){
    if (n < r) return 0;
    if (n == r) return 1;

    long long num = fact[n];
    long long denom = (fact[r] * fact[n - r]) % MOD;
    return (num * binpow(denom, MOD - 2)) % MOD;
}


void solve(){
    int N, K; cin >> N >> K;
    vector<int> R(N);
    for (auto& x : R) cin >> x;

    nth_element(R.begin(), R.begin() + (K - 1), R.end(), greater<int>());
    int block = R[K - 1];

    int n = 0, above = 0;
    for (int x : R){
        if (x == block) n++;
        if (x > block) above++;
    }

    cout << nCr(n, K - above) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    fact[0] = 1;
    for (long long x = 1; x < MAXN; x++) fact[x] = (x * fact[x - 1]) % MOD;

    int t = 1; cin >> t;
    while (t--) solve();
}