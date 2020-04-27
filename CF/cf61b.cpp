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
	int ans = -1;
	for(int i = 0; i < n; i++){		
		int valL = 0, valR = 0, act = v[i];
		for(int j = i-1; j >= 0; j--){
			if(act >= v[j]){
				valL++;
				act = v[j];
			}else break;
		}
		act = v[i];
		for(int j = i+1; j < n; j++){
			if(act >= v[j]){
				valR++;
				act = v[j];
			}else break;
		}
		ans = max(ans, valL+valR+1);
	}
	cout << ans<<'\n';
}
