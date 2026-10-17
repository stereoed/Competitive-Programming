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

void solve() {
    int N; cin >> N;
    vector<int> X(N), T(N);

    for (auto& x : X) cin >> x;
    for (auto& t : T) cin >> t;

    double l = -1e9, r = 1e9;
    for (int i = 0; i < N; i++){
        l = max<double>(l, X[i] + T[i]);
        r = min<double>(r, X[i] - T[i]);
    }

    cout << setprecision(10) << l + (r - l) / 2 << '\n';
}

int main() {
    FastIO;

    int t = 1; cin >> t;
    while (t--) solve();
}