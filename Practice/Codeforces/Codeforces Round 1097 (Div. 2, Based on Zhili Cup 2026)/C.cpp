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
#define yes "YES"
#define no "NO"

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

struct delta{
	int x, y;
	char dir;
};

struct edge{
	int a, b;
	ll w;
};

delta D[] = {{0, 1, 'R'}, {0, -1, 'L'}, {1, 0, 'D'}, {-1, 0, 'U'}};

int n, m;

/*

No puede ser greedy porque quizas se necesita informacion futura.
No puede ser retroactivo (dfs) porque es n^2

Puedo rechazar altiro si la cantidad no suma 0 entre ambas lineas hasta i.

Me sirve cambiar solo si son distintos. Quizas tratar como rangos? si me falta le paso
una del otro.

*/
void solve() {
	cin >> n;
	int o1{0}, o2{0};
	int i1{0}, i2{0}; // Cuantos corchetes abiertos extra le pueden llegar a este.
	string a1, a2; cin >> a1 >> a2;
	dump("start");
	
	rep(i, n){
		o1 += (a1[i] == '(' ? 1 : -1);
		o2 += (a2[i] == '(' ? 1 : -1);
		
		if (a1[i] != a2[i]){
			if (a1[i] == '(') i2++;
			else i1++;
		}
		
		dump(o1, o2, i1, i2);
		dump(i, a1[i], a2[i]);
		
		if (o1 < 0 && i1 > 0){
			o1 += 2;
			o2 -= 2;
			i1--;
		}
		
		if (o2 < 0 && i2 > 0){
			o2 += 2;
			o1 -= 2;
			i2--;
		}
		
		dump(o1, o2);
		if (o1 < 0 || o2 < 0){
			dump("fail")
			cout << no << el;
			return;
		}
	}
	dump(o1, o2, i1, i2);
	
	while (o1 < 0 && i1 > 0){
		o1 += 2;
		o2 -= 2;
		i1--;
	}
	
	while (o2 < 0 && i2 > 0){
		o2 += 2;
		o1 -= 2;
		i2--;
	}
	
	if (o1 != 0 || o2 != 0){
		dump("fail")
		cout << no << el;
		return;
	}
	
	cout << yes << el;
}

int main() {
	FastIO;

#ifdef LOCAL
	auto start = chrono::high_resolution_clock::now();
#endif

	int t = 1;
	cin >> t;
	
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