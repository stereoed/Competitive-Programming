#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const int MOD = 1e9 + 7;

void solve(){
    long long n, c; cin >> n >> c;
    vector<long long> cost(n);
    for (int i = 0; i < n; i++){
        cin >> cost[i];
        cost[i] += (i + 1);
    }
    sort(cost.begin(), cost.end());
    if (cost[0] > c){
        cout << 0 << '\n';
        return;
    }

    for (int i = 1; i < n; i++) {
        cost[i] += cost[i - 1];
        if (cost[i] > c){
            cout << i << '\n';
            return;
        }
    }
    cout << n << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}