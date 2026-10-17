#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

const int M = 1000000007;

#define print_ok(b) cout << (b ? "YES\n" : "NO\n");

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    long long cnt_pos = 0, cnt_neg = 0;
    for (auto c : s) cnt_pos += c == '+';
    cnt_neg = n - cnt_pos;

    int q; cin >> q;
    for (int i = 0; i < q; i++){
        long long x, y; cin >> x >> y;

        if (x == y || cnt_pos == cnt_neg){
            print_ok(cnt_pos == cnt_neg);
            continue;
        }

        if (x > y) swap(x, y);
        if (cnt_neg < cnt_pos) swap(x, y);

        long long aux = x * cnt_neg - y * cnt_pos;
        print_ok(aux % (x - y) == 0 &&
                aux / (x - y) <= min(cnt_neg, cnt_pos) && aux / (x - y) >= 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}