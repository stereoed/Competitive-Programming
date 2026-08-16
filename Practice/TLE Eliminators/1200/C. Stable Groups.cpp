#pragma GCC optimize("Ofast")
using namespace std;

#if __has_include("stdc++.h")
    #include "stdc++.h"
#else
    #include <bits/stdc++.h>
#endif

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define el '\n'

long long n, k, x;
void solve() {
    cin >> n >> k >> x;
    vector<long long> v(n);

    for (auto& aux : v) cin >> aux;
    sort(v.begin(), v.end());

    vector<long long> group_differences;
    for (int i = 1; i < n; i++){
        if (v[i] - v[i-1] > x) group_differences.push_back((v[i] - v[i-1] + x -  1)/x);
    }
    sort(group_differences.rbegin(), group_differences.rend());
    
    while (!group_differences.empty() && group_differences.back() <= k){
        k -= group_differences.back();
        group_differences.pop_back();
    }

    cout << group_differences.size() + 1 << '\n';
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}