#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, act = 0;
	cin >> n >> k;
	vector<int> v;	
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		v.push_back(val);
		if(i < k)act += val;
	}	
	int ans = act, idx=0;
	for(int i = k; i < n; i++){
		act += v[i];
		act -= v[i-k];
		if(act < ans){			
			idx = i-k+1;
		}
		ans = min(ans, act);
	}
	cout << idx+1<<'\n';
}
