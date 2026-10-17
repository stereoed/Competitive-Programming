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
vector<vector<int>> ADJ;
vector<bool> seen;
int open, closed;

void dfs(int i){
    seen[i] = true;
    while (ADJ[i].size()){
        auto nxt = ADJ[i].back(); ADJ[i].pop_back();
        if (seen[nxt]) continue;
        dfs(nxt);
    }
}

void solve(){
    cin >> N; 
    ADJ.assign(N, vector<int>());
    seen.assign(N, false);
    open = 0;
    closed = 0;

    for (int i = 0; i < N; i++) {
        int x; cin >> x; x--;
        ADJ[x].push_back(i);
        ADJ[i].push_back(x);
    }

    for (int i = 0; i < N; i++){
        sort(ADJ[i].begin(), ADJ[i].end());
        ADJ[i].erase(unique(ADJ[i].begin(), ADJ[i].end()), ADJ[i].end());
    }

    dump(ADJ);

    for (int i = 0; i < N; i++){
        if (seen[i] || ADJ[i].size() % 2 == 0) continue;
        dfs(i);
        open++;
    }

    for (int i = 0; i < N; i++){
        if (seen[i]) continue;
        dfs(i);
        closed++;
    }

    dump(closed, open);
    cout << closed + (open > 0) << ' ' << closed + open << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}