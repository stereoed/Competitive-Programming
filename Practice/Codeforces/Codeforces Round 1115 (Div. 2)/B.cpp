#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

long long n, q;
vector<int> v; 
string s;

//freq of the second most repeated card?

void solve(){
    cin >> n >> s;

    int one = 0, zero = 0, row_one = 0, row_zero = 0;

    // Buffer de los bordes
    int b1 = (s[0] == '1') + (s[n-1] == '1');
    int b0 = 2 - b1; 

    // Cuantos DEBO borrar
    for (char c : s){
        if (c == '0'){
            row_zero++;
            if (row_one > 1) one += row_one - 1;
            row_one = 0;
        } else {
            row_one++;
            if (row_zero > 1) zero += row_zero - 1;
            row_zero = 0;
        }
    }
    if (row_one > 1) one += row_one - 1;
    if (row_zero > 1) zero += row_zero - 1;

    if (one < zero) { swap(one, zero); swap(b0, b1); } dump(one, b1, zero, b0);

    if (one - zero - b0 > 1){
        cout << "-1\n";
        return;
    }

    cout << 2 * max(one, zero) - (one != zero) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}