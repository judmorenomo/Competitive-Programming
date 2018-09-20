#include<bits/stdc++.h>
using namespace std;
vector<int> v;
bool arr[100005];
int pre[100005];
int main(){
	memset(arr, 0, sizeof arr);
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		v.push_back(val);
	}
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		arr[i] = val;
	}
	int ans = 0;
	for(int i = 0; i < v.size(); i++){
		if(arr[i]){
			ans += v[i];
			v[i] = 0;
		}
	}	
	memset(pre, 0, sizeof pre);
	pre[0] = v[0];
	for(int i = 1; i < n; i++){
		pre[i] = v[i]+pre[i-1];
	}
	int may = pre[k-1];
	for(int i = 1; i < v.size()-k+1; i++){
		int val = pre[i+k-1]-pre[i-1];
		may = max(may, val);		
	}
	printf("%d\n", ans+may);
}