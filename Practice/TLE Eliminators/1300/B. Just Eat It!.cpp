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

long long n;

void solve() {
    cin >> n;
    vector<int> v(n);
    bool ok = true;

    long long sum = 0;
    for (auto& x : v) {
        cin >> x;
        sum += x;
        if (sum <= 0) ok = false;
    }

    sum = 0;
    for (int i = n - 1; i >= 0; i--){
        sum += v[i];
        if (sum <= 0) ok = false;
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}