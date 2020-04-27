#include<bits/stdc++.h>
using namespace std;

const double v = 50.0;

double dist(double x1, double y1, double x2, double y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	double ans = 0;
	vector<pair<int, int> > p;
	for(int i = 0; i < n; i++){
		int a, b;		
		cin >> a >> b;
		p.push_back({a, b});
	}
	for(int i = 0; i < p.size()-1; i++){
		ans += dist(p[i].first, p[i].second, p[i+1].first, p[i+1].second)/v;
	}
	cout <<setprecision(10)<< ans*1.0*k<<'\n';
}
