#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long val, val2;
	cin >> val;
	val2 = (val+1)/2;
	int sign = 1;
	if(val % 2)sign*=-1;
	cout << val2*sign<<'\n';
}
