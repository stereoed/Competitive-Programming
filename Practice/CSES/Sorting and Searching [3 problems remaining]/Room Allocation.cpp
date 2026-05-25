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
 
struct state{
	int idx, room{-1}, a, b;
};
 
void solve(){
	int n; cin >> n;
	vector<state> v(n);
	rep(i, n) { v[i].idx = i; cin >> v[i].a; cin >> v[i].b; }
	sort(all(v), [](const state& a, const state& b){
		if (a.a != b.a) return a.a < b.a;
		return a.b < b.b;
	});
	
	int total_rooms = 0;
	ordered_set<pii> rooms; // {end, idx}
	vector<int> output(n);
	
	rep(i, n){
		auto& [idx, room, a, b] = v[i];
		if (rooms.order_of_key({a, -1}) == 0){
			room = ++total_rooms;
		} else {
			pii deleted = *rooms.find_by_order(0);
			room = output[deleted.second];
			rooms.erase(deleted);
		}
		
		rooms.insert({b, idx});
		output[idx] = room;
	}
	
	cout << total_rooms << el;
	rep(i, n) cout << output[i] << " ";
	cout << el;
}
 
int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}