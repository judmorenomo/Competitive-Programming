#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, a, b;
	vector<char> s;	
	vector<int> nums;
	scanf("%d %d %d", &n, &a, &b);
	int sum = a+b, auxA = a, auxB = b;	
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		s.push_back(c);		
	}		
	int ans = 0;
	for(int i = 0; i < s.size(); i++){		
		if(s[i] == '.'){						
			int pos = i+1;
			int cont = 1;
			while(s[pos] == '.'){
				cont++;
				pos++;
			}	
			int val1, val2;
			if(cont % 2){				
				val1 = (cont/2)+1;
				val2 = cont/2;				
			}else{
				val1 = val2 = cont/2;
			}	
			if(a > b){									
				ans += min(a, val1);
				a -= min(a, val1);
				ans += min(b, val2);
				b -= min(b, val2);					
			}else{
				ans += min(b, val1);
				b -= min(b, val1);
				ans += min(a, val2);					
				a -= min(a, val2);					
			}		
			i = pos-1;		
		}
	}
	printf("%d\n", ans);
}	