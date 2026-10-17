#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

int N;

void solve(){
    cin >> N;
    vector<pair<pair<int, int>, int>> E(N);
    for (int i = 1; i <= N; i++){
        int a, b; cin >> a >> b;
        E[i - 1] = {{a, b}, i};
    }
    sort(E.begin(), E.end());
    
    for (int i = 1; i < N; i++){
        if (E[i].first.first == E[i - 1].first.first){
            cout << E[i - 1].second << " " << E[i].second << "\n";
            return;
        }
        
        if (E[i - 1].first.second >= E[i].first.second){
            cout << E[i].second << " " << E[i - 1].second << "\n";
            return;
        }
    }
    
    cout << "-1 -1\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}