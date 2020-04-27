#include<bits/stdc++.h>
using namespace std;

int arr[110];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	k--;
	for(int i = 0; i < n; i++)cin >> arr[i];	
	int ans = arr[k], l = k-1, r = k+1;	
	while(l >= 0 && r < n){
		if(arr[l] && arr[r])ans += 2;
		l--; r++;
	}	
	while(l >= 0){
		if(arr[l])ans++;
		l--;
	}
	while(r < n){
		if(arr[r])ans++;
		r++;
	}
	cout << ans<<'\n';
}
