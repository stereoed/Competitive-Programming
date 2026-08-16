#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

long long n, m;
string s;

void solve(){
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    
    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());

    int ans = min((int)v.size(), 2);
    for (int i = 1; i < (int)v.size() - 1; i++){
        if ((v[i] - v[i-1] < 0) != (v[i+1] - v[i] < 0)) ans++;
    }

    cout << ans  << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}