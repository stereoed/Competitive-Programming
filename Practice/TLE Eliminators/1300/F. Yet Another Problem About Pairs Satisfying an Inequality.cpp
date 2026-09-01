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
    vector<int> v(n);
    for (auto& x : v) { cin >> x; x--; } 

    long long ans = 0;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++){
        bool valid = v[i] < i;
        int score = (valid && v[i] > 0 ? cnt[v[i] - 1] : 0);
    
        ans += score;
        cnt[i] = valid;
        if (i > 0) cnt[i] += cnt[i - 1];

        dump(v[i], valid);
        dump(ans, score, cnt);
    }
    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}