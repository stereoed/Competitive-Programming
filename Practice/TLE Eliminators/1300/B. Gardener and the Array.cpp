#pragma GCC optimize("Ofast")
using namespace std;
#include <bits/stdc++.h>

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(v) v.begin(), v.end()

long long n;

void solve() {
    cin >> n;
    vector<vector<int>> mat(n);
    map<int, int> seen;

    for (int i = 0; i < n; i++){
        int k; cin >> k;
        for (int j = 0; j < k; j++){
            int x; cin >> x;
            seen[x]++;
            mat[i].push_back(x);
        }
    }


    for (const auto& v : mat){
        bool all_seen = true;
        for (const auto x : v){
            if (seen[x] == 1){
                all_seen = false;
                break;
            }
        }

        if (all_seen){
            cout << "YES\n";
            return;
        }
    }


    cout << "NO\n";
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}