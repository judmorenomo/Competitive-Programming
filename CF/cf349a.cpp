#include<bits/stdc++.h>
using namespace std;

double eps = 1e-6;
const double pi = acos(-1);
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int d, h, v, e;
	cin >> d >> h >> v >> e;
	double r = 1.0*d/2, sp = 1.0*v;	
	double rsp = 1.0*pi*r*r*e;

	if(rsp - sp > eps){
		cout << "NO\n";
	}else {
		double tot = 1.0*pi*r*r*h;
		double df = sp - rsp;		
		cout <<setprecision(10) << "YES\n"<<tot/df<<'\n';
	}
}
