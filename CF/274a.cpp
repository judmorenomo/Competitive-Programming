#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int res = a + b + c;
	res = max(res, a*b*c);
	res = max(res, (a+b)*c);
	res = max(res, a*(b+c));
	printf("%d\n", res);
}