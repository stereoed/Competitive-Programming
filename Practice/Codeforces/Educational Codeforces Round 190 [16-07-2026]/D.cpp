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
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))
 
const int MOD = 676767677;
const int INF = 1e9;
 
struct delta{
	int x, y;
	char dir;
};
 
delta D[] = {{0, 1, 'R'}, {0, -1, 'L'}, {1, 0, 'D'}, {-1, 0, 'U'}};
 
int n;

/*

Number of segments [L, R] with the same MEX. 0 Doesnt count.
I know we can calculate a MEX using a min segment tree in o(logN). However,
that would yield a O(n^2logn) solution: unfeasable.

There must be another way considering the number of segments is not high enough
to consider MOD.

a) Puedo agarrar segmentos seguidos que no contengan uno, y sumar
el factorial del largo por cada segmento.

En esos subsegmentos, ahora lockeo la next_arte izquierda y pongo la next_arte derecha 
en ai == bi == 1. Sumo el largo. Ahora considero los items que estan a
la derecha, mientras no exista ai == 2 o bi == 2 (distintos entre si) puedo 
agregar el largo. 

Si tengo que ai == bi == 2...

b) Y si guardo cuando ai == bi como pilares?

c) FUERA DE CONTST ->
hint : si R funciona, entonces R-1 tambien. (next_ara un mismo L)
Entonces, puedo ir en reversa con los L tal que se encuentre el R mas grande

Revise la solucion.
*/
int aux;
void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    
    rep(i, n) {cin >> a[i]; a[i]--;}
    rep(i, n) {cin >> b[i]; b[i]--;}
    
    ll o = 0;
    
    // next_a y next_b dicen cuando anext_arece por primera vez despues de el indice actual
    // dp guarda mi R maximo para el punto [i]
    vector<int> next_a(n + 1, n), next_b(n + 1, n), dp(n + 2, n);
    
    
    repb(i, n){
        next_a[a[i]] = i;
        next_b[b[i]] = i;
        
        // Si ambos son iguales entonces puedo extender mi R maximo
        if (a[i] == b[i]) {
            int x = a[i] + 1;
            if (next_a[x] == next_b[x]) {
                dp[i] = dp[next_a[x]];
            } else {
                dp[i] = min(next_a[x], next_b[x]);
            }
        }
        
        // La busqueda empieza del 0. Si llego a 1 en uno antes que el otro corto ahi.
        if (next_a[0] != next_b[0]) {
            o += min(next_a[0], next_b[0]) - i;
        } else {
            // Si no, lo extiendo hasta mi R maximo segun dp
            o += dp[next_a[0]] - i;
        }
    }
    
    cout << o << el;
}
 
int main() {
	FastIO;
	
	int t = 1;
	cin >> t;
	
	while (t--) {
		solve();
	}
 
	return 0;
}