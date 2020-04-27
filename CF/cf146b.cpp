#include<bits/stdc++.h>
using namespace std;

int contD[1000010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, ans = 0;
	cin >> a >> b >> c;
	for(int i = 1; i <= a*b*c; i++){
		for(int j = i; j <= a*b*c; j+=i){
			contD[j]++;
		}
	}		
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= b; j++){
			for(int k = 1; k <= c; k++){
				ans += contD[i*j*k];
			}
		}
	}
	cout << ans % (1 << 30)<<'\n';
}
