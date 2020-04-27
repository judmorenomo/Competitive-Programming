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
	for(int i = 0; i < n; i++){
		int men = INT_MAX, may = 0;
		if(i > 0)men = min(men, abs(v[i]-v[i-1]));
		if(i < n-1)men = min(men, abs(v[i]-v[i+1]));
		
		if(i != 0)may = max(may, abs(v[i]-v[0]));
		if(i != n-1)may = max(may, abs(v[i]-v[n-1]));
		cout << men<<" "<<may<<'\n';
	}
}
