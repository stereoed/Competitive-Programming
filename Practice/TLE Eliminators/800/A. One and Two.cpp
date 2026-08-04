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
    int goal = 0;
    for (auto& x : v) {
        cin >> x;
        goal += x == 2;
    }

    if (goal&1){
        cout << "-1\n";
        return;
    }

    goal /= 2;
    for (int i = 0; i < n; i++){
        goal -= v[i] == 2;
        if (goal == 0){
            cout << i + 1 << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
