#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	for(int i = 0; i < a.size(); i++){
		a[i] = tolower(a[i]);
		b[i] = tolower(b[i]);
		if(a[i] < b[i]) {
			cout << "-1";
			return 0;
		}else if(a[i] > b[i]){
			cout << "1";
			return 0;
		}
	}
	cout << "0";
}
