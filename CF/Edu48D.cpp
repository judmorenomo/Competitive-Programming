#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> row, col;
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		row.push_back(val);
	}
	for(int i = 0; i < m; i++){
		int val;
		scanf("%d", &val);
		col.push_back(val);
	}
	int aux1 = row[0]^row[1], aux2 = col[0]^col[1];
	for(int i = 2; i < n; i++)aux1 = (aux1 ^ row[i]);	
	for(int i = 2; i < m; i++)aux2 = (aux2 ^ col[i]);	
	if(aux1 != aux2){
		puts("NO");
		return 0;
	}
	puts("YES");
	int val = row[0];
	for(int i = 1; i < m; i++) val = val ^ col[i];
	printf("%d ", val);
	for(int i = 1; i < m; i++)printf("%d ", col[i]);
	puts("");
	for(int i = 1; i < n; i++){
		for(int j = 0; j < m; j++){
			if(j == 0){
				printf("%d ", row[i]);
			}else printf("0 ");
		}
		puts("");
	}
}