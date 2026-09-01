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
vector<bool> valid(1e6 + 1, false);

void solve() {
    cin >> n; n--;
    
    if (valid[n]) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main() {
    FastIO;
    
    for (int i = 2; i <= 1e3; i++){
        if (i == 4) dump(i * i + i);
        int x = i * i + i;
        while (x <= 1e6) {
            valid[x] = true;
            x *= i;
            x += i;
        }
    }

    dump(valid);

    int t = 1; cin >> t;
    while (t--) solve();
}