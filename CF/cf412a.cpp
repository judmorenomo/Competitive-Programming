#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	bool changed = false;
	vector<pair<int, int> > vec;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		if(a != b)changed = true;
		vec.push_back({a, b});
	}
	if(changed){
		cout << "rated\n";
		return 0;
	}
	bool bet = false;
	for(int i = 1; i < n; i++){
		if(vec[i-1].first < vec[i].first){
			bet = true;
			break;
		}
	}
	if(bet){
		cout << "unrated\n";
	}else cout << "maybe\n";
}
