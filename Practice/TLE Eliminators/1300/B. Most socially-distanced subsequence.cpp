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

long long n, k;

void solve() {
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    vector<int> ans = {v[0]};
    for (int i = 1; i < n; i++){
        if (i == n - 1) {
            if (v[i] != ans.back()) ans.push_back(v[i]);
            break;
        }

        if ((v[i] - v[i - 1] < 0) != (v[i + 1] - v[i] < 0)) ans.push_back(v[i]);
    }

    cout << ans.size() << '\n';
    for (const auto x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}