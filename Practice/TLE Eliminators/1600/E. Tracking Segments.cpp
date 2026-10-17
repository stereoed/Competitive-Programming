#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

const int MAXN = 1e5 + 5;
long long V[MAXN]{}; 
int N, M, Q;

vector<pair<int, int>> Segments;
vector<int> Updates;

bool ok(int mid){
    for (int i = 0; i <= N; i++) V[i] = 0;
    for (int i = 0; i < min(Q, mid); i++){
        V[Updates[i]]++;
    }  

    for (int i = 1; i <= N; i++){
        V[i] += V[i - 1];
    }

    for (auto& [l, r] : Segments){
        if (2 * (V[r] - V[l - 1]) > r - l + 1) return true;
    }

    return false;
}

void solve(){
    cin >> N >> M; N++;
    Segments.resize(M);
    for (auto& [l, r] : Segments) cin >> l >> r;

    cin >> Q;
    Updates.resize(Q);
    for (auto& x : Updates) cin >> x;
    
    
    long long l = 0, r = Q + 1;
    while (l < r){
        int mid = l + (r - l) / 2;
        if (ok(mid)) r = mid;
        else l = mid + 1;
    }

    cout << (l == Q + 1 ? -1 : l) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}