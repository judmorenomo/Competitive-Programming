#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a, b, c;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		if(val == 1){
			a.push_back(i+1);
		}else if(val == 2){
			b.push_back(i+1);
		}else c.push_back(i+1);
	}
	int men = min(a.size(), b.size());
	men = min(men, (int)c.size());	
	cout << men<<'\n';
	for(int i = 0; i < men; i++){
		cout << a[i]<<" "<<b[i]<<" "<<c[i]<<'\n';
	}	
}
