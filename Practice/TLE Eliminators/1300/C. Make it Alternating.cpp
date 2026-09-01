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
string s;
const int MOD = 998244353;
vector<long long> factorial(1e6 + 5);

void solve() {
    cin >> s;

    char prev = 'x';
    int cnt = 0;
    long long ans1 = 0, prod = 1;

    for (const auto c : s){
        if (prev != c) {
            if (cnt > 1){
                ans1 += cnt - 1;
                prod = prod * cnt % MOD;
            }
            cnt = 0;
            prev = c;
        }
        cnt++;
    }

    if (cnt > 1){
        ans1 += cnt - 1;
        prod = prod * cnt % MOD;
    }

    long long ans2 = factorial[ans1] * prod % MOD;
    cout << ans1 << " " << max<long long>(ans2, 1) << '\n';
}

int main() {
    FastIO;
    
    factorial[0] = 1;
    for (int i = 1; i < 1e6 + 5; i++){
        factorial[i] = (factorial[i-1] * i) % MOD;
    }

    int t = 1; cin >> t;
    while (t--) solve();
}