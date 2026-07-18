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
#define el '\n'

int solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    // Estaba resolviendo el problema con subarrays, no con subsecuencias

    int a10{0}, a01{0}, a1{0}, a0{0};
    for (const int x : a){
        int b; cin >> b;
        if (x == b){
            if (x == 1) a1++;
            else a0++;
        } 

        else {
            if (x == 1) a10++;
            else a01++;
        }   
    }

    // A: No hay ninguno que sea distinto
    if (a1 + a0 == n) return 0;

    // B: La suma de los distintos es impar: los invierto todos de una
    if (a10 & 1) return 1;

    // C1: No hay ningun 1 en toda 'a': no se puede invertir nada.
    // C2: No hay ningun 0 en toda 'b': siempre que se invierte queda al menos un cero: contradiccion.
    if (a10 + a1 == 0 || a1 + a01 == n) return -1;    

    // D: Se parte el movimiento en dos:
    /*
        > Se toma una parte impar y se invierte, luego se toma la otra parte impar y tambien se invierte
        Sea a = [1, 1, 0]
            b = [0, 0, 1]
        
           a* = [1, 0, 1]
          a** = [0, 0, 1]
        Como tratamos con subsecuencias y no subarreglos no importa el orden
    */
    return 2;
}

int main() {
	FastIO;
    
	int t = 1;
	cin >> t;
	
	while (t--) cout << solve() << el;
}