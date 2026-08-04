#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

int n, k, x, m, a, b, c;
vector<int> v;
string s, s1, s2;

void solve(){
    cin >> n;
    int negatives = 0, sum = 0;
    
    for (int i = 0; i < n; i++){
        cin >> a;
        sum += a;
        negatives += (a < 0);
    }

    dump(negatives, sum);
    
    int ans = 0;
    if (sum < 0){
        int change = (-sum + 1)/2; dump(change);
        negatives -= change;
        ans += change;
        sum = 0;
    }

    if (negatives & 1) ans++;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
