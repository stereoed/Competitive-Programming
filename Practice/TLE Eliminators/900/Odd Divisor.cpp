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

vector<int> primes;
vector<bool> is_prime(1e7, true);

long long n;
void solve() {
    cin >> n;
    while (n % 2 == 0) n /= 2;
    cout << (n != 1 ? "YES\n" : "NO\n");
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}