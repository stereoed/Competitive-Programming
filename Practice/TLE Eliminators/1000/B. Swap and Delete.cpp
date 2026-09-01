#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

void solve() {
    string s; cin >> s; dump(s);
    int n = s.size();

    pair<int, int> have, want;
    for (char c : s) have.first += c == '0';
    have.second = n - have.first;
    want = {have.second, have.first};
    dump(have, want);

    int ans = 0;
    for (; ans < n; ans++){
        if (have.first >= want.first && have.second >= want.second) break;
        dump(want);
        int ptr = n - 1 - ans;
        want = {want.first - (s[ptr] == '1'), want.second - !(s[ptr] == '1')};
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}