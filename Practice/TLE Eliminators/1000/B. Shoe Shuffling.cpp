#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif


void solve() {
    long long n; cin >> n;
    vector<long long> v(n);
    for (auto& x : v) cin >> x;
    
    int cnt = 1;
    for (int i = 1; i < n; i++){
        if (v[i] != v[i-1]){
            if (cnt == 1){
                cout << "-1\n";
                return;
            }
            cnt = 0;
        }
        cnt++;    
    }

    if (n == 1 || cnt == 1){
        cout << "-1\n";
        return;
    }

    int start = 1;
    for (int i = 1; i < n; i++){
        if (v[i] != v[i-1]){
            cout << start << ' ';
            start = i + 1;
        } else {
            cout << (i + 1) << " ";
        }
    }

    cout << start << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}