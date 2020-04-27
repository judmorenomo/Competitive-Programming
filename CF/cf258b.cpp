#include<bits/stdc++.h>
using namespace std;
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
	int cont = 0, beg = 0, en = -1;
	bool desc = false;
	for(int i = 1; i < n; i++){
		if(v[i] < v[i-1]){
			if(!desc){
				cont++;
				beg = i-1;
				desc = true;
			} 
		}else {
			if(desc){
				desc = false;
				en = i-1;
			}			
		}
	}	
	if(cont == 0){		
		cout << "yes\n1 1\n";
		return 0;		
	}
	if(en == -1)en = n-1;
	if(cont > 1){
		cout << "no\n";
	}else {
		int valL, valR;
		if(beg == 0)valL = -1;
		else valL = v[beg-1];
		if(en == n-1)valR = INT_MAX;
		else valR = v[en+1];

		if(valL < v[en] && valR > v[beg]){
			cout << "yes\n"<<beg+1<<" "<<en+1<<'\n';
		}else cout << "no\n";	
	}
}
