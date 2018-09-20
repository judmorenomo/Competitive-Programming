#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int main(){
	int n, may = -1;
	memset(arr, 0, sizeof arr);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		may = max(may, val);
		arr[val]++;
	}
	int sum = 0;
	for(int i = 1; i <= may; i++){
		sum += arr[i]/2;
	}
	printf("%d\n", sum/2);
}