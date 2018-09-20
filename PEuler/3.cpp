#include<bits/stdc++.h>
using namespace std;
#define MAX_N 600851475143
bool isPrime(int n){
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0)return false;
	}
	return true;
}
int main(){
	/*long long ans;
	for(long long i = 2; i*i <MAX_N; i++){		
		if(isPrime(i) && MAX_N % i == 0){
			ans = i;
		}
	}
	printf("%lld\n", ans);*/
	long long sum = 2;
	for(int i = 3; i < 2000000; i += 2){
		if(isPrime(i))sum += i;
	}
	printf("%lld\n", sum);
}