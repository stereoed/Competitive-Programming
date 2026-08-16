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

void solve(){
    cin >> n;
    vector<int> v(n);

    for (auto& x : v) {
        cin >> x;
    }

    
    if (n % 2 == 0){
        cout << "2\n";
        cout << "1 " << n << "\n";
        cout << "1 " << n << "\n";
        return;
    }
    
    cout << "4\n";
    cout << "1 " << n << "\n";
    cout << "1 " << n - 1 << "\n";
    cout << n - 1 << " " << n << "\n";
    cout << n - 1 << " " << n << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}