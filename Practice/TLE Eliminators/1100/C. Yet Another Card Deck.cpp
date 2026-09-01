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
    int n, q; cin >> n >> q;
    vector<int> cards(51, n + 5);
    for (int i = 1; i <= n; i++){
        int a; cin >> a;
        cards[a] = min(cards[a], i);
    }

    for (int i = 1; i <= q; i++){
        int a; cin >> a; dump(a, cards[a]);
        cout << cards[a] << ' ';
        
        for (int j = 1; j <= 50; j++) if (cards[j] < cards[a]) cards[j]++;
        cards[a] = 1;
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}