#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		long long n, m;
		scanf("%lld %lld", &n, &m);
		if(n > m){
			swap(n, m);
		}
		long long numMay = (m/2)+1, numMen = (m - numMay + 1);
		long long cantMay = numMay * (n/2), cantMen = numMen * ((n + 1) / 2) ;		
		printf("%lld\n", cantMay + cantMen);			
	}
}