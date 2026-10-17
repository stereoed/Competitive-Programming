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
    int N, K, S; cin >> N >> K >> S;
    vector<long long> V(N), P(N), best(N);
    for (auto& x : V) cin >> x;
    for (int i = 1; i < N; i++) {
        best[i] = max(V[i] + V[i - 1], best[i - 1]);
    }
    
    P[0] = V[0];
    for (int i = 1; i < N; i++) P[i] += V[i] + P[i - 1];
    dump(P);
    dump(best);

    long long ans = P[K];
    for (int i = 1; i <= S; i++){
        int stop = K - 2*i; dump(stop);
        if (stop >= 0) {
            ans = max(ans, i * best[stop] + P[stop]);
            dump(i * best[stop] + P[stop]);
        }
        if (stop + 1 >= 0) {
            ans = max(ans, (i - 1) * best[stop + 1] + P[stop + 1] + (stop != -1 ? V[stop] : 0));
            dump((i - 1) * best[stop + 1] + P[stop + 1] + (stop != -1 ? V[stop] : 0));
        }
    }

    cout << ans << '\n';
}

int main() {
    FastIO;

    int t = 1; cin >> t;
    while (t--) solve();
}