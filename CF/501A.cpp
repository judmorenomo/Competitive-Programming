#include<bits/stdc++.h>
using namespace std;
bool vals[110];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		for(int j = l; j <= r; j++){
			vals[j] = 1;
		}
	}	
	vector<int> v;	
	for(int i = 1; i <= m; i++){
		if(!vals[i]){
			v.push_back(i);
		}
	}
	printf("%d\n", v.size());
	for(int i = 0; i < v.size(); i++){
		printf("%d ", v[i]);
	}
	puts("");
}