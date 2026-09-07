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
    int cnt[3]{};

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x%2) cnt[1]++;
        else {
            if ((x / 2) % 2) cnt[2]++;
            else cnt[0]++;
        }
    }

    cout << max({cnt[0], cnt[1], cnt[2]}) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}