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

int n, k;
void solve() {
    cin >> n >> k;

    long long base = (1LL << 31) - 1;

    vector<int> bit_cnt(31);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        for (int j = 0; j <= 30; j++) bit_cnt[j] += ((x & (1 << j)) > 0);
        base &= x;
    } dump(base, bit_cnt);

    int other = 0;
    for (int i = 30; i >= 0; i--){
        if (n - bit_cnt[i] <= k){
            other |= (1 << i);
            k -= n - bit_cnt[i];
        }
    } dump(other);

    cout << (base | other) << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}