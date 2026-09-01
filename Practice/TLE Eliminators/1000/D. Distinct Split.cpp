#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve() {
    int n; string s;
    cin >> n >> s;
    map<char, int> cnt; set<int> seen_a;

    for (const char c : s) cnt[c]++;

    int b = cnt.size();
    int ans = b;
    for (const char c : s){
        seen_a.insert(c);
        if (--cnt[c] == 0) b--;
        ans = max(ans, b + (int)seen_a.size());
    }

    cout << ans << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}