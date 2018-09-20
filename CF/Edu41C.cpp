#include<bits/stdc++.h>
using namespace std;
int em0[5], em1[5];
int main(){
	memset(em0, 0, sizeof em0);
	memset(em1, 0, sizeof em1);
	int n;
	cin >> n;
	string s;
	cin.ignore();

	for(int k = 0; k < 4; k++){
		for(int i = 0; i < n; i++){
			getline(cin, s);
			for(int j = 0; j < n; j++){
				int val = s[j]-'0';
				int pos = (i+j)%2;				
				if(!pos){
					if(val == 0){
						em0[k]++;
					}else em1[k]++;
				}else{
					if(val == 0){
						em1[k]++;
					}else em0[k]++;
				}
			}					
		}
		if(k != 3)getline(cin, s);
	}

	int ans = 987654321;
	int aux1, aux2, aux3;
	aux1 = min(em0[0]+em0[1]+em1[2]+em1[3], em0[0]+em1[1]+em0[2]+em1[3]);
	aux2 = min(em0[0]+em1[1]+em1[2]+em0[3], em1[0]+em1[1]+em0[2]+em0[3]);
	aux3 = min(em1[0]+em0[1]+em1[2]+em0[3], em1[0]+em0[1]+em0[2]+em1[3]);
	aux1 = min(aux1, min(aux2, aux3));
	ans = min(ans, aux1);
	printf("%d\n", ans);
}