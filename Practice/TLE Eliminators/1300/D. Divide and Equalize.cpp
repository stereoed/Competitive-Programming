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
#define all(v) v.begin(), v.end()

long long n;
vector<bool> is_prime(1e3 + 1, true);
vector<int> primes;

void solve() {
    cin >> n;
    map<int, int> cnt;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        for (const auto p : primes){
            if (x == 1) break;
            while (x % p == 0){
                cnt[p]++;
                x /= p;
            }
        }
        if (x != 1) cnt[x]++;
    }

    for (const auto& [p, c] : cnt){
        if (c % n){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    FastIO;

    for (int i = 2; i <= 1e3; i++){
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (int x = i * i; x <= 1e3; x += i) is_prime[x] = 0;
    }

    int t = 1; cin >> t;
    while (t--) solve();
}