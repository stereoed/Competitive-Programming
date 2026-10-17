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
vector<int> SIZE_OF_SUBTREE;
vector<bool> SEEN;

int dfs(int k){
    int o = 1;
    
    for (auto x : ADJ[k]){
        if (SEEN[x]) continue;
        SEEN[k] = true;
        o += dfs(x);
    }
    return SIZE_OF_SUBTREE[k] = o;
}

void solve(){
    cin >> N;
    ADJ = vector<vector<int>>(N + 1);
    SIZE_OF_SUBTREE = vector<int>(N + 1);
    SEEN = vector<bool>(N + 1);
    
    for (int i = 0; i < N - 1; i++){
        int a, b; cin >> a >> b;
        ADJ[a].push_back(b);
        ADJ[b].push_back(a);
    }
    
    if (N % 2){
        cout << "-1\n";
        return;
    }
    
    SEEN[1] = true;
    std::ignore = dfs(1);
    
    int ans = 0;
    for (auto x : SIZE_OF_SUBTREE) if (x > 0 && x % 2 == 0) ans++;
    cout << ans - 1 << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}