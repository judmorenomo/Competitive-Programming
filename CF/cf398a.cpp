#include<bits/stdc++.h>
using namespace std;

bool isIn[100010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		v.push_back(val);
	}
	int act = n, pos = 0;
	while(pos < n){
		isIn[v[pos]] = 1;
		if(isIn[act]){
			while(isIn[act]){
				cout << act<<" "; 
				act--;
			}
		}
		cout <<'\n';
		pos++;
	}	
}
