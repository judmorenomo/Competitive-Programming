#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string pos, mov;
	cin >> pos >> mov;
	int act = 0;

	for(auto ch: mov){
		if(pos[act] == ch){
			act++;
		}
	}
	cout << act+1<<'\n';
}
