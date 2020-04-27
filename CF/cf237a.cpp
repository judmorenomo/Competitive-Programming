#include<bits/stdc++.h>
using namespace std;

char mat[310][310];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> mat[i][j];
		}
	}
	if(n == 1){
		cout << "YES\n";
		return 0;
	}
	bool yes = true;
	char cc = mat[0][0], dd = mat[0][1];
	if(cc == dd){
		cout << "NO\n";
		return 0;
	}
	for(int i = 0; i < n; i++){
		int l = i, r = n-i-1;
		for(int j = 0; j < n; j++){
			if(j == l || j == r){
				if(mat[i][j] != cc){
					yes = false;
					break;
				}
			}else {				
				if(mat[i][j] != dd){
					yes = false;
					break;
				}
			}
		}
	}
	if(yes)cout << "YES\n";
	else cout << "NO\n";
}
