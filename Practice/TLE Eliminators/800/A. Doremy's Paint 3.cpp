#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

int n, m;
vector<int> arr;
string s;

void solve(){
    bool ok = true;

    cin >> n;
    arr.assign(n, 0);

    for (auto& x : arr) {
        cin >> x;
    }

 
    sort(arr.begin(), arr.end());
    map<int, int> cnt;

    for (const auto x : arr){
        cnt[x]++;
    }

    ok &= (cnt.size() <= 2);
    
    if (cnt.size() == 2){
        int a = arr[0], b = arr[n-1];
        ok &= (abs(cnt[a] - cnt[b]) <= 1);
    }    

    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}