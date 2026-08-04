#pragma GCC optimize("Ofast")
using namespace std;

#if __has_include("stdc++.h")
    #include "stdc++.h"
    #else
    #include <bits/stdc++.h>
#endif

#if __has_include("cpp-dump.hpp")
    #include "cpp-dump.hpp"
    #define dump(...) cpp_dump(__VA_ARGS__);
    #else
    #define dump(...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define el '\n'


long long d, k;

void solve() {
    cin >> d >> k;
    bool ash_wins = true;

    dump(d, k);
    
    /*
    * Juego ql se puede representar con torrecitas
    * Como se hacia? solo dios sabe
    * Si k > d/2 -> si o si gana ash
    * El primer movimiento, el de ash, siempre es (k, 0)
    * * Despues, si k * sqrt (2) > d entonces si o si gana ash
    * * * Pero esto no es generalizable
    * Aca seria re bueno tener un papel
    * Pero como paso la distancia a las torres?
    * Puedo encontrar la (altura, profundidad) directa 
    * en d * [sin (atan(y / x)), cos (atan(y / x))]
    * Si mi punto despues de moverme es <= a ese limite,
    * me sirve.
    * 
    * Aca esta: https://cp-algorithms.com/game_theory/sprague-grundy-nim.html
    * Como represento la distancia de las torres?
    * distancia maxima y distancia minima?
    * La minima seria moverme directo hacia el borde mas cercano
    * La maxima seria moverme en diagonal.
    * Pero tambien puedo hacer algo en tremedio, hmm
    * Si dejo todas las combinaciones como torres distintas?
    * No, puede crecer mucho con k, d.
    * 
    * Demosle asi nomas
    * Encontremos la distancia maxima, normalizada en pasos.
    * Si estando ahi me puedo mover, gana impar.
    * Esto es como la mano invisible del mercado, si llego a eso
    * El resto se arregla solo
    */

    long long l = 0, r = d / k + 1;;
    long long mid = l + (r - l)/2;
    long long pt = mid * k;

    while (l < r){
        mid = l + (r - l + 1)/2;
        pt = mid * k;

        if (pt * pt + pt * pt > d * d) r = mid - 1;
        else l = mid;
    }

    pt = l * k;
    if (pt * pt + (pt + k) * (pt + k) > d * d) ash_wins = false;
    cout << (ash_wins ? "Ashish" : "Utkarsh") << el;
}

int main() {
	FastIO;
    
	int t = 1;
	cin >> t;
	
	while (t--) solve();
}