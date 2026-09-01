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
    string a, b; cin >> a >> b;
    int na = a.size(), nb = b.size();
    int ans = na + nb;

    for (int i = 0; i < na; i++){
        string s = "";
        for (int j = i; j < na; j++){
            s += a[j];

            if (na - j - i >= ans) continue;

            auto it = b.find(s);
            if (it == string::npos) continue;

            ans = min(ans, na + nb - 2 * (j - i + 1));
        }
    }

    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}