#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef pair<int, int> pii;

const int M = 1000000007;

void solve(){
    int n; cin >> n;
    ll ans = 0;
    vector<pii> segments(n);
    for (auto& [ff, ss] : segments) cin >> ff >> ss;
    sort(segments.begin(), segments.end());

    ordered_set<int> segment_ends;
    for (const auto& [start, end] : segments){
        ans += segment_ends.size() - segment_ends.order_of_key(end);
        segment_ends.insert(end);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}