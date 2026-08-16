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
    int l = 0, r = n-1;

    vector<int> v(n);
    set<int> left;

    for (auto& x : v) {
        cin >> x;
        left.insert(x);
    }

    while(l < r){
        int mx = *left.rbegin();
        int mn = *left.begin();

        if (v[l] == mn || v[l] == mx){
            left.erase(v[l++]);
            continue;
        }

        if (v[r] == mn || v[r] == mx){
            left.erase(v[r--]);
            continue;
        }

        cout << l + 1 << " " << r + 1 << '\n';
        return;
    }

    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}