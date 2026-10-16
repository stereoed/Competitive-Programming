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
    int N, M, K, P; cin >> N >> M >> K >> P;
    if (M >= P){
        cout << "NO\n";
        return;
    }

    cout << "SI\n";
    for (int i = 1; i <= N; i++){
        if (M > 0 && i != K){
            M--;
            cout << 'B';
        } else {
            cout << 'E';
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}