#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, k;
	cin >> n >> k;
	long long ev = n/2, od = (n+1)/2;
	if(k <= od){
		cout << 2*k - 1<<'\n';
	}else {
		k -= od;
		cout << 2*k<<'\n';
	}
}
