#include<bits/stdc++.h>
using namespace std;
const int NMAX = 1010;
char mat[NMAX][NMAX];

int arr[NMAX][NMAX], izq[NMAX][NMAX], der[NMAX][NMAX], aba[NMAX][NMAX];
int aux1[NMAX][NMAX], aux2[NMAX][NMAX];

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
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if (i == 2 && j == 6){				
			}
			if(i > 0){
				if(mat[i][j] == '*')arr[i][j] = arr[i-1][j] + 1;
			}else{
				if(mat[i][j] == '.')arr[i][j] = 0;
				else arr[i][j] = 1;
			}
			if(j > 0){
				if(mat[i][j] == '*')izq[i][j] = izq[i][j-1] + 1;
			}else{
				if(mat[i][j] == '.')izq[i][j] = 0;
				else izq[i][j] = 1; 
			}
		}
	}
	for(int i = n-1; i >= 0; i--){
		for(int j = m-1; j >= 0; j--){
			if(i < n-1){
				if(mat[i][j] == '*')aba[i][j] = aba[i+1][j] + 1;
			}else{
				if(mat[i][j] == '.')aba[i][j] = 0;
				else aba[i][j] = 1;
			}
			if(j < m-1){
				if(mat[i][j] == '*')der[i][j] = der[i][j+1] + 1;
			}else{
				if(mat[i][j] == '.')der[i][j] = 0;
				else der[i][j] = 1;
			}
		}
	}
	vector<pair<pair<int, int>, int> > vec;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int valor = min(aba[i][j], arr[i][j]);
			valor = min(valor, izq[i][j]);
			valor = min(valor, der[i][j]);
			valor--;
			if(valor > 0){
				vec.push_back({{i, j}, valor});
			}
		}
	}
	for(int i = 0; i < vec.size(); i++){
		int tam = vec[i].second;
		aux1[vec[i].first.first - tam][vec[i].first.second]++;
		if(vec[i].first.first + tam + 1 < n)aux1[vec[i].first.first + tam + 1][vec[i].first.second]--;
		aux2[vec[i].first.first][vec[i].first.second - tam]++;
		if(vec[i].first.second + tam + 1 < m)aux2[vec[i].first.first][vec[i].first.second + tam + 1]--;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i > 0)aux1[i][j] = aux1[i][j] + aux1[i-1][j];
			if(j > 0)aux2[i][j] = aux2[i][j] + aux2[i][j-1];
		}
	}
	bool yes = true;	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j] == '*' && aux1[i][j] <= 0 && aux2[i][j] <= 0)yes = false;			
		}		
	}
	if(!yes)cout << "-1\n";
	else{
		cout << vec.size()<<'\n';
		for(int i = 0; i < vec.size(); i++){
			cout << vec[i].first.first + 1<<" "<<vec[i].first.second + 1<<" "<<vec[i].second<<'\n';
		}
	}
}