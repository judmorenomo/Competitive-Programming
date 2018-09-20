#include<bits/stdc++.h>
using namespace std;

long long pre[500010], pos[500010];
vector<int> v, posis;

int bin(int x){
	int lo = 0, hi = posis.size()-1, ans = hi+1, mid;
	while(lo <= hi){
		mid = lo + (hi-lo)/2;
		if(posis[mid] >= x){
			ans = mid;
			hi = mid-1;
		}else lo = mid + 1;
	}
	return ans;
}

int main(){
	long long tot = 0;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		tot += val;
		v.push_back(val);
	}
	if(tot % 3 != 0){
		puts("0");
		return 0;
	}
	pre[0] = v[0];
	for(int i = 1; i < n; i++){
		pre[i] = pre[i-1] + v[i];
	}
	pos[n-1] = v[n-1];
	for(int i = n-2; i >= 0; i--){
		pos[i] = pos[i+1] + v[i];
	}
	for(int i = 0; i < n; i++){
		if((tot / 3) == pos[i])posis.push_back(i);
	}		
	long long ans = 0;
	for(int i = 0; i < n-2; i++){
		if((tot / 3) == pre[i]){			
			ans += posis.size() - bin(i +2);
		}
	}
	printf("%lld\n", ans);
}