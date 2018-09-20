#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, h, a, b, q;
	scanf("%d %d %d %d %d", &n, &h, &a, &b, &q);
	while(q--){
		int f1, h1, f2, h2;
		scanf("%d %d %d %d", &f1, &h1, &f2, &h2);
		int res = 0;
		if(f1 == f2){
			printf("%d\n", abs(h1 - h2));
		}else{
			if(!(h1 >= a && h1 <= b)){
				int val1 = abs(a-h1), val2 = abs(b-h1);	
				if(val1 <= val2){
					res += val1;
					h1 = a;
				}else{
					res += val2;
					h1 = b;
				}
			}
			res += abs(f1-f2);
			res += abs(h1 - h2);
			printf("%d\n", res);
		}
	}
}