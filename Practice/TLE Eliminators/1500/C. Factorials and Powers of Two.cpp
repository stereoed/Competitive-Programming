#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

long long fac[16]{};
long long n;
int ans = 64;

int popcount(long long x){
    int num{};
    for (; x; ++num, x &= (x - 1));
    return num;
}

void dfs(int idx, int cnt, long long num){
    if (idx == 16) return;

    ans = min(ans, cnt + popcount(n - num));
    dfs(idx + 1, cnt + 1, num + fac[idx]);
    dfs(idx + 1, cnt, num);
}

void solve(){
    cin >> n;
    ans = 64;

    dfs(0, 0, 0);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    fac[0] = 1;
    for (int i = 1; i < 16; i++) fac[i] = 1LL * i * fac[i - 1];
    dump(fac);

    int t = 1; cin >> t;
    while (t--) solve();
}