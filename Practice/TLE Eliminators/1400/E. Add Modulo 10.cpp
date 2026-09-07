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
    int n; cin >> n;
    vector<int> v(n);

    bool five = false;
    for (auto& x : v){
        cin >> x;

        if (x % 10 == 5 || x % 10 == 0) {
            x += x % 10; 
            five = true;
        }

        else while (x % 10 != 2){
            x += x % 10;
        }
    }
    
    if (five){
        v.erase(unique(v.begin(), v.end()), v.end());
        cout << (v.size() == 1 ? "Yes\n" : "No\n");
        return;
    }

    sort(v.begin(), v.end());
    bool ok = true;
    for (int i = 1; i < n; i++) ok &= (v[i] - v[i - 1]) % 20 == 0;
    
    cout << (ok ? "Yes\n" : "No\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}