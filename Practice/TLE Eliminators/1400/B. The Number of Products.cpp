#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

int n;
void solve(){
    cin >> n;
    long long total = 1LL * (n + 1) * (n) / 2;
    long long positive = 0;

    int cnt[2] = {1, 0};
    int parity = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        parity ^= (x < 0);
        positive += cnt[parity]++;
    }

    cout << total - positive << ' ' << positive << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}