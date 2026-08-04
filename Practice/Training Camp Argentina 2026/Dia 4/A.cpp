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

int n;

void solve() {
    cin >> n;
    vector<int> arr(n);

    int ma = 0;
    for (auto& x : arr) {
        cin >> x;
        ma = max(ma, x);
    }

    dump(arr)
    int cnt = 0, cur = arr[n - 1];
    dump(ma, cur, cnt)

    for (int i = n - 1; i >= 0; i--){
        int cand = arr[i];
        dump(cur, cand, cur == ma)

        if (cur == ma){
            dump("break")
            break;
        }

        dump(cand > cur)
        if (cand > cur){
            cur = cand;
            cnt++;
        }
    }

    cout << cnt << el;
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}
