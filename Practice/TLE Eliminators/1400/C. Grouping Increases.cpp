#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

void solve(){
    int n; cin >> n;
    int f1 = 1e9, f2 = 1e9;

    int ans = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;

        if (x <= f1) f1 = x;
        else if (x <= f2) f2 = x;
        else {
            f1 = x;
            ans++;
        }

        if (f2 < f1) swap(f1, f2);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}