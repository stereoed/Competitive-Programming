#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n; cin >> n;
    multiset<int> tops;
 
    while (n--) {
        int x; cin >> x;
        auto it = tops.upper_bound(x);  
        if (it == tops.end()) tops.insert(x);
        else { tops.erase(it); tops.insert(x); }
    }
 
    cout << (int)tops.size() << "\n";
}