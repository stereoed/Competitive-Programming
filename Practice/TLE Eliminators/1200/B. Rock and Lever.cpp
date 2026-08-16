#pragma GCC optimize("Ofast")
using namespace std;

#if __has_include("stdc++.h")
    #include "stdc++.h"
#else
    #include <bits/stdc++.h>
#endif

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define el '\n'

int n;

int MSB(int x){
    int r = 1, out = 0;
    while (r <= x){
        r *= 2;
        out++;
    }

    return out - 1;
}

void solve() {
    cin >> n;
    vector<int> cnt(35);
    long long ans = 0;

    for (int i = 1; i <= n; i++){
        int x; cin >> x; dump(x, MSB(x), cnt[MSB(x)]);
        ans += cnt[MSB(x)]++;
    }

    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}