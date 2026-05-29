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

ll n;

/*
* M. Mirinae
*
* There are N planets in Vita's galaxy. In order to improve the security of the planets, Vita 
* assigned each planet to guard exactly one other planet. In particular, the i-th planet guards the 
* Ai-th planet for every 1≤i≤N.
* Vita wants to construct a protective barrier surrounding multiple planets. Let the set of planets to 
* be protected by the barrier be S, then each planet in S must be guarding a planet not in S.
* Help Vita determine the maximum number of planets to be protected by the barrier.
*
* El problema es se divide en dos, parte lineal, se pinta la cabeza (todas las cabezas) y se alterna
* Parte ciclica: dos contadores, pinto en i o en i + 1? dejo el minimo (debo haber hecho todo 
* lo lineal primero).
* 
* N -> 1e6
*/

void solve() {
	cin >> n;
	vi protects(n); cin >> protects; // A quien protege cada indice
	vi cnt_protected(n); rep(i, n) cnt_protected[--protects[i]]++; // Cuantos protegen al indice i
	vb barrera(n); // A quienes protege la barrera,
	vb se_puede_pintar(n, 1);
	
	dump(n, protects);
	
	pqg<pii> min_heap; // cnt_protected[i], i
	rep(idx, n) {
		min_heap.push({cnt_protected[idx], idx});
		
		if (cnt_protected[idx] == 0){ // Entry, los pinto y bloqueo tanto el entry como el proximo
			barrera[idx] = 1;
			se_puede_pintar[protects[idx]] = 0;
		}
	}
	
	// Parte lineal
	while (!min_heap.empty()){
		// Info + revision
		auto [protected_by, idx] = min_heap.top(); min_heap.pop();
		if (protected_by != cnt_protected[idx]) continue; // Outdated
		if (protected_by > 0) break; // Se acabo la parte lineal
		
		// Logica de barrera
		ll nxt_idx = protects[idx];
		
		// Si se puede pintar el actual, lo pinto y prohibo que el proximo se pinte
		if (se_puede_pintar[idx]){
			barrera[idx] = 1;
			se_puede_pintar[nxt_idx] = 0;
		}
		
		dump(idx, nxt_idx, barrera[nxt_idx], barrera[idx]);
		
		// Actualizo el heap
		cnt_protected[nxt_idx] -= 1;
		min_heap.push({cnt_protected[nxt_idx], nxt_idx});
	}

	dump(cnt_protected);
	dump(barrera);
	
	int ans = 0;
	for (auto barrera_activa : barrera) ans += barrera_activa;
	dump(ans);
	
	// Parte ciclica
	vb ciclo(n), fijo(n), seen(n);

	// Lo que quedo con cnt_protected > 0 es ciclo
	rep(i, n) ciclo[i] = (cnt_protected[i] > 0);

	// Si la parte lineal conto nodos del ciclo, los saco: el ciclo se recalcula limpio
	rep(i, n) if (ciclo[i] && barrera[i]) ans--;

	// Si un nodo lineal pintado apunta al ciclo, ese nodo del ciclo queda prohibido
	rep(i, n) if (!ciclo[i] && barrera[i]) fijo[protects[i]] = 1;

	rep(idx, n){
		if (!ciclo[idx] || seen[idx]) continue;

		vi cycle;
		int cur = idx;

		do {
			seen[cur] = 1;
			cycle.pb(cur);
			cur = protects[cur];
		} while (cur != idx);

		int best = 0;
		int m = cycle.size();

		rep(start, 2){ // 0, 1
			if (start && fijo[cycle[0]]) continue;

			int a = start ? -INF : 0;    // anterior apagado
			int b = start ? 1 : -INF;    // anterior prendido

			repx(i, 1, m){
				int u = cycle[i];

				int na = max(a, b);              // no pinto u
				int nb = fijo[u] ? -INF : a + 1; // pinto u solo si anterior apagado

				a = na;
				b = nb;
			}

			if (start) best = max(best, a);        // si pinte el primero, no puedo pintar el ultimo
			else best = max(best, max(a, b));
		}

		ans += best;
	}
	
	// Printeo
	cout << ans << el;
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