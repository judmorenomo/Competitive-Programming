#include<bits/stdc++.h>
using namespace std;
int arr[105];
int main(){
	memset(arr, 0, sizeof arr);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		arr[val]++;
	}
	int may = -1;
	for(int i = 1; i <= 100; i++){
		may = max(may, arr[i]);
	}
	printf("%d\n", may);
}