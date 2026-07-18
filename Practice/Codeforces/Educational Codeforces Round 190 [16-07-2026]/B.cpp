#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t; cin >> t;
  while (t--){
    string s; cin >> s;
    
    int a = 0, b = 0;
    for (char c : s){
        if (c == '4') continue;
        
        if (c == '2') a++;
        /*
            No puedo creer lo mucho que me tomo entender esta parte.
            La idea es que si '1' y '3' son 'x'; con '2' igual a 'y'
            El string final me quede con un fomato yyyyxxxx
            
            El 4 siempre se elimina asi que lo voy a ignorar.
            b significa que puedo dejar todos los 2 que venian antes
            (cuando tomo la a con el max) o dejar todos los 1 y 3 que
            venian antes (cuando tomo el b).
            
            Lo que no dejo es lo que borro.
        */
        else b = max(a, b) + 1;
    }
    
    cout << s.size() - max(a, b) << endl;
  }
}
