#include<bits/stdc++.h>
using namespace std;
int lastLet[27], lastNum[100010], b[100010], n, m, ans;
vector<int> P, T;
void pre(){
	int i = 0, j = -1; b[0] = -1;
	while(i < m){		
		while(j >= 0 && P[i] != P[j] && (P[j] || P[i] <= j)) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

void kmp(){
	int i = 0, j = 0;
	while(i < n){
		while(j >= 0 && T[i] != P[j] && (P[j] || T[i] <= j)){ 						
			j = b[j];
		}
		i++; j++;
		if(j == m){				
			ans++;
			j = b[j];			
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);	
	string s;
	while(cin >> s){
		P.clear();
		T.clear();
		int nu;
		cin >> nu;
		vector<int> vec;
		for(int i = 0; i < nu; i++){
			int val;
			cin >> val;
			vec.push_back(val);
		}

		memset(lastLet, -1, sizeof lastLet);
		memset(lastNum, -1, sizeof lastNum);
		
		for(int i = 0; i < vec.size(); i++){
			int num = vec[i];
			if(lastNum[num] == -1){
				lastNum[num] = i;
				P.push_back(0);
			}else{			
				P.push_back(i-lastNum[num]);			
				lastNum[num] = i;
			}
		}
		
		for(int i = 0; i < s.size(); i++){
			int num = s[i]-'a';
			if(lastLet[num] == -1){
				lastLet[num] = i;
				T.push_back(0);
			}else{
				T.push_back(i-lastLet[num]);			
				lastLet[num] = i;
			}
		}	
		n = T.size();
		m = P.size();
		pre();	
		ans = 0;
		kmp();
		cout << ans<<'\n';
	}
}