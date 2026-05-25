#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <string.h>
 
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// *set.find_by_order(X) [Element at position X], set.order_of_key(x) [N smaller than X]
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
 
int n, x;
 
void solve(){
	cin >> n >> x;
	int nf = n;
	vii arr(n); rep(i, nf) { 
		cin >> arr[i].first;
		arr[i].second = i;
		if (arr[i].first >= x) n--;
	}
	sort(all(arr));
	
	rep(i, n){
		repx(j, i+1, n){
			int search = x - arr[i].first - arr[j].first;
			if (search <= 0) continue;
			
			int left = i+1, right = n-1;
			while (left < right){
				if (right == j) right--;
				if (left == j) left++;
				if (left >= right) break;
				
				int sum = arr[left].first + arr[right].first;
				if (sum == search){
					cout << arr[i].second + 1 << " " << arr[j].second + 1 << " " << arr[left].second + 1 << " " << arr[right].second + 1 << el;
					return;
				}
				
				if (sum > search) right--;
				else left++;
			}
		}
	}
	cout << "IMPOSSIBLE" << el;
}
 
int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}