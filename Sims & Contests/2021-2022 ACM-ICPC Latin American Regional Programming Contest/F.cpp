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

int contador = 0;
vector<vector<int>> adj_list;
vector<int> visitados;
int actual = -100;
void dfs(int u){
	if(visitados[u]!=-1)return;
	visitados[u] = contador;
	actual = max(actual, u);
	for(int i = 0; i<adj_list[u].size(); i++){
		int vecino = adj_list[u][i];
		if(visitados[vecino]==-1)dfs(vecino);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	adj_list.assign(n,vector<int>());
	visitados.assign(n,-1);
	rep(i,m){
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		adj_list[x].push_back(y);
		adj_list[y].push_back(x);
	}
	if(adj_list[n-1].size() == 1){
		rep(i,n-1)cout << "B";
		cout << "A" << endl;
		return 0;
	}
	int color = -100;
	int peso = -100;
	visitados[n-1] = 100;
	rep(i,adj_list[n-1].size()){
		int vecino = adj_list[n-1][i];
		if(visitados[vecino]!=-1)continue;
		contador++;
		dfs(vecino);
		if(actual>peso){
			peso = actual;
			color = contador;
		}
		actual = -100;
	}
	rep(i,n-1){
		if(visitados[i]==color)cout << "B";
		else cout << "A";
	}
	cout << "A" << endl;
	return 0;
}