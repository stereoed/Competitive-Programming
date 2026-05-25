#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <string.h>
 
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
 
struct node{
    int val;
    node* prev = nullptr;
    node* next = nullptr;
};
 
void solve(){
    int x, n; cin >> x >> n;
    vector<int> poles(n), o(n);
    rep(i, n) cin >> poles[i];
    vector<int> pol = poles;
    sort(all(pol));
 
    map<int, node*> idx;
    node first, last;
    first.val = 0;
    last.val = x;
 
    vector<node> nodes(n);
    node* prev = &first;
 
    rep(i, n){
        nodes[i].val = pol[i];
        nodes[i].prev = prev;
        nodes[i].next = nullptr;
        prev->next = &nodes[i];
 
        prev = &nodes[i];
        idx[nodes[i].val] = &nodes[i];
 
        if (i == n-1){
            last.prev = &nodes[i];
            nodes[i].next = &last;
        }
    }
 
    int larg = 0, lla = 0;
    rep(i, n){
        larg = max(larg, pol[i] - lla);
        lla = pol[i];
    }
    larg = max(larg, x - lla);
 
    o[n-1] = larg;
    repb(i, n - 1){
        int p = poles[i + 1];
        node* cur = idx[p];
 
        larg = max(larg, cur->next->val - cur->prev->val);
        
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        o[i] = larg;
    }
 
    rep(i, n) cout << o[i] << " ";
    cout << el;
}
 
int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}