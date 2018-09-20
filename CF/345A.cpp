#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	int ans = 0;	
	while(a > 0 && b > 0){
		if(a <= b){
			a++;
			b -= 2;
		}else{
			b++;
			a -= 2;
		}
		if(a >= 0 && b >= 0){
			ans++;
		}
	}
	printf("%d\n", ans);
}