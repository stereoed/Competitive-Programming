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
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end()); dump(v);


    vector<char> ans(n, 'C');
    int mex_A = 0, mex_B = 0, mex_C = 0;
    for (int i = 0; i < n; i++){
        auto& [c, id] = v[i];

        if (c == mex_A){
            if (mex_A <= mex_C){
                mex_A++;
                ans[id] = 'A';
            } else {
                break;
            }            
        }
        
        else if (c == mex_B){
            mex_B++;
            ans[id] = 'B';
        }

        else if (c == mex_C){
            mex_C++;
            ans[id] = 'C';
        }
    }

    dump(mex_A, mex_B, mex_C)
    if (mex_A + mex_B + mex_C < 2 * max({mex_A, mex_B, mex_C})){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (auto c  : ans) cout << c;
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}