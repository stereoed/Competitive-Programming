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
vector<int> v, b, c;
string s, s1, s2;

void solve(){
    cin >> n;
    v.assign(n, 0);
    b.clear();
    c.clear();

    int mx = 0;
    for (auto& x : v){
        cin >> x;
        mx = max(x, mx);
    }

    for (const int x : v){
        if (x == mx) c.push_back(x);
        else b.push_back(x);
    }

    if (b.empty()){
        cout << "-1\n";
        return;
    }

    cout << b.size() << " " << c.size() << '\n';
    for (const int x : b) cout << x << " ";
    cout << '\n';
    for (const int x : c) cout << x << " ";
    cout << '\n';    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
