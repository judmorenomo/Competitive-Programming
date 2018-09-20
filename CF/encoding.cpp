#include<bits/stdc++.h>
using namespace std;
int n, m, lastLet[200010], lastLet2[200010], b[200010];
vector<int> pa, te, matches;
int a[30], b2[30];
string t, p;

void pre(){
	int i = 0, j = -1; b[0] = -1;
	while(i < m){
		while(j >= 0 && pa[i] != pa[j] && (pa[j] || pa[i] <= j)) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

void kmp(){
	int i = 0, j = 0;
	while(i < n){
		while(j >= 0 && te[i] != pa[j] && (pa[j] || te[i] <= j))j = b[j];
		i++; j++;
		if(j == m){
			matches.push_back(i-j);
			//cout << "MATCH EN "<<i-j<<'\n';
			j = b[j];
		}
	}
}

bool check(int pos){
	memset(b2, -1, sizeof b2);
	for(int i = 0; i < 26; i++){
		if(a[i] != -1){			
			b2[i] = t[a[i] + pos] - 'a';
		}
	}
	for(int i = 0; i < 26; i++){		
		if(b2[i] != -1 && b2[b2[i]] != -1 && b2[b2[i]] != i)return false;
	}
	return true;
}
int main(){	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;	
	cin >> t;
	cin >> p;
	memset(lastLet, -1, sizeof lastLet);
	memset(lastLet2, -1, sizeof lastLet2);
	for(int i = 0; i < p.size(); i++){
		int num = p[i] - 'a';
		if(lastLet[num] == -1){
			lastLet[num] = i;
			pa.push_back(0);
		}else{
			pa.push_back(i - lastLet[num]);
			lastLet[num] = i;
		}		
	}
	for(int i = 0; i < t.size(); i++){
		int num = t[i] - 'a';
		if(lastLet2[num] == -1){
			lastLet2[num] = i;
			te.push_back(0);
		}else{
			te.push_back(i - lastLet2[num]);
			lastLet2[num] = i;
		}		
	}


	pre();
	kmp();

	memset(a, -1, sizeof a);
	for(int i = 0; i <p.size(); i++){
		a[p[i]-'a'] = i;
	}	
	vector<int> res;
	for(int i = 0; i < matches.size(); i++){
		if(check(matches[i]))res.push_back(matches[i]+1);
	}
	cout << res.size()<<'\n';
	for(int i = 0; i < res.size(); i++){
		cout << res[i]<<" ";
	}
	cout <<'\n';

}