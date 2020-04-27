#include<bits/stdc++.h>
using namespace std;

string res[3] = {"Carrots", "Kiwis", "Grapes"};

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k, t;
	cin >> n >> m >> k >> t;
	vector<pair<int, int> > waste;
	for(int i = 0; i < k; i++){
		int a, b;
		cin >> a >> b;			
		waste.push_back({a, b});
	}		
	sort(waste.begin(), waste.end());	

	

	for(int i = 0; i < t; i++){
		int a, b;
		cin >> a >> b;		
		int aux = lower_bound(waste.begin(), waste.end(), make_pair(a, b)) - waste.begin();				
		int val = (1ll*a*m - 1ll*(m-b) - 1ll*aux - 1ll) % 3;
		
		string ans = res[val];
		if(waste[aux].first == a && waste[aux].second == b)ans = "Waste";
		cout << ans<<'\n';
	}
}


