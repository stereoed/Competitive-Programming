#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

vector<int> v;

bool test(int x){
    int l = 0, r = v.size() - 1;

    while (l < r){
        while (l < r && v[l] != v[r]){
            if (v[l] != x && v[r] != x) return false;
            if (v[l] == x) l++;
            else r--;
        }

        l++;
        r--;
    }

    return true;
}

void solve(){
    int n; cin >> n;
    v.assign(n, 0);
    for (auto& x : v) cin >> x;

    int l = 0, r = n - 1;
    while (l < r){
        if (v[l] != v[r]){
            if (test(v[l])) break;
            if (test(v[r])) break;
            cout << "NO\n";
            return;
        
        }
        l++;
        r--;
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}