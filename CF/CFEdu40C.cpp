#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> v;
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		v.push_back(val);
	}
	if(n == 1){
		puts("YES");
		printf("1 %d\n", v[0]);
		return 0;
	}
	int dif = -1, may = -1;
	for(int i = 0; i < v.size()-1; i++){
		may = max(may, max(v[i], v[i+1]));
		if(abs(v[i]-v[i+1]) != 1)dif = abs(v[i]-v[i+1]);
	}
	if(dif == -1){
		puts("YES");
		printf("1 %d\n", may);
		return 0;
	}
	dif = -1;
	bool eq = true;
	for(int i = 0; i < v.size()-1; i++){
		int v1 = v[i], v2 = v[i+1];
		int dife = abs(v1-v2);
		if(dife == 0){
			eq = false;
			break;
		}
		if(dife == 1)continue;
		if(dif == -1){
			dif = dife;
		}else{
			if(dife != dif){
				eq = false;
				break;
			}
		}
	}
	if(!eq)puts("NO");
	else{		
		bool pos = true;
		for(int i = 0; i < v.size()-1; i++){
			int val = abs(v[i]-v[i+1]);
			if(val == 1){
				int men = min(v[i], v[i+1]);
				if(men % dif == 0){
					pos = false;
					break;
				}
			}
		}
		if(!pos){
			puts("NO");			
		}else{
			puts("YES");			
			int numC = ceil((double)may/dif);			
			printf("%d %d\n", numC, dif);
		}
	}	
	return 0;
}