#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

/*
void solve() {
    int n, k; cin >> n >> k;

    int ans = k;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        ans = min(ans, (k - x%k)%k);
    }

    cout << ans << '\n';
}
*/

void solve() {
    int n; char c; string s;
    cin >> n >> c >> s;

    n += n;
    s += s;
    dump(n, c, s);

    int ans = 0;
    int cnt = -1;
    for (char ch : s){
        dump(ch, cnt, ans);
        if (cnt == -1) {
            if (ch == c) cnt = 0;
            else continue;
        }

        if (ch == 'g') {
            ans = max(ans, cnt);
            cnt = -1;
            continue;
        }

        cnt++;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}