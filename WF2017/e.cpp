#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9
int n, t;
vector<pair<double, double> > v;

bool can(double val){
	double sum = 0.0;
	for(int i = 0; i < v.size(); i++){
		double div = (v[i].first)/(v[i].second+val);		
		sum += div;
	}		
	if(sum > t)return false;
	return true;
}
int main(){	
	double lo = -1e9;
	scanf("%d %d", &n, &t);
	for(int i = 0; i < n; i++){
		double d, s;
		cin >> d >> s;
		lo = max(lo, -s);
		v.push_back({d, s});
	}	
	double hi = 1e9, mid = 0.0, ans = 0.0;	
	while(hi-lo > EPS){	
		mid = (lo+hi)/2.0;				
		if(can(mid)){			
			ans = mid;
			hi = mid;
		}else lo = mid;
	}
	printf("%.9f\n", ans);
}