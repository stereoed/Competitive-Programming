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
    int n, l, r; cin >> n >> l >> r; dump(n, l ,r);
    vector<int> ans(n + 1);

    for (int i = 1; i <= n; i++){
        ans[i] = l + (l % i ? (i - (l % i)) : 0);
        if (ans[i] > r){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}
