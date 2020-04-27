#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, men = 1e6, sum = 0;
	cin >> n >> k;
	vector<int> neg, pos;	
	for(int i = 0; i < n; i++){
		int val; cin >> val;
		sum += val;
		men = min(men, abs(val));
		if(val < 0)neg.push_back(val);
		else pos.push_back(val);
	}	
	sort(neg.begin(), neg.end());
	int kk = k;	
	for(int i = 0; i < neg.size() && kk > 0; i++){
		sum -= 2*(neg[i]);
		kk--;
	}
	if(kk){
		kk = kk % 2;
		if(kk)sum -= 2*men;
	}
	cout << sum<<'\n';
}
