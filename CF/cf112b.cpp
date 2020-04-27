#include<bits/stdc++.h>
using namespace std;
int n, k;
bool can(int val){	
	int sum = val;
	long long act = k;
	while(true){		
		sum += (val/act);
		if(val/act == 0)break;
		act*= k;
	}
	if(sum >= n)return true;
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin >> n >> k;
	int lo = 1, hi = 1e9, mi;
	while(lo <= hi){
		mi = lo + (hi-lo)/2;		
		if(can(mi)){
			hi = mi-1;
		}else lo =  mi+1;
	}
	if(!can(mi))mi++;
	cout << mi<<'\n';
}
