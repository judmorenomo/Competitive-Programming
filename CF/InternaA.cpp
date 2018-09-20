#include<bits/stdc++.h>
using namespace std;
#define MAX_N 5
struct Matrix {long long mat[MAX_N][MAX_N]; };
long long mo = 1e9 + 7;

Matrix matMul(Matrix a, Matrix b){
	Matrix ans; int i, j, k;
	for(i = 0; i < MAX_N; i++){
		for(j = 0; j < MAX_N; j++){
			for(ans.mat[i][j] = k = 0; k < MAX_N; k++){
				ans.mat[i][j] = (ans.mat[i][j] % mo + ((a.mat[i][k] % mo * b.mat[k][j] % mo)%mo)) % mo;
			}
		}
	}
	return ans;
}

Matrix matPow(Matrix base, long long p){
	Matrix ans; int i, j;
	for(i = 0; i < MAX_N; i++){
		for(j = 0; j < MAX_N; j++){
			ans.mat[i][j] = (i == j);
		}
	}		
	while(p){
		if(p & 1)ans = matMul(ans, base);
		base = matMul(base, base);
		p >>= 1;
	}
	return ans;
}
int main(){
	Matrix matriz;
	memset(matriz.mat, 0, sizeof matriz.mat);
	matriz.mat[0][0] = 16;
	matriz.mat[0][1] = 9;
	matriz.mat[0][2] = 4;
	matriz.mat[0][3] = 1;
	matriz.mat[1][0] = 1;
	matriz.mat[2][1] = 1;
	matriz.mat[3][2] = 1;
	matriz.mat[4][3] = 1;				  

	long long val;
	cin >> val;
	long long aux = val;
	val /= 10;
	int res = 0;
	Matrix ans = matPow(matriz, val);	
	for(int i = 0; i < 4; i++){
		res =  ( res % mo + (ans.mat[i][0])% mo) % mo;		
	}
	if(aux % 10 < 5){
		res = (res % mo + (ans.mat[4][0]) % mo) % mo;
	}
	cout << res<<'\n';
}