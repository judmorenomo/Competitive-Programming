#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> vals;

bool can(int x){
	int res = 0;
	for(int i = 0; i < vals.size(); i++){
		if(res >= vals[i]){
			res++;
		}else if(x){
			x--;
			res++;
		}
	}
	if(res >= m)return 1;
	return 0;
}

int main(){	
	scanf("%d %d", &n, &m);	
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		vals.push_back(val);
	}	
	int lo = 0, hi = n, ans = hi+1,mid;
	while(lo <= hi){
		mid = lo+(hi-lo)/2;
		if(can(mid)){
			ans = mid;
			hi = mid-1;
		}else lo = mid+1;
	}
	printf("%d\n", ans);
}