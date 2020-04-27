#include<bits/stdc++.h>
using namespace std;
string a, b;

vector<int> all;

void go(int idx, int pos){
	if(idx == a.size()){
		all.push_back(pos);
		return;
	}
	if(b[idx] == '+')return go(idx+1, pos+1);
	if(b[idx] == '-')return go(idx+1, pos-1);
	go(idx+1, pos+1);
	go(idx+1, pos-1);
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin >> a >> b;
	int act = 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i] == '-')act--;
		else act++;
	}
	go(0, 0);
	int cont = 0;
	for(int i = 0; i < all.size(); i++){		
		if(all[i] == act)cont++;
	}
	cout <<setprecision(10)<< 1.0*cont/all.size()<<'\n';
}
