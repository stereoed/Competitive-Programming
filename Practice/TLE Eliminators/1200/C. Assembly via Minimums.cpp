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
    int ns = n * (n - 1) / 2; dump(ns);
    vector<int> v(ns);

    for (auto& x : v) cin >> x;
    sort(v.begin(), v.end()); dump(v);

    int i = 0, step = n;
    while (i < ns){
        dump(i, step, v[i]);
        cout << v[i] << " ";
        i += --step;
    }

    cout << v[ns-1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}