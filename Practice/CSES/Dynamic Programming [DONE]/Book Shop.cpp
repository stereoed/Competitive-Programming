#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, x; cin >> n >> x;
    vii pp(n);
    
    rep(i,n) cin >> pp[i].first; // Price, profit
    rep(i,n) cin >> pp[i].second;
    
	vi ans(x + 1, 0);
	
	rep(i, n){
        int price = pp[i].first, val = pp[i].second;
        for (int j = x; j >= price; --j){
            ans[j] = max(ans[j], ans[j - price] + val);
        }
    }
 
	
	cout << ans[x] << el;	
}