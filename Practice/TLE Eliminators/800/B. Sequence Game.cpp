#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

int n, m;
vector<int> v, ans;
string s, s1, s2;

void solve(){
    cin >> n;
    v.assign(n, 0);
    ans.clear();

    for (auto& x : v){
        cin >> x;
    }

    ans.push_back(v[0]);
    for (int i = 1; i < n; i++){
        if (v[i] < v[i-1]) ans.push_back(1);
        ans.push_back(v[i]);
    }

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
