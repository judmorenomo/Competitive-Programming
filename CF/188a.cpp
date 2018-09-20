#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n, k;
	cin >> n >> k;
	long long mid;
	if(n % 2 == 0){
		mid = n/2;
	}else{
		mid = (n/2)+1;
	}
	bool flag = false;
	if(k > mid){
		flag = true;
		k = k - mid;
	}
	long long res;
	if(flag){
		res = 2*k;
	}else{
		res = (2*k)-1;
	}
	cout << res<<'\n';
}