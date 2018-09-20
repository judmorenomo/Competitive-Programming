#include<bits/stdc++.h>
using namespace std;

long long sum1[100010], sum2[100010];
int main(){
	vector<int> v1, v2;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		v1.push_back(val);
		v2.push_back(val);
	}
	sort(v2.begin(), v2.end());
	sum1[0] = v1[0];
	sum2[0] = v2[0];
	for(int i = 0; i < n; i++){
		sum1[i] = sum1[i-1] + v1[i];
		sum2[i] = sum2[i-1] + v2[i];
	}	
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		int ty, l, r;
		scanf("%d %d %d", &ty, &l, &r);
		l--; r--;
		if(ty == 1){
			printf("%lld\n", sum1[r]-sum1[l]+v1[l]);
		}else{
			printf("%lld\n", sum2[r]-sum2[l]+v2[l]);
		}
	}
}