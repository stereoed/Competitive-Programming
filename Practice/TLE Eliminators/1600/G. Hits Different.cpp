#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const int MAXN = 1e6 + 5;
long long ANS[MAXN]{};

void solve(){
    int N; cin >> N;
    cout << ANS[N] << '\n';
}

long long left(long long row, long long num){
    long long prev_max = 1LL * row * (row - 1) / 2;
    long long prev_prev_max = 1LL * (row - 1) * (row - 2) / 2;
    return prev_prev_max + max(1LL, num - prev_max - 1);    
}

long long right(long long row, long long num){
    long long prev_max = 1LL * row * (row - 1) / 2;
    long long prev_prev_max = 1LL * (row - 1) * (row - 2) / 2;
    return prev_prev_max + min(row - 1LL, num - prev_max);    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ANS[1] = 1;
    long long row = 1;
    for (long long num = 1; num < MAXN; num++){
        bool le = (num != 1 + 1LL * row * (row - 1) / 2);
        bool ri = (num != 1LL * row * (row + 1) / 2);
        long long extra = (row >= 2 && le ? ANS[left(row, num)] : 0);
        if (ri) extra += ANS[right(row, num)];
        if (row > 2 && le && ri) extra -= ANS[left(row - 1, right(row, num))];

        ANS[num] = num * num + extra;
        if (num == row * (row + 1) / 2) row++;
    }
    
    int t = 1; cin >> t;
    while (t--) solve();
}