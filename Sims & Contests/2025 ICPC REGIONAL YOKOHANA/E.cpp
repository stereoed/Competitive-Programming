#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

long long A, B, C;
long long K;

bool ok(long long P, long long Q){
    long long cur = min(K, (Q * A / P));
    cur = min(K, cur * min(K, (Q * B / P)));
    cur = min(K, cur * min(K, (Q * C / P)));
    return cur >= K;
}

long long BS(long long WHO){
    long long l = 1, r = max(WHO, K);
    while (l < r){
        long long mid = l + (r - l) / 2;
        if (ok(WHO, mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

void solve(){
    cin >> A >> B >> C >> K;
    long long p = 0, q = 1;

    for (long long W : {A, B, C}){
        long long cur = BS(W);
        if (cur * p < W * q){
            p = W;
            q = cur;
        }
    }

    cout << p / gcd(p, q) << ' ' << q / gcd(p, q)<< '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}