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

long long n, k;

bool ok(int mid, const vector<long long>& v){
    vector<long long> v2(mid);
    for (int i = 0; i < mid; i++) v2[i] = v[i];
    sort(v2.rbegin(), v2.rend());

    long long h = k;
    for (int i = 0; i < mid; i += 2){
        h -= v2[i];
        if (h < 0) return false;
    }
    return h >= 0;
}

void solve() {
    cin >> n >> k;
    vector<long long> v(n);
    for (auto& x : v) cin >> x;

    int l = 0, r = n;

    while (l < r){
        int mid = l + (r - l + 1) / 2;
        if (ok(mid, v)) l = mid;
        else r = mid - 1;
    }

    cout << l << '\n';    
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}