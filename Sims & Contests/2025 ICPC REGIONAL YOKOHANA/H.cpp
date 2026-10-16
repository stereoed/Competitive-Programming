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
vector<vector<char>> matrix;
vector<vector<int>> visited;
int n, m, k;
bool flag = true;

bool limits(int f, int c){
	return f>=0 && f<n && c>=0 && c<m;
}

bool uno(int x, int y){
	if(!limits(x+k-1, y+k-1))return false;
	for(int i = x; i<x+k; i++){
		if(visited[i][y] || matrix[i][y]=='.')return false;
	}
	for(int j = y; j<y+k; j++){
		if(visited[x][j] || matrix[x][j]=='.')return false;
	}
	for(int j = y; j<y+k; j++){
		if(visited[x+k-1][j] || matrix[x+k-1][j]=='.')return false;
	}

	for(int i = x; i<x+k; i++){
		visited[i][y] = 1;
	}
	for(int j = y; j<y+k; j++){
		visited[x][j] = 1;
	}
	for(int j = y; j<y+k; j++){
		visited[x+k-1][j] = 1;
	}
	return true;
}

bool dos(int x, int y){
	if(!limits(x+k-1, y+k-1))return false;
	for(int i = x; i<x+k; i++){
		if(visited[i][y+k-1] || matrix[i][y+k-1]=='.')return false;
	}
	for(int j = y; j<y+k; j++){
		if(visited[x][j] || matrix[x][j]=='.')return false;
	}
	for(int j = y; j<y+k; j++){
		if(visited[x+k-1][j] || matrix[x+k-1][j]=='.')return false;
	}

	for(int i = x; i<x+k; i++){
		visited[i][y+k-1] = 1;
	}
	for(int j = y; j<y+k; j++){
		visited[x][j] = 1;
	}
	for(int j = y; j<y+k; j++){
		visited[x+k-1][j] = 1;
	}
	return true;
}
bool tres(int x, int y){
	if(!limits(x+k-1, y+k-1))return false;
	for(int i = x; i<x+k; i++){
		if(visited[i][y] || matrix[i][y]=='.')return false;
	}
	for(int j = y; j<y+k; j++){
		if(visited[x][j] || matrix[x][j]=='.')return false;
	}
	for(int i = x; i<x+k; i++){
		if(visited[i][y+k-1] || matrix[i][y+k-1]=='.')return false;
	}//kkk

	for(int i = x; i<x+k; i++){
		visited[i][y]=1;
	}
	for(int j = y; j<y+k; j++){
		visited[x][j]=1;
	}
	for(int i = x; i<x+k; i++){
		visited[i][y+k-1] =1;
	}
	return true;
}
bool cuatro(int x, int y){
	if(!limits(x+k-1, y+k-1))return false;
	for(int i = x; i<x+k; i++){
		if(visited[i][y] || matrix[i][y]=='.')return false;
	}
	for(int j = y; j<y+k; j++){
		if(visited[x+k-1][j] || matrix[x+k-1][j]=='.')return false;
	}
	for(int i = x; i<x+k; i++){
		if(visited[i][y+k-1] || matrix[i][y+k-1]=='.')return false;
	}//kkk

	for(int i = x; i<x+k; i++){
		visited[i][y]=1;
	}
	for(int j = y; j<y+k; j++){
		visited[x+k-1][j]=1;
	}
	for(int i = x; i<x+k; i++){
		visited[i][y+k-1] =1;
	}
	return true;
}


bool probar(int i, int j){
	return uno(i,j) || dos(i,j) || tres(i,j) || cuatro(i,j);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while(tt--){	
		flag = true;	
		cin >> n >>m >> k;
		matrix.assign(n,vector<char>(m,'.'));
		visited.assign(n,vector<int>(m,0));
		debug(visited);
		rep(i,n)rep(j,m)cin>>matrix[i][j];
		rep(i,n){
			rep(j,m){
				if(visited[i][j])continue;
				if(matrix[i][j]=='.')continue;
				if(probar(i,j))continue;
				flag = false;
				break;
			}
		}
		debug(visited);
		if(flag)cout << "yes" << endl;
		else cout << "no" << endl;
	}

return 0;
}