#include<bits/stdc++.h>
using namespace std;
char mat[105][105];
bool vis[105][105];
int n, m;

int solve(int i, int j){
	int row1 = i-1, row2 = i+1, col1 = j-1, col2 = j+1, aux = 0;
	while(row1 >= 0 && row2 < n && col1 >= 0 && col2 < m){
		if(mat[row1][j] != '*')break;
		if(mat[row2][j] != '*')break;
		if(mat[i][col1] != '*')break;
		if(mat[i][col2] != '*')break;
		vis[row1][j] = 1;
		vis[row2][j] = 1;
		vis[i][col1] = 1;
		vis[i][col2] = 1;
		vis[i][j] = 1;
		aux++;
		row1--; row2++;
		col1--; col2++;
	}
	return aux;
}

int main(){
	memset(vis, 0, sizeof vis);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			mat[i][j] = c;
		}
	}
	bool yes = true;
	if(mat[0][0] == '*' || mat[0][m-1] == '*' || mat[n-1][0] == '*' || mat[n-1][m-1] == '*')yes = false;
	if(!yes){
		cout << "-1\n";
		return 0;
	}
	vector<pair<pair<int, int>, int> > vec;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j] == '*'){
				int val = solve(i, j);
				if(!val)continue;
				vec.push_back({{i+1, j+1}, val});				
			}
		}		
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!vis[i][j] && mat[i][j] == '*'){
				yes = false;
				break;
			}
		}
	}
	if(!yes){
		cout << "-1\n";
		return 0;
	}
	cout << vec.size()<<'\n';
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i].first.first<<" "<<vec[i].first.second<<" "<<vec[i].second<<'\n';
	}
}