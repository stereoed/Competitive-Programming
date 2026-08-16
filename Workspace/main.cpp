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

const long long MOD = 998244353;
vector<vector<long long>> base = {{1, 1}, {1, 0}};

void square(){
    const vector<vector<long long>> copy = base;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            long long sum = 0;
            for (int x = 0; x < 2; x++) {
                sum += (copy[i][x] * copy [x][j]) % MOD;
                sum %= MOD;
            }
            base[i][j] = sum;
        }
    }
    dump(base);
}

long long FN = 1, FNm1 = 0, n;
void solve() {
    cin >> n;

    while (n){
        if (n&1){
            const int aux = FN;
            FN = base[0][0] * FN + base[0][1] * FNm1;
            FNm1 = base[1][0] * aux + base[1][1] * FNm1;

            FN %= MOD;
            FNm1 %= MOD;
            dump(FN, FNm1);
        }

        n /= 2;
        square();
    }

    cout << FNm1 << '\n';
}

int main() {
    FastIO;
    dump(base);
    int t = 1; //cin >> t;
    while (t--) solve();
}