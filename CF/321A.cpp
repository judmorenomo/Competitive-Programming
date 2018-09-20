#include<bits/stdc++.h>
using namespace std;
int res[100010];

int main(){
	vector<int> v;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		v.push_back(val);
	}
	int ans = 1;
	res[0] = 1;
	for(int i = 1; i < n; i++){
		if(v[i] >= v[i-1]){
			res[i] = res[i-1]+1;
		}else res[i] = 1;
		ans = max(ans, res[i]);
	}
	printf("%d\n", ans);
}