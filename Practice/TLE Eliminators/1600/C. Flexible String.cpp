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

int N, K;
string A, B, LETTERS;
vector<bool> in_stack(100);

long long dfs(int cur, int cnt){
    if (cnt == K){
        long long o = 0;
        int len = 0;

        for (int i = 0; i < N; i++){
            char a = A[i], b = B[i];
            if (in_stack[a - 'a'] || a == b) {
                len++;
                o += len;
            } else {
                len = 0;
            }
        }

        return o;
    }

    if (cur == (int)LETTERS.size()) return -1e18;

    long long o = dfs(cur + 1, cnt);

    in_stack[LETTERS[cur] - 'a'] = true;
    o = max(o, dfs(cur + 1, cnt + 1));
    in_stack[LETTERS[cur] - 'a'] = false;

    return o;
}

void solve() {
    cin >> N >> K;
    cin >> A >> B;

    LETTERS = A;
    sort(LETTERS.begin(), LETTERS.end());
    LETTERS.erase(unique(LETTERS.begin(), LETTERS.end()), LETTERS.end());
    K = min(K, (int)LETTERS.size());

    long long ans = dfs(0, 0);

    cout << ans << '\n';
}

int main() {
    FastIO;

    int t = 1; cin >> t;
    while (t--) solve();
}