#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

long long n, q;
vector<int> v; 

//freq of the second most repeated card?

void solve(){
    cin >> n;
    v.assign(1001, 0);

    int ans = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        v[x]++;
        ans += x;
    }

    int max_freq = 0;
    for (int i = 0; i < 1001; i++){
        if (v[max_freq] < v[i]) max_freq = i;
    }

    ans -= max<int>(0, v[max_freq] - (n - v[max_freq]) - 2) * max_freq;  
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}