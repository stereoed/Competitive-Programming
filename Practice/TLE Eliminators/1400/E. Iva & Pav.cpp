#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
#else
    #define dump(...)
#endif

int st[18][200005], lg[200005];

// Template
void build(vector<int>&a){
    int n = a.size();
    for(int i = 0; i < n; i++) st[0][i] = a[i];
    for(int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
    for(int j = 1; j < 18; j++){
        for(int i = 0; i + (1 << j) <= n; i++)
            st[j][i] = st[j - 1][i] & st[j - 1][ i + (1 << (j - 1))];
    }
}

int qry(int l,int r){
    int j = lg[r - l + 1];
    return st[j][l] & st[j][r - (1 << j) + 1];
}

void solve(){
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i]; 
    build(a);

    int q; cin >> q;
    for (int _ = 0; _ < q; _++){
        int left, k; cin >> left >> k; left--;
        if (a[left] < k) {
            cout << "-1 ";
            continue;
        }

        int l = left, r = n - 1;
        while (l < r){
            int mid = l + (r - l + 1)/2;
            if (qry(left, mid) >= k) l = mid;
            else r = mid-1;
        }
        cout << l + 1 << ' ';
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; cin >> t;
    while (t--) solve();
}