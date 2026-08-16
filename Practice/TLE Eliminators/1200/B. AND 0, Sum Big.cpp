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

const long long MOD = 1e9 + 7;
long long n, k;

long long pw(long long x, int e){
    long long res = 1;
    for (int i = 0; i < e; i++){
        res *= x;
        res %= MOD;
    }
    return res; 
}

void solve() {
    cin >> n >> k;
    cout << pw(n, k) << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}