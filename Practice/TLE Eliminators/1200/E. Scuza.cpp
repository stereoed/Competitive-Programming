#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

long long n, q;
void solve(){
    cin >> n >> q;
    vector<long long> z(n + 1), ans(q);
    vector<pair<long long, int>> query(q);

    for (int i = 1; i <= n; i++) {
        cin >> z[i];
        z[i] += z[i-1];
    }
    for (int i = 0; i < q; i++) {
        cin >> query[i].first;
        query[i].second = i;
    }

    sort(query.begin(), query.end());
    dump(query);

    int ptr = 0;
    for (int i = 1; i <= n; i++){
        int jump = z[i] - z[i-1]; dump(jump, query[ptr].first);
        while (ptr < q && jump > query[ptr].first){
            ans[query[ptr].second] = z[i-1];
            ptr++;
        }
    }

    for (; ptr < q; ptr++){
        ans[query[ptr].second] = z[n];
    }

    for (const auto a : ans) cout << a << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}