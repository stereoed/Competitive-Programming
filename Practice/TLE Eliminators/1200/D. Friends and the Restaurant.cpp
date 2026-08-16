#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

long long n, y, aux;



void solve(){
    cin >> n;
    vector<int> z(n);
    for (auto& x : z) {
        cin >> aux;
        x = -aux;
    }

    for (auto& x : z) {
        cin >> aux;
        x += aux;
    }

    sort(z.begin(), z.end());

    int ans = 0, l = 0, r = n - 1;
    while (l < r){
        int total = z[l] + z[r];
        if (total >= 0){
            r--;
            ans++;
        }
        l++;
    }
    cout << ans << '\n';    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}