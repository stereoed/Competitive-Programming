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
    vector<int> V(N), ANS;
    for (auto& x : V) cin >> x;
    sort(V.begin(), V.end());

    long long less_than = V.back() - V.front();

    int l = 0, r = N - 1;
    long long sum = 0;
    while (l <= r){
        if (sum + V[r] < less_than) {
            ANS.push_back(V[r]);
            sum += V[r--];
        } else {
            ANS.push_back(V[l]);
            sum += V[l++];
        }

        if (sum >= less_than){
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
    for (auto x : ANS) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}