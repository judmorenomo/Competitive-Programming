#include<bits/stdc++.h>
using namespace std;
map<int, int> ma;
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> vals;
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		vals.push_back(val);
	}
	int ans = 0, may = 0;
	for(int i = 0; i < m; i++){
		int val;
		scanf("%d", &val);
		for(int j = 0; j < vals.size(); j++){
			int valor = val - vals[j];			
			if(valor >= 0){
				ma[valor]++;
				if(ma[valor] > may){
					ans = valor;
					may = ma[valor];
				}else if(ma[valor] == may){
					ans = min(ans, valor);
				}
			}
		}
	}
	
	printf("%d\n", ans);
}