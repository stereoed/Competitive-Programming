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

int g;

long long C(int n, int r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

void solve() {
    cin >> g;
    long long cnt_zero = 0, cnt_one = 0;
    for (int i = 0; i < g; i++){
        int x; cin >> x;
        cnt_one += x == 1;
        cnt_zero += x == 0;
    }

    dump(cnt_one, cnt_zero);

    long long ans = 0;
    for (int i = 0; i <= cnt_zero; i++) {
        dump(i, C(cnt_zero, i));
        ans += C(cnt_zero, i);
    }
    cout << ans * cnt_one << '\n';
}

int main() {
    FastIO;
    int t = 1; cin >> t;
    while (t--) solve();
}