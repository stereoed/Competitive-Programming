#pragma GCC optimize("Ofast")
using namespace std;

#if __has_include("stdc++.h")
    #include "stdc++.h"
#else
    #include <bits/stdc++.h>
#endif

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define el '\n'

long long n, q;

void solve() {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 1) v[i]++;
        if (i > 0 && v[i] % v[i-1] == 0) v[i]++;
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';    
}

int main() {
    FastIO;

    int t = 1; cin >> t;
    while (t--) solve();
}