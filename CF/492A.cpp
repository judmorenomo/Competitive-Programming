#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	int div1, div2, div3, div4, div5;
	div1 = (n / 100);
	ans += div1;
	n -= 100*div1;
	div2 = (n / 20);
	ans += div2;
	n -= 20*div2;
	div3 = (n / 10);
	ans += div3;
	n -= div3*10;
	div4 = (n / 5);
	ans += div4;
	n -= div4*5	;
	div5 = n;
	ans += div5;
	n -= div5;
	printf("%d\n", ans);
}