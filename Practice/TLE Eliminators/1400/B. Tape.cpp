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
    int n, m, k; cin >> n >> m >> k;
    vector<int> dif;
    int prev = -1;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (prev != -1){
            dif.push_back(x - prev - 1);
        }
        prev = x;
    }

    long long ans = n;
    sort(dif.begin(), dif.end());
    for (int i = 0; i < n - k; i++){
        ans += dif[i];
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}