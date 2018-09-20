#include<bits/stdc++.h>
using namespace std;
vector<int> res;
string s1, s2;
void go(int i, int pos){		
	if(i == s2.size()){
		res.push_back(pos);
		return;	
	}
	if(s2[i] == '+') return go(i+1, pos+1);
	if(s2[i] == '-') return go(i+1, pos-1);
	go(i+1, pos+1);
	go(i+1, pos-1);
	return;
}
int main(){	
	cin >> s1 >> s2;
	int pos = 0;
	for(int i = 0; i < s1.size(); i++){
		if(s1[i] == '+')pos++;
		else pos--;
	}		
	go(0, 0);
	int cont = 0;
	for(int i = 0; i < res.size(); i++){
		if(res[i] == pos)cont++;
	}
	double ans = (cont*1.0)/res.size();
	printf("%.9f\n", ans);
}