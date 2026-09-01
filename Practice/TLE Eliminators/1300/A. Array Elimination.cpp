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

int n;

void solve() {
    cin >> n;
    vector<int> bits(31);

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        for (int j = 0; j < 31; j++) bits[j] += ((x & 1 << j) > 0);
    }
    
    dump(bits);

    vector<int> ans;
    for (int i = 1; i <= n; i++){
        bool ok = true;
        for (int j = 0; j < 31; j++) ok &= (bits[j] % i == 0);
        if (ok) ans.push_back(i);
    }

    for (const auto x : ans) cout << x << " ";
    cout << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}