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

string a, b;
void solve() {
    cin >> a >> b;
    int n = a.size(), m = b.size() - 1;
    bool ok = true;

    vector<int> cnt(26);
    for (int i = n - 1; i >= 0; i--){
        if (m < 0) break;

        if (a[i] == b[m]){
            if (cnt[b[m] - 'A'] > 0) ok = false;
            m--;
            continue;
        }

        cnt[a[i] - 'A']++;
    }

    ok &= m < 0;

    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}