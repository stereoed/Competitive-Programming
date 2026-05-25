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
 
void solve(){
    int n; cin >> n;
    ll bottom = 0, o = 0;
    map<int, int> ocur;
    vector<int> arr(n); 
    rep(i, n){
        cin >> arr[i];
        if (ocur.count(arr[i])){
            bottom = max(bottom, (ll)ocur[arr[i]] + 1);
        }
        ocur[arr[i]] = i;
        o += i - bottom + 1;
        //cout << bottom << " " << i << " : "<< o << el;
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