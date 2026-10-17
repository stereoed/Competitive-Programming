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

void solve() {
    int N; cin >> N;
    int l = 1, r = N;

    while (l < r){
        int mid = l + (r - l) / 2;
        cout << "? " << l << ' ' << mid << endl;
        dump(l, mid, r);
        
        int cnt = 0;
        for (int i = 0; i < mid - l + 1; i++){
            int x; cin >> x;
            cnt += (l <= x && x <= mid);
        }

        dump(cnt);
        if (cnt & 1) r = mid;
        else l = mid + 1;
    }

    cout << "! " << l << endl;
}

int main() {
    FastIO;

    int t = 1; cin >> t;
    while (t--) solve();
}