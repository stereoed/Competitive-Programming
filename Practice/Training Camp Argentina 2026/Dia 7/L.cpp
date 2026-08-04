#pragma GCC optimize("Ofast")
using namespace std;

#if __has_include("stdc++.h")
    #include "stdc++.h"
#else
    #include <bits/stdc++.h>
#endif

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define repf(i,k,n) for(int i=k; i<n; i++)
#define rep(i,n) for(int i=0; i<n; i++)
#define el '\n'

int n, m;

void solve(){
    cin >> n;
    
    vector<vector<int>> logs(n + 1);
    for (int i = 0; i < n; i++){
        int person, bid; cin >> person >> bid;
        logs[person].push_back(bid);
    }

    set<pair<int, int>> active;
    vector<int> removed(n + 1);

    for (int person = 1; person <= n; person++){
        if (!logs[person].empty()) active.insert({logs[person].back(), person});
    }

    cin >> m;
    for (int i = 0; i < m; i++){
        int k; cin >> k;

        for (int x = 0; x < k; x++){
            cin >> removed[x];
            if (!logs[removed[x]].empty())
                active.erase({logs[removed[x]].back(), removed[x]});
        }

        if (active.empty()){
            cout << "0 0" << el;
        } else {
            const auto [mx, winner] = *active.rbegin();
            const auto& bids = logs[winner];
            removed[k++] = winner;

            active.erase(*active.rbegin());
            if (active.empty()){
                cout << winner << " " << bids.front() << el;
            } else {
                cout << winner << " " << *upper_bound(all(bids), active.rbegin()->first) << el;
            }
        }

        for (int x = 0; x < k; x++){
            if (!logs[removed[x]].empty()) active.insert({logs[removed[x]].back(), removed[x]});
        }
    }
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}