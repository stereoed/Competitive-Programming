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

void solve(){
    cin >> n >> m;
    dump(n, m);
    arr.assign(n, 0);
    for (auto& k : arr) cin >> k;
    
    int ans1 = 2 * m;
    int ans2 = arr[0];

    for (int i = 0; i < n; i++){
        dump(i, arr[i]);

        if (i > 0 && arr[i] < m){
            dump(ans2, (arr[i] - arr[i-1]));
            ans2 = max(ans2, (arr[i] - arr[i-1]));
        }

        if (i > 0  && arr[i] > m) {
            dump(ans2, 2*(m - arr[i-1]));
            ans2 = max(ans2, 2*(m - arr[i-1]));
        }

        if (i == n - 1) {
            dump(ans2, 2*(m - arr[i]));
            ans2 = max(ans2, 2*(m - arr[i]));
        }
    }

    cout << min(ans1, ans2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}