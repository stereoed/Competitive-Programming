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
    vector<int> ANS(N);

    int A = 1;
    int B = 2;
    for (int i = 0; i < 2 * N && B <= N; i++){
        cout << "? " << A << " " << B << endl;
        int AmodB; cin >> AmodB;

        cout << "? " << B << " " << A << endl;
        int BmodA; cin >> BmodA;

        if (AmodB > BmodA){
            ANS[A - 1] = AmodB;
            A = B;
        } else {
            ANS[B - 1] = BmodA;
        }

        B++;
    }

    cout << "! ";
    for (int x : ANS) cout << (x ? x : N) << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
}