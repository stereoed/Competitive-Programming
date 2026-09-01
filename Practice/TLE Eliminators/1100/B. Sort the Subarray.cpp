#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

int x, prev;
void solve(){
    int n; cin >> n;
    vector<int> A(n), B(n);
    for (auto& x : A) cin >> x;
    for (auto& x : B) cin >> x;

    int i = 0;
    for (; i < n; i++) if (A[i] != B[i]) break;

    int l = i, r = i;
    while (l > 0 && B[l - 1] <= B[l]) l--;
    while (r < n - 1 && B[r] <= B[r + 1]) r++;


    cout << l + 1 << ' ' << r + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}