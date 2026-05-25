
#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <string.h>
#include <queue>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
void solve(){
    int n; cin >> n;
    vector<pair<int,int>> customers(n);
    rep(i, n) cin >> customers[i].first >> customers[i].second;
    sort(all(customers));
 
    int o = 0;
    priority_queue<int> pq;
    rep(i, n){
        while(!pq.empty() && -pq.top() < customers[i].first) pq.pop();
        pq.push(-customers[i].second);
        o = max(o,(int) pq.size());
    }
 
    cout << o << el;
}
 
int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}