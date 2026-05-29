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
 
ll n;
vi v, ans;
 
/*
	PROBLEMA ACTUAL (NO CONTEST).
	num => [0, num / 2] + {num};
	Entonces, la pregunta pasa a ser, cuanto es el mex? de esi?
	como minimo es min(n, mediana/2), salvo que esten ordenados, o que el maximo es muhco mas grande y casi pegue...
	
	No puede ser una dp de poner numero / transformarlo porque n es muy grande.
	Quizas intento poner hasta que los gaps sean iguales a los q me quedan (ordenados), luego relleno en orden hasta que no pueda meter otro.
	si me faltan, me quedo asi, estan ordenados, si me sobra, entonces fue.
	
	como se los gaps?
	como me aseguro que no falle?
	
	Que otra opción de corte tengo?
	si front < num? pero quizas llegue a num y sea ese el que me falte.
	
	digo que ans[i] es las maneras de hacer i con el arreglo....
	
	Re confuso, siento que no estoy nada cerca de la solucion del problema.
	
	
	////////
	ERA BINARY SEARCH AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	
*/

void solve() {
    cin >> n;
    v = vi(n);
    rep(i, n) cin >> v[i];
    sort(all(v));

    int l = 0, r = n;
    while(l < r) {
        int m = (l + r + 1) / 2;
        vi vv(m), tt(m);

        for(auto& x : v) {
            if (x < m && vv[x] == 0) vv[x] = 1; // Las uso exacto
            else if (x > 0) tt[min((ll)m - 1, (x - 1) / 2)]++; // Me sirven como comodin, guardo hasta donde llega.
        }
        
        // Approx inicial
        int mex = 0;
        while(mex < m && vv[mex]) mex++;
        
        // Intentamos usar comodines
        rep(i, m){
            while(mex <= i && tt[i] > 0) {
                tt[i]--;
                mex++;
                
                // Sigo hasta donde puedo
                while(mex < m && vv[mex]) mex++;
            }
        }
        
        // Funciona!
        if(mex == m) l = m;
        
        // No funciona...
        else r = m - 1;
    }
    cout << l << el;
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