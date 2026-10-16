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
    int N, Q; cin >> N;
    vector<pair<int, char>> V(N);

    int P = 0;
    for (auto& [p, c] : V){
        cin >> c >> p; 
        P += p;
        p = P;
    }

    cin >> Q;
    for (int i = 0; i < Q; i++){
        int a; cin >> a;

        int l = 0, r = N - 1;
        while (l < r){
            int mid = l + (r - l) / 2;
            if (V[mid].first >= a) r = mid;
            else l = mid + 1; 
        }
        cout << V[l].second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}