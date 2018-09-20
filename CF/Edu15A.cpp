#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> v;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		v.push_back(val);
	}
	int ans = 1, cont = 1;
	for(int i = 1; i < n; i++){
		if(v[i] > v[i-1]){
			cont++;
			ans = max(ans, cont);
		}else cont = 1;
	}
	printf("%d\n", ans);
}