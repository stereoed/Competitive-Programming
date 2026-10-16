#include <bits/stdc++.h>

typedef long long ll;

using namespace std;



int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s; cin >> s;

	set<char> vocales = {'A', 'I', 'U', 'E', 'O'};
	int idx = -1;

	int count = 0;
	vector<ll> indices;

	for(int i = 0; i < (int)s.size() - 4; i++){
		if (s[i] == s[i + 4] && vocales.count(s[i]) && s[i + 1] == 'G' && s[i + 2] == 'A' && s[i + 3] == 'S'){
			count++;
			idx = i;
			indices.push_back(i);
		}
	}
	bool se_puede = true;
	for(int i = 1; i < indices.size(); i++){
		if(indices[i] - indices[i-1] != 4) se_puede = false;
	}
	
	if (count == 1 || (indices.size() >= 2 && se_puede)) {
		for(int i = 0; i < (int)s.size(); i++){
			if (i <= idx || i > idx + 4) cout << s[i];
		}
		cout << '\n';

	} else if (count > 1) cout << "+\n";
	else cout << "-\n";

	return 0;
}

