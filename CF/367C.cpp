#include<bits/stdc++.h>
using namespace std;
const long long inf = 1e14 + 10;
vector<int> v;
string vs[100010][2];
unsigned long long dp[100010][3];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);	
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int val; cin >> val;
		v.push_back(val);
	}
	for(int i = 0; i < n; i++){
		string w; cin >> w;
		string aux = w;
		reverse(aux.begin(), aux.end());
		vs[i][0] = w;
		vs[i][1] = aux
;
	}
	for(int i = 0; i < n; i++){
		dp[i][0] = dp[i][1] = inf;
	}	
	dp[0][0] = 0;
	dp[0][1] = v[0];
	for(int i = 1; i < n; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				if(vs[i][k] >= vs[i-1][j]){
					dp[i][k] = min(dp[i][k], dp[i-1][j]+k*v[i]);
				}
			}
		}
	}
	long long ans = min(dp[n-1][0], dp[n-1][1]);
	if(ans == inf)ans = -1;
	cout << ans<<'\n';
}