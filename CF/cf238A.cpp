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

	sort(v.begin(), v.end());
	for(int i = 0; i< v.size(); i++)cout << v[i]<<" ";
}

