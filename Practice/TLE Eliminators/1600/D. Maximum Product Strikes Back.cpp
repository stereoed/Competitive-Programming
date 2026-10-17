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
    vector<int> V(N + 1), P(N + 1), NEG(N + 1), R;

    for (int i = 1; i <= N; i++) {
        cin >> V[i];
        P[i] = abs(V[i]) == 2;
        NEG[i] = V[i] < 0;
        if (V[i] == 0) R.push_back(i);
    }
    R.push_back(N + 1);

    for (int i = 1; i <= N; i++) {
        P[i] += P[i - 1];
        NEG[i] += NEG[i - 1];
    }

    int l = 1;
    int x = N, y = 0, best = 0;

    for (auto z : R) {
        int L = l, r = z - 1;

        if ((NEG[r] - NEG[L - 1]) & 1) {
            // f = first negative in [L, r], g = last negative in [L, r]
            int f = lower_bound(all(NEG), NEG[L - 1] + 1) - NEG.begin();
            int g = lower_bound(all(NEG), NEG[r]) - NEG.begin();

            // drop whichever side holds fewer 2s: prefix [L, f] or suffix [g, r]
            if (P[f] - P[L - 1] > P[r] - P[g - 1]) r = g - 1;
            else L = f + 1;
        }

        if (P[r] - P[L - 1] > best) {
            x = L - 1;
            y = N - r;
            best = P[r] - P[L - 1];
        }

        l = z + 1;  // from the zero, not from the trimmed r
    }

    cout << x << ' ' << y << el;
}

int main() {
    FastIO;

    int t = 1; cin >> t;
    while (t--) solve();
}