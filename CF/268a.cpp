#include<bits/stdc++.h>
using namespace std;
int arr[105];
int main(){
	memset(arr, 0, sizeof arr);
	int n;
	scanf("%d", &n);
	int p, q;
	scanf("%d", &p);
	for(int i = 0; i < p; i++){
		int val;
		scanf("%d", &val);
		arr[val]++;
	}
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		int val;
		scanf("%d", &val);
		arr[val]++;
	}
	bool yes = true;
	for(int i = 1; i <= n; i++){
		if(!arr[i]){
			yes = false;
			break;
		}
	}
	if(yes){
		puts("I become the guy.");
	}else{
		puts("Oh, my keyboard!");
	}
}