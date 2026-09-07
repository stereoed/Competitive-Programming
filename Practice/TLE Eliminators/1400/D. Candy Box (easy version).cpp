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
    vector<long long> cnt(n + 1);
    for (int i =0; i < n; i++){
        int a; cin >> a; cnt[a]++;
    }

    sort(cnt.rbegin(), cnt.rend()); dump(cnt);

    long long ans = 0 , prev = 1e9;
    for (int i = 0; i < n; i++){
        prev = min(cnt[i], prev - 1); 

        if (prev == 0) break;
        ans += prev;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}