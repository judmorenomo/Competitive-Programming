#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x0, y0;
	cin >> n >> x0 >> y0;
	set<pair<int, int> > s;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		int num = b - y0, den = a - x0;
		if(den == 0)s.insert({0, 0});
		else if(num == 0)s.insert({0, 1});
		else {
			int gc = __gcd(num, den);
			s.insert({num/gc, den/gc});
		}		
	}
	cout << s.size()<<'\n';
}
