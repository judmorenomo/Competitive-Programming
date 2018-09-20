#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int t, cas = 1;
	cin >> t;
	while(t--){
		int val;
		string p;
		cin >> val >> p;
		int pot = 0, dam = 0, contS = 0;		
		int act = (1 << pot);
		for(int i = 0; i < p.size(); i++){
			if(p[i] == 'S'){
				dam += act;
				contS++;
			}else{
				pot++;
				act = (1 << pot);
			}
		}		
		if(contS > val){
			cout << "Case #"<<cas<<": IMPOSSIBLE"<<'\n';
		}else{
			int res = 0;
			while(dam > val){
				res++;
				int auxDam = 0, auxPot = 0, damAct = (1 << auxPot);				
				for(int i = p.size()-1; i >= 1; i--){
					if(p[i] == 'S' && p[i-1] == 'C'){
						p[i] = 'C';
						p[i-1] = 'S';
						break;
					}
				}
				for(int i = 0; i < p.size(); i++){
					if(p[i] == 'S'){
						auxDam += damAct;						
					}else{
						auxPot++;
						damAct = (1 << auxPot);
					}
				}
				dam = auxDam;
			}
			cout <<"Case #"<<cas<<": "<< res<<'\n';
		}
		cas++;
	}
}