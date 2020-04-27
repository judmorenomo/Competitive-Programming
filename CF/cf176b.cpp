#include<bits/stdc++.h>
using namespace std;
long long n, k;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin >> n >> k;	
	long long tot = 1 + (k*(k-1))/2;	
	if(n == 1){
		cout << "0\n";
		return 0;
	}
	if(n > tot){
		cout << "-1\n";
	}else{
		long long sum = (k*(k-1))/2;
		if(n <= k){
			cout << 1<<'\n';
		}else {
			long long lo = 1, hi = k-1, mi, aux, val;
			while(lo <= hi){
				mi = lo + (hi-lo)/2;
				aux = k-mi-1;
				val = aux*(aux+1)/2;

				val = sum - val;
				if(val >= n-1){
					hi = mi-1;
				}else lo = mi+1;
			}					
			if(val < n-1)mi++;
			cout << mi<<'\n';
		}
	}
	
}
