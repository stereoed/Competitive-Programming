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

int n, k;

void solve() {
    cin >> n >> k;
    vector<int> max_k(n), present(k);
    for (auto& x : max_k) { cin >> x; x--; }
    for (auto& x : present) cin >> x;
    sort(max_k.rbegin(), max_k.rend());

    int cur_k = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++){
        if (cur_k < k && present[cur_k] < present[max_k[i]]) ans += present[cur_k++];
        else ans += present[max_k[i]];
    }

    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}