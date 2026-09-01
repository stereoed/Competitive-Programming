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

long long n;

void solve() {
    cin >> n;
    int a = 1, b = 1, c = 1;

    int mult = 1;
    for (const auto p : primes){
        while (n % p == 0){
            mult *= p;
            n /= p;

            if (a == 1) {
                a = mult;
                mult = 1;
            }
            else if (mult != a && b == 1) b = mult;
            
            if (b != 1) break;
        }
        if (b != 1) break;        
    }

    if (b != 1) c = n;
    dump(a, b, c);

    if (c == 1 || b == c || c == a) cout << "NO\n";
    else cout << "YES\n" << a << " " << b << " " << c << '\n';
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