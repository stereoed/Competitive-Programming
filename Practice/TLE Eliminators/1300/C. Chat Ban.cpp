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

long long k, x;

long long ssum(long long R){
    return R * (R + 1) / 2;
}

long long get_sum(long long mid){
    long long sum = ssum(min(k, mid));
    if (mid > k) {
        sum += ssum(k - 1);
        sum -= ssum(2 * k - 1 - mid);
    }
    return sum;
}

void solve() {
    cin >> k >> x;
    long long l = 0, r = 2 * k - 1;
    while (l < r){
        long long mid = l + (r - l + 1)/2;
        if (get_sum(mid) <= x) l = mid;
        else r = mid - 1;
    }
    if (l < 2 * k - 1 && get_sum(l) < x) l++;
    cout << l << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}