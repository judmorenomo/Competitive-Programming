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
	int f = v[0], pos = 0;
	while(v[pos] == f)pos++;
	int ff = v[n-1], poss = n-1;
	while(v[poss] == ff)poss--;
	if(pos > poss)cout << 0<<'\n';
	else cout << poss-pos+1<<'\n';

}
