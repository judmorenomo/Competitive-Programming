#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, l;	
	cin >> n >> l;
	vector<int> val;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;		
		val.push_back(a);
	}	
	sort(val.begin(), val.end());
	double ans = max(1.0*val[0], 1.0*(l-val[val.size()-1]));	
	for(int i = 0; i < val.size()-1; i++){
		double aux = 0.5*(val[i+1]-val[i]);
		ans = max(ans, aux);
	}	
	cout << setprecision(10)<<ans<<'\n';
}
