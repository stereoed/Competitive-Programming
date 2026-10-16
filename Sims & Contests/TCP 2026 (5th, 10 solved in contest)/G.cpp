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
    int N, X; cin >> N >> X;
    int step_size = sqrt(N) + 1;

    int start = 0, end = 0;
    for (int i = 0; (i - 1) * step_size < N; i++){
        int clamp = min(N - 1, i * step_size);
        cout << "? " << clamp + 1 << endl;

        int val; cin >> val;
        if (val == X){
            cout << "! " << clamp + 1 << endl;
            return;
        } 
        
        if (val > X){
            start = (i - 1) * step_size;
            end = clamp;
            break;
        }
    }

    cout << "R" << endl;

    for (int x = start + 1; x < end; x++){
        cout << "? " << x + 1 << endl;

        int val; cin >> val;

        if (val == X){
            cout << "! " << x + 1 << endl;
            return;
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}