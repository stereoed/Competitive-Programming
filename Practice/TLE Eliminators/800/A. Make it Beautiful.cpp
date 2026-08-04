#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif


int n;
string s;
vector<int> v;

void solve(){
    cin >> n;
    v.assign(n, 0);
    for (auto& x : v) {
        cin >> x;
    }

    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    
    if (v[l] == v[r]){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << v[r] << " " << v[l++] << " ";
    for (; l < r; l++) cout << v[l] << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
