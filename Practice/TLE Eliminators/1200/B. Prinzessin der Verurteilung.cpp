#pragma GCC optimize("Ofast")
using namespace std;

#if __has_include("stdc++.h")
    #include "stdc++.h"
#else
    #include <bits/stdc++.h>
#endif

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define el '\n'

long long n;
string s;

vector<set<string>> bruteforce_base(3);

void create_bruteforce(){
    for (char x = 'a'; x <= 'z'; x++){
        bruteforce_base[0].insert(string(1, x));
        for (char y = 'a'; y <= 'z'; y++){
            bruteforce_base[1].insert(string(1, x) + y);
            for (char z = 'a'; z <= 'z'; z++){
                bruteforce_base[2].insert(string(1, x) + y + z);
            }
        }
    }
}

void solve() {
    cin >> n >> s;

    // One

    auto bruteforce = bruteforce_base[0];
    for (int l = 0; l < n; l++) bruteforce.erase(string(1, s[l]));
    if (bruteforce.size()){
        cout << *bruteforce.begin() << '\n';
        return;
    }

    // Two
    bruteforce = bruteforce_base[1];
    for (int l = 0; l < n - 1; l++) bruteforce.erase(string(1, s[l]) + s[l + 1]);
    if (bruteforce.size()){
        cout << *bruteforce.begin() << '\n';
        return;
    }

    bruteforce = bruteforce_base[2];
    for (int l = 0; l < n - 2; l++) bruteforce.erase(string(1, s[l]) + s[l + 1] + s[l + 2]);
    cout << *bruteforce.begin() << '\n';
}

int main() {
    FastIO;
    bruteforce_base.assign(3, set<string>());
    create_bruteforce();

    int t = 1; cin >> t;
    while (t--) solve();
}