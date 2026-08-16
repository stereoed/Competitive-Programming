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
void solve() {
    cin >> n;
    long long ans = 0;

    while (n > 1){
        if (n % 6 == 0){
            n /= 6;
            ans += 1;
            continue;
        }

        if (n % 3 == 0){
            n /= 3;
            ans += 2;
            continue;
        }

        cout << "-1\n";
        return;
    }

    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}