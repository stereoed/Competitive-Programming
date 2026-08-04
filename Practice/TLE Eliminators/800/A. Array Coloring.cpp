#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

int n, m, a, b, c;
vector<int> v;
string s, s1, s2;

void solve(){
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a;
        sum += a;
    }

    const bool ok = sum % 2 == 0;
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
