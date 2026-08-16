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

long long n, x, mx, sum;
void solve() {
    cin >> n >> x;
    mx = 0;
    sum = 0;
    
    for (int i = 0; i < n; i++){
        int y; cin >> y;
        mx += (y + x - 1) / x;
        sum += y; 
    }
    cout << (sum + x - 1) / x << " " << mx << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}