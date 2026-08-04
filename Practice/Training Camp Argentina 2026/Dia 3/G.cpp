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

int n, m;

const int MAXN = 7 * 1e5;
vector<pair<int, int>> cola(MAXN);
int top = 0, bottom = 0;

map<int, int> id;

struct BIT {
    int n;
    vector<int> t;
    BIT(int n = 0) { init(n); }
    void init(int n_) {
        n = n_;
        t.assign(n + 2, 0);
    }
    void add(int i, int v) {
        for (; i <= n; i += i & -i) t[i] += v;
    }
    int sum(int i) {
        int r = 0;
        for (; i > 0; i -= i & -i) r += t[i];
        return r;
    }
    int rangeSum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    int N = n + m;

    BIT bit(N);
    vector<pair<int,int>> mima(n + 1);   // {min, max}
    vector<pair<int,int>> latest(n + 1); // {BIT position, idx}

    for (int i = 1; i <= n; ++i) {
        mima[i] = {i, i};
        latest[i] = {n - i + 1, i};
        bit.add(n - i + 1, 1);
    }

    int nextPos = n + 1;

    for (int i = 0; i < m; ++i) {
        int x; cin >> x;

        mima[x].first = 1;
        int p = latest[x].first;

        int curPos = bit.rangeSum(p + 1, N) + 1;
        mima[x].second = max(mima[x].second, curPos);

        bit.add(p, -1);
        latest[x].first = nextPos;
        bit.add(nextPos++, 1);
    }

    sort(all(latest));
    for (int i = 1; i <= n; ++i) {
        const auto& [pos, num] = latest[i];
        mima[num].second = max(mima[num].second, n - i + 1);
    }

    for (int i = 1; i <= n; ++i) {
        cout << mima[i].first << ' ' << mima[i].second << el;
    }
}

int main() {
    FastIO;
    int t = 1; //cin >> t;
    while (t--) solve();
}