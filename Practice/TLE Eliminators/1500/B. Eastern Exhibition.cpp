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
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    
    long long count_x = 1, count_y = 1;
    if (N % 2 == 0){
        count_x = X[N/2] - X[N/2 - 1] + 1;
        count_y = Y[N/2] - Y[N/2 - 1] + 1;
    }

    cout << count_x * count_y << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}