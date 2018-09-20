#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int val1 = max(n, n / 10);
	int res = n % 10;
	int num = n / 100;	
	num = num*10 + res;	
	int val2 = max(val1, num);	
	printf("%d\n", val2);
}