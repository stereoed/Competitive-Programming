#pragma GCC optimize("Ofast")

#if __has_include("stdc++.h")
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif

#ifdef LOCAL
    #if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
    #else
    #define dump(...)
    #endif
#else
    #define dump(...)
#endif

// ORDERED TREE
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;


#define ordered_set tree<pair<ll, int>, null_type,less<pair<ll, int>>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef tuple<ll, ll, ll> tiii;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
#define imp "IMPOSSIBLE"

const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int INF = 1e9;
const ll INFL = 1e17;

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
ll floor(ll a, ll b) { return a / b - (a % b < 0); }
ll ceil(ll a, ll b) { return a / b + (a % b > 0); }

template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}

struct node{
	ll slack;
	int idx, D, T;
	bool active = true;
};

int n, m;
ll s = 0;


// Gracia visho 
void solve() {
	cin >> n;
	vector<node> arr(n);
	vi ans(n);
	
	rep(i, n){
		cin >> arr[i].T >> arr[i].D;
		arr[i].idx = i;
	} 
	
	sort(all(arr), [&](node a, node b) {return a.D < b.D;});
	
	rep(i, n){
		dump(i, arr[i].T, arr[i].D)
		s += arr[i].T;
		arr[i].slack = arr[i].D - s;
		
		if (arr[i].slack < 0){
			cout << '*' << el;
			return;
		}
		dump(s, arr[i].slack)
	} 
	
	rep(i, n){
        int best_id = INF;
        int best_pos = -1;
        ll min_slack_before = INFL;

        rep(x, n){
            if (!arr[x].active) continue;

            if (arr[x].T <= min_slack_before) {
                if (arr[x].idx < best_id) {
                    best_id = arr[x].idx;
                    best_pos = x;
                }
            }

            min_slack_before = min(min_slack_before, arr[x].slack);
        }

        arr[best_pos].active = false;
        ans[i] = best_id + 1;

        rep(x, best_pos){
            if (arr[x].active) {
                arr[x].slack -= arr[best_pos].T;
            }
        }
    }
	
	
	
	for (const auto& v : ans) cout << v << " ";
	cout << el;
}

int main() {
	FastIO;

#ifdef LOCAL
	auto start = chrono::high_resolution_clock::now();
#endif

	int t = 1;
	//cin >> t;
	
	while (t--) {
		solve();
	}

#ifdef LOCAL
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> elapsed = end - start;
	cerr << "\n[Time] " << fixed << setprecision(6) << elapsed.count() << " ms\n";
#endif

	return 0;
}