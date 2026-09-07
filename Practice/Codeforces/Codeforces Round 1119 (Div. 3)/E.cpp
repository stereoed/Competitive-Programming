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
    for (auto& x : v) cin >> x;
    vector<int> tl_0(n, 1e8), tr_0(n, 1e8);
    vector<bool> can_zero(n, true);

    int right_most = -1;
    for (int i = 0; i < n; i++){
        if (v[i] != -1) right_most = i + v[i];
        can_zero[i] = (i >= right_most);
    }

    int left_most = n;
    for (int i = n - 1; i >= 0; i--){
        if (v[i] != -1){
            left_most = i - v[i];
        }
        
        if (can_zero[i] && (i <= left_most)) v[i] = 0;
        
        if (v[i] == 0) tr_0[i] = 0;
        else if (i < n - 1) tr_0[i] = tr_0[i+1] + 1;
    }

    for (int i = 0; i < n; i++){
        if (v[i] == 0) tl_0[i] = 0;
        else if (i > 0) tl_0[i] = tl_0[i-1] + 1;
    }

    for (int i = 0; i < n; i++){
        if (v[i] == -1) v[i] = min(tl_0[i], tr_0[i]);
        if (v[i] != min(tl_0[i], tr_0[i]) || ((i > 0) && (v[i] - v[i - 1] > 1))){ 
            dump("No", i, v[i], tl_0[i], tr_0[i])
            cout << "-1\n";
            return;
        }
    }

    for (auto x : v) cout << (x == 0 ? 1 : 0);
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}