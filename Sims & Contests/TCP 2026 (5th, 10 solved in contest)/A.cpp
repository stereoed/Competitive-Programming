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
    if (N <= 2){
        cout << "NO\n";
        return;
    }
    
    cout << "SI\n";
    int R = N % 3;

    for (int i = 0; i < R; i++) cout << '2';
    for (int i = R; i < N - R; i++)cout << '1';
    for (int i = N - R; i < N; i++) cout << '2';

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}