#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m, val1, val2;
	scanf("%d", &n);
	m = n/2;	
	cout << "? "<<1<<endl;
	cin >> val1;
	cout <<"? "<<1+m<<endl;
	cin >> val2;
	if(abs(val1-val2) % 2){
		cout << "! -1"<<endl;
		return 0;
	}
	if(abs(val1-val2) == 0){
		cout << "! 1"<<endl;
		return 0;
	}
	bool crece = false, flag = true;
	if(val1 - val2 < 0)crece = true;	
	int lo = 1, hi = m+1, mid, ans = hi+1, in1, in2;
	while(flag){		
		while(lo <= hi){
			mid = lo + (hi-lo)/2;
			cout << "? "<<mid<<endl;
			cin >> in1;
			cout << "? "<<(mid+m)%(n+1)<<endl;
			cin >> in2;
			int valor = in1 - in2;
			if(valor == 0){
				ans = mid;
				flag = false;
				break;
			}else if(valor > 0){
				if(crece){
					ans = mid;
					hi = mid-1;
				}else{
					ans = mid;
					lo = mid+1;
				}
			}else{
				if(crece){					
					lo = mid+1;
					ans = mid;
				}else{
					hi = mid-1;
					ans = mid;
				}
			}
		}
	}
	cout << "! "<<ans<<endl;
}