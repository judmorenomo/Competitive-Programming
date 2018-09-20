#include<bits/stdc++.h>
using namespace std;
int main(){	
	int n, a, b, c;
	scanf("%d %d %d %d", &n, &a, &b, &c);
	if(a > b)swap(a, b);
	if(b > c)swap(b, c);
	if(a > b)swap(a, b);
	int ans = -1;
	for(int i = 0; i <= n/a; i++){
		for(int j = 0; j <= n/b; j++){
			int sum = (a*i) + (b*j), falt = n - sum;			
			if(falt == 0)ans = max(ans, i+j);
			if(falt > 0){
				if(falt % c == 0){					
					ans = max(ans, i+j+(falt/c));
				}
			}
		}
	}
	printf("%d\n", ans);
}