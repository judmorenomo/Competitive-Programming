#include<bits/stdc++.h>
using namespace std;
int pre[200010];
int main(){
	vector<int> v;
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		v.push_back(val);
	}
	pre[0] = v[0];
	for(int i = 1; i < n; i++){
		pre[i] = pre[i-1] + v[i];
	}
	int ans = INT_MAX, pos;
	for(int i = 0; i < n - k + 1; i++){
		int r = i + k - 1, l = i;
		int val = pre[r] - pre[l] + v[l];
		if(val < ans){
			ans = val;
			pos = l+1;
		}		
	}
	printf("%d\n", pos);
}