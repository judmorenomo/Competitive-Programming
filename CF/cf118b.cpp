#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<double, int> p1, pair<double, int> p2){
	if(p1.first > p2.first)return 1;
	if(p1.first < p2.first)return 0;
	return p1.second < p2.second ? 1 : 0;
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, t1, t2, k;
	cin >> n >> t1 >> t2 >> k;
	double perc = 1.0*k/100;
	vector<pair<double, int> > sc;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;		
		double sc1 = 1.0*a*t1*(1.0-perc) + 1.0*b*t2, sc2 = 1.0*b*t1*(1.0-perc)+1.0*a*t2;
		sc.push_back({max(sc1, sc2), i});
	}

	sort(sc.begin(), sc.end(), cmp);
	for(int i = 0; i < sc.size(); i++){
		cout <<fixed<<setprecision(2)<<sc[i].second+1<<" "<< sc[i].first<<'\n';
	}

}
