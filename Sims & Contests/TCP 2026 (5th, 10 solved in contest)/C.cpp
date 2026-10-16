#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

void solve(){
    int N; cin >> N;
    map<int, int> cnts;
    for (int i = 0; i < N; i++){
        int a; cin >> a;
        cnts[a]++;
    }

    priority_queue<int> pq;
    for (auto [val, cnt] : cnts) if (cnt > 0) pq.push(cnt);
    dump(cnts);

    int ans = 0;
    while (pq.size() >= 3){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int c = pq.top(); pq.pop();
        if (a - 1 > 0) pq.push(a - 1);
        if (b - 1 > 0) pq.push(b - 1);
        if (c - 1 > 0) pq.push(c - 1);
        ans++;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}