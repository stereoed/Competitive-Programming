#pragma GCC optimize("Ofast")

#if __has_include("stdc++.h")
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif

#ifdef LOCAL
    #if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__)
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

const int MOD = 998244353;
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

struct delta{
	int x, y;
	char dir;
};

struct edge{
	int a, b;
	ll w;
};

delta D[] = {{0, 1, 'R'}, {0, -1, 'L'}, {1, 0, 'D'}, {-1, 0, 'U'}};

struct Node {
    int a[4] = {-INF, -INF, -INF, -INF};
};

struct SegTree {
    int n;
    vector<Node> st;

    SegTree() {}
	
    SegTree(const vector<Node>& v) {
        build(v);
    }

    Node merge(const Node& L, const Node& R) {
        Node res;
		dump("merging: ", L.a, R.a);
		
        int l1 = 0, l2 = 0, r1 = 3, r2 = 3;
		int idx = 3;
		
		// Dos menores
		while (l1 <= r1 && L.a[l1] == -INF) l1++;
		while (l2 <= r2 && R.a[l2] == -INF) l2++;
		
		while (idx > 1 && (l1 <= r1 || l2 <= r2)){
			dump(idx, l1, l2, r1, r2);
			if (l2 > r2 || (l1 <= r1 && L.a[r1] >= R.a[r2])) {
				dump("Selected", L.a[r1]);
				res.a[idx--] = L.a[r1--];
			}
			else {
				if (l1 > r1 || (l2 <= r2 && L.a[r1] < R.a[r2])) {
					dump("Selected", R.a[r2]);
					res.a[idx--] = R.a[r2--];
				}
				else{
					dump("Break");
					break;
				} 
			}
		}
		
		idx = 0;
		while (idx < 2 && (l1 <= r1 || l2 <= r2)){
			dump(idx, l1, l2, r1, r2);
			if (l2 > r2 || (l1 <= r1 && L.a[l1] <= R.a[l2])) res.a[idx++] = L.a[l1++];
			else if (l1 > r1 || (l2 <= r2 &&L.a[l1] > R.a[l2])) res.a[idx++] = R.a[l2++];
			else break;
		}
		
		sort(res.a, res.a + 4);
		dump("got: ", res.a);
        return res;
    }

    void build(const vector<Node>& v) {
		n = (int)v.size();
		st = vector<Node>(4 * n);
		
		dump("setting values", st.size(), n);
        rep(i, n) {
            st[n + i] = v[i];
        }
		
		dump("merging values");
        for (int i = n - 1; i >= 1; i--) {
            st[i] = merge(st[2 * i], st[2 * i + 1]);
        }
    }

    Node query(int l, int r) {
        // query on [l, r)
        Node left;
        Node right;

        l += n;
        r += n;

        while (l < r) {
            if (l & 1) left = merge(left, st[l++]);
            if (r & 1) right = merge(st[--r], right);

            l >>= 1;
            r >>= 1;
        }

        return merge(left, right);
    }
};

ll n, q;

/*
* A. An Easy Array Problem
*/

void solve() {
	cin >> n >> q;
	vector<Node> arr(n); rep(i, n) cin >> arr[i].a[3];
	
	SegTree st(arr);
	dump(1);
	
	rep(i, q){
		int l, r; cin >> l >> r; l--; r--;
		ll base = (ll)arr[l].a[3] * (ll)arr[r].a[3];
		ll ans = -INFL;
		dump("query on", l, r, base);
		
		Node mid = st.query(l + 1, r);
		int others[4];

		rep(j, 4) others[j] = mid.a[j];
		dump(others);
		
		rep(j, 4){
			if (others[j] == -INF) continue;
			
			repx(k, j + 1, 4)
				ans = max(ans, base * (ll)others[j] * (ll)others[k]);
		}
		
		dump(ans);
		cout << ans << el;
	}
	
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