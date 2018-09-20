#include<bits/stdc++.h>
using namespace std;
bool arr[1010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m, q;
	string s, t;
	cin >> n >> m >> q;
	cin >> s; cin >> t;
	bool no = false;
	if(s.size() >= t.size()){
		for(int i = 0; i < s.size() - t.size() + 1; i++){
			string aux = s.substr(i, t.size());
			if(aux == t)arr[i + t.size()-1] = 1;
		}
	}else{
		no = true;
	}
	while(q--){		
		int l, r, ans = 0;
		cin >> l >> r;
		l--; r--;
		if(!no){
			for(int i = l; i <= r; i++){
				if(arr[i] && (i - t.size() + 1 >= l))ans++;
			}		
			cout << ans<<'\n';	
		}else{
			cout << "0\n";
		}		
	}
}