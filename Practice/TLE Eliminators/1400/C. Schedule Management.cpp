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
    int n, m; cin >> n >> m;
    vector<int> v(n);

    for (int i = 0; i < m; i++){
        int a; cin >> a; a--;
        v[a]++;
    }

    long long l = 0, r = 2 * m;
    while(l < r){
        long long mid = l + (r - l) / 2;
        
        long long comodin = 0;
        long long remaining = 0;
        for (auto x : v){
            if (mid < x) remaining += x - mid;
            else comodin += (mid - x) / 2;            
        }

        if (comodin >= remaining) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}