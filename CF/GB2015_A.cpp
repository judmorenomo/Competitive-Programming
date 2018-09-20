#include<bits/stdc++.h>
using namespace std;
char mat[510][510];
long long acu[510][510];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c; cin >> c;
			mat[i][j] = c;
		}
	}

	memset(acu, 0, sizeof acu);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i > 0 && j > 0){
				acu[i][j] = acu[i][j-1] + acu[i-1][j] - acu[i-1][j-1];
				if(mat[i][j] == '.'){
					if(mat[i-1][j] == '.')acu[i][j]++;
					if(mat[i][j-1] == '.')acu[i][j]++;
				}
			}else if(i > 0){
				acu[i][j] = acu[i-1][j];
				if(mat[i][j] == '.' && mat[i-1][j] == '.')acu[i][j]++;
			}else if(j > 0){
				acu[i][j] = acu[i][j-1];
				if(mat[i][j] == '.' && mat[i][j-1] == '.')acu[i][j]++;
			}			
		}
	}

	int q; cin >> q;
	while(q--){
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--; r2--;
		c1--; c2--;

		long long res = acu[r2][c2];
		if(r1 > 0)res -= acu[r1-1][c2];
		if(c1 > 0)res -= acu[r2][c1-1];
		if(r1 > 0 && c1 > 0)res += acu[r1-1][c1-1];
		if(r1 > 0){
			for(int i = c1; i <= c2; i++){
				if(mat[r1][i] == '.' && mat[r1][i] == mat[r1-1][i])res--;
			}
		}
		if(c1 > 0){
			for(int i = r1; i <= r2; i++){
				if(mat[i][c1] == '.' && mat[i][c1] == mat[i][c1-1])res--;
			}	
		}
		cout << res<<'\n';
	}	

}