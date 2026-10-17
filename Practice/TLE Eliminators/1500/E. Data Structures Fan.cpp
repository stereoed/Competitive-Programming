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

void solve(){
    int n; cin >> n;

    int X = 0;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    
    string s; cin >> s;
    for (int i = 1; i <= n; i++){
        if (s[i - 1] == '1') X ^= v[i];
        v[i] ^= v[i - 1];
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++){
        int k; cin >> k;
        if (k == 1){
            int a, b; cin >> a >> b; a--;
            X ^= v[b] ^ v[a];
        } else {
            int a; cin >> a;
            cout << (a == 1 ? X : X ^ v[n]) << ' ';            
        }
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}