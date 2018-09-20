#include<bits/stdc++.h>
using namespace std;
int arr[1005];
int main(){
	memset(arr, 0, sizeof arr);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int val;
		scanf("%d", &val);
		arr[val]++;
	}
	int ans = 987654321;
	for(int i = 1; i <= n; i++){
		ans = min(ans, arr[i]);
	}
	printf("%d\n", ans);
}