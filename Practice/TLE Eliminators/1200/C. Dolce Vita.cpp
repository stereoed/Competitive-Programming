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

long long n, x;

void solve() {
    cin >> n >> x;
    vector<long long> v(n);
    int start = n-1;

    for (int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));

    for (int i = 0; i < n; i++) {
        if (i > 0) v[i] += v[i-1];
        if (v[i] > x) start = min(start, i - 1);
    }

    long long ans = 0, time = 0; dump(v, start);
    for (int i = start; i >= 0; i--){
        long long shops = i + 1; dump(shops);
        long long days = (x + shops - (time * shops) - v[i]) / shops; dump(x + shops, (time * shops), v[i], days);
        ans += days * shops; dump(ans);
        time += days; dump(time);
    }

    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}