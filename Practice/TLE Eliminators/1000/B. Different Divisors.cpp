#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

vector<bool> is_prime(5 * 1e5 + 1, true);
vector<int> primes;

void solve() {
    long long n; cin >> n;
    long long ans = 1;

    auto it = *upper_bound(primes.begin(), primes.end(), n); dump(it);
    ans *= it;

    it = *upper_bound(primes.begin(), primes.end(), it + n - 1); dump(it);
    ans *= it;

    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for (long long i = 2; i < 5 * 1e5; i++){
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (long long x = i * i; x < 5 * 1e5; x += i) is_prime[x] = false;
    }

    dump(primes);

    int t = 1; cin >> t;
    while (t--) solve();
}