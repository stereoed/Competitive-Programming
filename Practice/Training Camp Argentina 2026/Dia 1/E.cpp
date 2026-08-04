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

int n;
string s;

bool ok(int t, const vector<int>& a, const vector<int>& p) {
    dump(t)
    int j = 0;
    int sz = (int)a.size();

    for (int pos : p) {
        if (j >= sz) {
            dump("early return")
            return true;
        }
        int rem = t;
        int npos = pos;

        // Primero a la izquierda
        dump("IZQ", j, sz, pos, a[j])
        int left = a[j];
        if (left < pos){
            while (j < sz && a[j] < pos && a[j] + rem >= pos) j++;
            rem -= (pos - left);
            npos = left;
        }
        
        // Luego a la derecha version a;
        int right = max(npos + rem, pos + rem/2);
        dump("DER", j, sz, right, rem, a[j])
        while (j < sz && a[j] > pos && a[j] <= right) j++;

    }
    dump(j >= sz)
    return j >= sz;
}

void solve() {
    cin >> n >> s;
    vector<int> a, p;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') a.push_back(i);
        if (s[i] == 'P') p.push_back(i);
    }
    dump(a)
    dump(p)

    int l = 0, r = 2 * n + 5;
    while (l < r) {
        int mid = l + (r - l) / 2;
        dump(l, r, mid)

        if (ok(mid, a, p)) r = mid;
        else l = mid + 1;
    }
    cout << l << el;
}

int main() {
    FastIO;
    int t = 1;
    while (t--) solve();
}
