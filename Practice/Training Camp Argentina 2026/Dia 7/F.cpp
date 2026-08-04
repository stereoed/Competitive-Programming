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
const int max_n = 1001;
int matrix[max_n][max_n];
int visited[max_n][max_n];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n,m;
vi tiempos;

bool limits(int u, int v){
	return u>=0 && u<n && v>=0 && v<m && matrix[u][v];
}

int dfs(int u , int v, int t){
	if(visited[u][v])return 0;
	int tot = 1;
	visited[u][v]=t;
	for(int i = 0; i<4; i++){
		int nx = u+dx[i], ny = v+dy[i];
		if(limits(nx,ny) && !visited[nx][ny]){
			tot+=dfs(nx,ny,t);
		}
	}
	return tot;
}
int sumar(int u , int v){
	set<int> tps;
	for(int i = 0; i<4; i++){
		int nx = u+dx[i], ny = v+dy[i];
		if(limits(nx,ny)){
			tps.insert(visited[nx][ny]-1);
		}
	}
	int sum = 0;
	for(auto a : tps)sum+=tiempos[a];
	return sum+1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	rep(i,n)rep(j,m){
		char a;
		cin >> a;
		matrix[i][j] = (a=='.');
	}
	int tt = 1;
	rep(i,n)rep(j,m)visited[i][j] = 0;
	rep(i,n)rep(j,m){
		if(!visited[i][j] && matrix[i][j]){
			int kk =dfs(i,j,tt);
			tiempos.push_back(kk);
			tt++;
		}
	}
debug(tiempos);
//rep(i,n)rep(j,m)cout << visited[i][j];
	rep(i,n){
		rep(j,m){
			if(!matrix[i][j])cout << sumar(i,j)%10;
			else cout << '.';
		}
		cout << endl;
	}
	return 0;
}