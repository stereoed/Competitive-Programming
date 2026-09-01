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
void solve() {
    cin >> n;
    vector<long long> v(n);
    map<long long, int> seen;

    long long sum = 0;
    for (auto& x : v) { 
        cin >> x;
        seen[x]++;
        sum += x;
    }

    vector<long long> ans;
    for (int i = 0; i < n; i++){
        long long val = sum - v[i];
        if (val & 1 || seen[val / 2] == 0) continue;
        if (seen[val / 2] == 1 && val == 2 * v[i]) continue; // i.e, we delete the biggest number, and then query if its also there
        ans.push_back(i + 1);
    }

    cout << ans.size() << '\n';
    for (const auto x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}