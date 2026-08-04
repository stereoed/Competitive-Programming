#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
#else
    #define dump(...)
#endif

int n, m;
vector<int> arr;
string s;

void solve(){
    cin >> n >> s;
    
    int number_of_water = 0;
    int longest_stretch = 0, current_stretch = 0;

    for (int i = 0; i < n; i++){
        if (s[i] == '.'){
            number_of_water++;
            if (i > 0 && s[i - 1] == s[i]) current_stretch++;
            else current_stretch = 1;

            longest_stretch = max(longest_stretch, current_stretch);
        }
    }

    if (longest_stretch > 2){
        cout << 2 << '\n';
    } else {
        cout << number_of_water << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
}