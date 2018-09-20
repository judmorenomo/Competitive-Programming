#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	int q;
	scanf("%lld %d", &n, &q);
	while(q--){
		long long i, j;
		scanf("%lld %lld", &i, &j);
		i--; j--;
		long long res = 0;
		if((i + j) % 2 == 0){
			res += (i/2)*n;
			if(i % 2)res += (n+1)/2;
			res += (j/2);
		}else{
			res += (n*n + 1)/2;
			res += (i/2)*n;
			if(i % 2) res += (n/2);
			res += (j/2);
		}
		printf("%lld\n", res+1);
	}
}