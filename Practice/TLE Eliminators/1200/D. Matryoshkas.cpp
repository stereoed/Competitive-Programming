#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

long long n, q;
void solve(){
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    dump(arr);

    int ans = 0;
    map<int, int> cnt;

    for (int i = 0; i < n; i++){
        dump(ans, arr[i], cnt[arr[i] - 1]);
        if (cnt[arr[i] - 1] > 0) cnt[arr[i] - 1]--;
        else ans++;
        cnt[arr[i]]++;
    }

    

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}