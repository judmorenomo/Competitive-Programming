#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		v.push_back(val);
	}
	vector<int> ans(2, 0);	
	int lPos = 0, rPos = n-1, turn = 0;	
	while(lPos <= rPos){			
		if(v[lPos] >= v[rPos]){
			ans[turn] += v[lPos];
			lPos++;
		}else {
			ans[turn] += v[rPos];
			rPos--;
		}
		turn = !turn;		
	}
	cout << ans[0]<<" "<<ans[1]<<'\n';
}
