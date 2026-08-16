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

long long x, n; 
void solve() {
    cin >> x >> n;

    if (n == 0){
        cout << x << '\n';
        return;
    }

    n++;
    long long time = (4 * (n / 4));
    long long ans = (x & 1 ? x - time : x + time);
    for (int i = 0; i < n % 4; i++){
        if (ans % 2 == 0) ans -= time;
        else ans += time;

        time++;
    }

    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}