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
    vector<vector<int>> ar(n), anr(n);
    vector<int> ans;
    queue<int> q;

    for (int i = 0; i < n; i++){
        int parent, nrespect; cin >> parent >> nrespect; 

        if (parent == -1){
            q.push(i);
            continue;
        }

        parent--;
        if (nrespect) anr[parent].push_back(i);
        else ar[parent].push_back(i);
    }

    while (!q.empty()){
        int u = q.front(); q.pop();
        for (auto v : ar[u]) q.push(v);

        for (auto v : anr[u]){
            if (ar[v].empty()) ans.push_back(v);
            q.push(v);
        }
    }

    if (ans.empty()){
        cout << "-1\n";
        return;
    }

    sort(ans.begin(), ans.end());
    for (auto x : ans) cout << x + 1<< ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}