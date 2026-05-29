#include <bits/stdc++.h>
#ifdef jlocal
#include<jdebug/debug.hpp>
#else
#define debug(...) 0;
#endif
using namespace std;

#define endl "\n"
#define repf(i,k,n) for(int i=k; i<n; i++)
#define rep(i,n) for(int i=0; i<n; i++)

typedef vector<int> vi;
typedef long long ll;

vector<vector<int>> adj_list;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int n,m;
	cin >> n >> m;
	adj_list.assign(n,vector<int>());
	vi requisitos(n,0);
	//debug("papasd");
	rep(i,m){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		adj_list[a].push_back(b);
		requisitos[b]--;
		//cout << a << " " << b << endl;
	}
	//cout << "pandas" << endl;
	set<int> ops;
	rep(i,n){
		if(requisitos[i]==0)ops.insert(i);
	}
	vi orden;
	//cout << "hola" << endl;
	while(ops.size()>0){
		auto it = ops.begin();
		int x = *it;
		ops.erase(it);
		orden.push_back(x);
		for(int i = 0; i<adj_list[x].size();i++){
			int vecino =adj_list[x][i];
			requisitos[vecino]++;
			if(requisitos[vecino]==0)ops.insert(vecino);
		}
		//debug(ops.size());
		//debug(x);
	}
	if(orden.size()<n)cout << "IMPOSSIBLE" << endl;
	else{
		rep(i,n)cout << orden[i]+1 << " ";
		cout << endl;
	}
	return 0;
}