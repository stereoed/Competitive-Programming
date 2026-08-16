#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

int n, k;
void solve(){
    cin >> n >> k;
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    sort(v.begin(), v.end());

    int ans = 1, cnt = 1;
    for (int i = 1; i < n; i++){
        if (v[i] - v[i-1] > k) {
            ans = max(ans, cnt);
            cnt = 1;
        }
        
        else{
            cnt++;
        }
    }

    ans = max(ans, cnt);
    cout << n - ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}