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
    int n, k; cin >> n >> k;
    vector<long long> v(n);
    for (auto& x : v) cin >> x;

    if (k >= 3) {
        cout << "0\n";
        return;
    }

    sort(v.begin(), v.end());
    dump(v);
    long long ans = v[0];
    
    for (int i = n - 1; i > 0; i--){
        ans = min(ans, v[i] - v[i - 1]); dump(v[i], v[i - 1], v[i] - v[i - 1]);

        if (k == 2) {
            

            for (int j = i - 1; j >= 0; j--){
                long long dif = v[i] - v[j]; dump(dif);
                auto it = lower_bound(v.begin(), v.end(), dif);
                if (it != v.end()) ans = min(ans, *it - dif);
                if (it != v.begin()) ans = min(ans, dif - *(it - 1));
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}