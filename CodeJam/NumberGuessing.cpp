#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int lo, mid, hi, n;
		scanf("%d %d", &lo, &hi);
		scanf("%d", &n);
		while(lo <= hi){
			mid = lo + (hi-lo)/2;			
			printf("%d\n", mid);
			string word;
			cin >> word;
			if(word == "CORRECT")break;
			else if(word == "TOO_SMALL"){
				lo = mid+1;
			}else{
				hi = mid-1;
			}
		}
	}
}