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
    vector<int> V(N);
    for (auto& x : V) cin >> x;

    vector<vector<int>> ADJ(N);
    for (int i = 1; i < N; i++){
        int a, b; cin >> a >> b; a--; b--;
        ADJ[a].push_back(b);
        ADJ[b].push_back(a);
    }

    bool unique = true;
    vector<int> stk;

    for (int i = 0; i < N; i++) if (ADJ[i].size() >= 2 && V[i] > 1) stk.push_back(i);
    while (stk.size()){
        auto idx = stk.back(); stk.pop_back();
        if (ADJ[idx].size() > 2){
            unique = false;
            break;
        }

        int to_distribute = V[idx] / 2;
        V[idx] -= 2 * to_distribute;

        if (to_distribute){
            for (auto nxt : ADJ[idx]){
                if (ADJ[nxt].size() >= 2) {
                    V[nxt] += to_distribute;
                    if (V[nxt] > 1) stk.push_back(nxt);
                }
            }
        }
    }

    cout << "termina\n";
    cout << (unique ? "" : "no ") << "unico\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}
