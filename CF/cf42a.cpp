#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = -1;
	string nAns = "";	
	cin >> n;
	map<string, int> cont;
	for(int i = 0; i < n; i++){
		string a;
		cin >> a;
		cont[a]++;
		if(cont[a] > ans){
			ans = cont[a];
			nAns = a;
		}
	}
	cout << nAns<<'\n';
}
