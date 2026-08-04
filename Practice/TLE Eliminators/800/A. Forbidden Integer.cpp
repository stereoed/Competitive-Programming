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
    cin >> n >> k >> x;

    if (n == 1 || k == 1){
        cout << "NO\n";
        return;
    }
    
    if (x != 1){
        cout << "YES\n";
        for (int i = 0; i < n; i++){
            cout << "1 ";
        }
        cout << '\n';
        return;
    }

    if (k == 2){
        if (n % 2 == 0){
            cout << "YES\n";
            for (int i = 0; i < n; i += 2){
                cout << "2 ";
            }
            cout << '\n';
            return;
        }

        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    if (n % 2 == 1 && k >= 3){
        while (n % 2 == 1){
            cout << "3 ";
            n -= 3;
        }
    } else {
        cout << "NO\n";
        return;
    }
    

    while (n){
        cout << "2 ";
        n -= 2;
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}
