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
    vector<int> v(n), mtn(n, 1e9);
    for (auto& x : v) cin >> x;

    mtn[n-1] = n-1;
    for (int i = n-2; i >= 0; i--) {
        if (v[mtn[i + 1]] > v[i]) mtn[i] = i;
        else mtn[i] = mtn[i + 1];
    }

    int mtn_f = 0;
    for (int i = 1; i < n; i++){
        if (v[mtn_f] > v[i]) mtn_f = i;
        else if (v[mtn[i]] < v[i]){
            cout << "YES\n";
            cout << mtn_f + 1<< " " << i + 1 << " " << mtn[i] + 1 << '\n';
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