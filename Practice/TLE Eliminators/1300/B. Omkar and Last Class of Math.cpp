#pragma GCC optimize("Ofast")
using namespace std;
#include <bits/stdc++.h>

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<bool> is_prime(1e5, true);
vector<int> primes;

long long n, k;

void solve() {
    cin >> n;

    for (const auto p : primes){
        if (n % p == 0){
            cout << n / p << " " << (p - 1) * (n / p) << '\n';
            return;
        }
    }
    cout << 1 << " " << n - 1 << '\n';
}

int main() {
    FastIO;

    for (long long i = 2; i < 5 * 1e4; i++){
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (long long x = i * i; x < 5 * 1e4; x += i) is_prime[x] = false;
    }

    int t = 1; cin >> t;
    while (t--) solve();
}