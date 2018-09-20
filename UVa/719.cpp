#include<bits/stdc++.h>
using namespace std;

int minExp(string word){
	string s2 = word+word;
	int off = 0, answer = 0;
	for(int i = 1; i < s2.size(); i++){
		if(s2[i] < s2[answer]){
			answer = i;
			off = 0;
		}else if(s2[i] == s2[answer+off]){
			off++;
		}else if(s2[i] < s2[answer+off]){
			answer = i-off;
			off = 0;
			i = answer;
		}else off = 0;
	}
	return answer;
}
int main(){
	//freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--){
		string word;
		cin >> word;		
		cout << minExp(word)+1<<'\n';
	}
}