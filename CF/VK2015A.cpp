#include<bits/stdc++.h>
using namespace std;
map<string, int> nums;
map<int, int> cont;
map<int, int> res;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	//freopen("in.txt", "r", stdin);
	nums["polycarp"] = 0;
	cont[0] = 1;	
	int n, aux = 1, ans = 1;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s1, rep, s2;
		cin >> s1 >> rep >> s2;
		for(int j = 0; j < s1.size(); j++){
			s1[j] = tolower(s1[j]);
		}
		for(int j = 0; j < s2.size(); j++){
			s2[j] = tolower(s2[j]);
		}	

		if(nums.count(s1) == 0){			
			nums[s1] = aux;
			aux++;
		}

		if(nums.count(s2) == 0){			
			nums[s2] = aux;
			aux++;
		}
		int val1 = nums[s1], val2 = nums[s2];		
		if(cont[val2] != 0){
			cont[val1] = cont[val2] + 1;			
			ans = max(ans, cont[val1]);
		}
		
	}
	cout << ans <<'\n';
}