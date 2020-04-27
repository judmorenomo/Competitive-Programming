#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int p, q, l, r;
	cin >> p >> q >> l >> r;
	vector<pair<int, int>> v1, v2;
	for(int i = 0; i < p; i++){
		int a, b;
		cin >> a >> b;
		v1.push_back({a, b});
	}
	for(int i = 0; i < q; i++){
		int a, b;
		cin >> a >> b;
		v2.push_back({a, b});
	}
	int ans = 0;
	for(int i = l; i <= r; i++){
		bool pos = false;
		for(int j = 0; j < v2.size(); j++){
			int x = v2[j].first+i, y = v2[j].second+i;
			for(int k = 0; k < v1.size(); k++){
				int a = v1[k].first, b = v1[k].second;
				if(x <= b && y >= a){
					ans++;
					pos = true;
					break;
				}
			}
			if(pos)break;
		}
	}
	cout << ans<<'\n';
}
