#include<bits/stdc++.h>
using namespace std;
#define MAX_N 4000000
int main(){
	int f1 = 0, f2 = 1, fib = f1 + f2, sum = 0;	
	while(fib <= MAX_N){		
		f1 = f2;
		f2 = fib;
		fib = f1+f2;
		if(!(fib % 2))sum += fib;		
	}
	printf("%d\n", sum);
}