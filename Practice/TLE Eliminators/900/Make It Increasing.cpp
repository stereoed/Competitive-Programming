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
    for (auto& x : v) cin >> x;

    int ans = 0;

    for (int i = n - 2; i >= 0; i--){
        while (v[i] != 0 && v[i] >= v[i + 1]){
            v[i] /= 2;
            ans++;
        }

        if (v[i] >= v[i + 1]){
            cout << "-1\n";
            return;
        }
    }

    cout << ans << '\n';
}

int main() {
    FastIO;

    int t = 1; cin >> t;
    while (t--) solve();
}