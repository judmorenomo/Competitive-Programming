#include<bits/stdc++.h>
using namespace std;

int res[4] = {8, 4, 2, 6};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	if(n == 0){
		cout << "1\n";
	}else {
		cout << res[(n-1)%4]<<'\n';
	}
}
