#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<int> val;
	int ang = 180, lad = 3;	
	for(int i = 0; i < 1000; i++){
		int m = ang % lad;
		if(m == 0){
			val.insert(ang/lad);
		}		
		ang += 180;
		lad++;
	}
	int n;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		if(val.find(x) != val.end()){
			cout << "YES\n";
		}else cout << "NO\n";
	}
}
