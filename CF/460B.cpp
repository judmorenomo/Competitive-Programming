#include<bits/stdc++.h>
using namespace std;

bool valid(int val){
	int sum = 0;
	while(val){
		sum += val % 10;
		val /= 10;
	}
	if(sum == 10)return true;
	return false;
}
int main(){
	int k;
	scanf("%d", &k);
	int cont = 0, val = 1;
	while(cont < k){
		if(valid(val))cont++;
		val++;
	}
	printf("%d\n", val-1);
}