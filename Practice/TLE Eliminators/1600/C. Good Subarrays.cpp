#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
#include "cpp-dump.hpp"
#define dump(...) cpp_dump(__VA_ARGS__);
#else
#define dump(...)
#endif

vector<vector<int>> ADJ;
vector<int> D, S, G;

int build(int node, int depth, int parent){
    D[node] = depth;

    S[node] = 1;
    for (auto nxt : ADJ[node]){
        if (nxt == parent) continue;
        S[node] += build(nxt, depth + 1, node);
    }

    return S[node];
}

void solve(){
    int N; cin >> N;
    string S; cin >> S;
    map<int, int> cnt;
    cnt[0] = 1;

    long long ans = 0, sum = 0;
    
    for (int i = 0; i < N; i++){
        int num = S[i] - '0';
        sum += num;

        ans += cnt[sum - (i + 1)]++;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}