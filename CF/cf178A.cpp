#include<bits/stdc++.h>
using namespace std;
int arr[110];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> arr[i];
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int x, y; 
		cin >> x >> y;
		int l = y-1, r = arr[x]-y;
		arr[x] = 0;
		arr[x-1] += l;
		arr[x+1] += r;
	}
	for(int i = 1; i <= n; i++)cout << arr[i]<<'\n';
}
