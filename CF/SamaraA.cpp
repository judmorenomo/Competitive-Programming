#include<bits/stdc++.h>
using namespace std;
int main(){
	int s, g;
	scanf("%d %d", &s, &g);
	if((s % g) || (s == g))puts("-1");
	else{
		int val = s/g;
		int val1 = 1, val2 = val-1;
		val1*=g, val2*=g;
		printf("%d %d\n", val1, val2);
	}
}