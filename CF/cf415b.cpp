#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, f;
	cin >> n >> f;
	long long sum = 0;
	vector<long long> vec;	
	for(int i = 0; i < n; i++){
		long long k, l;
		cin >> k >> l;
		sum += min(k, l);
		int valN = min(2*k, l)-min(k, l);
		vec.push_back(1ll*valN);
	}	
	sort(vec.rbegin(), vec.rend());
	for(int i = 0; i < f; i++){
		sum += vec[i];
	}
	cout << sum<<'\n';
}
