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

long long n;

void solve() {
    cin >> n;
    vector<int> in(n), out(n);
    vector<bool> seen(n);

    for (int i = n - 1; i >= 0; i--) cin >> in[i];
    for (int i = n - 1; i >= 0; i--) cin >> out[i];

    int ans = 0, idx = 0;
    for (int i = 0; i < n; i++){
        while (seen[out[idx] - 1]) idx++;

        if (out[idx] == in[i]) idx++;
        else ans++;

        seen[in[i] - 1] = true;
    }

    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}