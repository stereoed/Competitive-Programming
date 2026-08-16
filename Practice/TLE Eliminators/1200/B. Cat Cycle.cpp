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

long long n, k;
 
void solve() {
    cin >> n >> k; k--;

    if (n%2 == 0){
        cout << (k % n) + 1 << '\n';
        return;
    }

    long long ans = (k + k / (n/2)) % n;
    cout << ans + 1 << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}