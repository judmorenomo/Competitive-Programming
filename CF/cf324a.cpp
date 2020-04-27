#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, t, dig = 1;
	cin >> n >> t;	
	if(t == 10)dig++;
	if(dig > n)cout <<"-1\n";
	else {
		int z = n - dig;
		cout << t;
		for(int i = 0; i < z; i++)cout << 0;
		cout <<'\n';
	}	
}
