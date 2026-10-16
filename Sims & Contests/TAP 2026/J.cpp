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
string S;

vector<vector<int>> memo_lr, memo_lk;
bool can(int l, int r){
    if (l >= r || (r - l + 1) %  3) memo_lr[l][r] = (l > r);
    if (memo_lr[l][r] != 2) return memo_lr[l][r] == 1;

    for (int k = l + 1; k <= r; k++){
        if (memo_lk[l][k] == 2){
            bool ok = false;

            for (int j = l + 1; j < k; j += 3){
                bool prereq = can(l + 1, j - 1) && can(j + 1, k - 1);
                bool req = (S[l] != S[j]) && (S[j] != S[k]) && (S[k] != S[l]);
                ok |= prereq && req;
                if (ok) break;
            }

            memo_lk[l][k] = ok;
        }

        if (memo_lk[l][k] == 1 && can(k + 1, r)) {
            dump(l, k, r);
            memo_lr[l][r] = 1;
            return memo_lr[l][r] == 1; 
        }
    }
    
    memo_lr[l][r] = 0;
    return memo_lr[l][r] == 1; 
}

void solve(){
    cin >> S;
    N = S.size();

    memo_lr.assign(N + 1, vector<int>(N + 1, 2));
    memo_lk.assign(N + 1, vector<int>(N + 1, 2));

    cout << (can(0, N - 1) ? "S\n" : "N\n");

    dump(memo_lk);
    dump(memo_lr);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}