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
    int N; cin >> N;
    vector<vector<int>> ADJ(N);
    vector<int> ANS(N - 1, -1);

    for (int i = 0; i < N - 1; i++){
        int a, b; cin >> a >> b; a--; b--;
        ADJ[a].push_back(i);
        ADJ[b].push_back(i);
    }

    int cur = 0;
    for (auto& E : ADJ){
        if ((int)E.size() < 3) continue;
        
        for (int i = 0; i < 3; i++) ANS[E[i]] = i;
        

        cur = 3;
        break;
    }

    for (auto x : ANS) cout << (x == -1 ? cur++ : x) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}