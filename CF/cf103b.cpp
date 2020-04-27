#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int xa, ya, xb, yb;
	cin >> xa >> ya >> xb >> yb;
	if(xa > xb)swap(xa, xb);
	if(ya > yb)swap(ya, yb);	
	int n;
	cin >> n;
	vector<pair<pair<int, int >, int > > rad;
	for(int i = 0; i < n; i++){
		int x, y, r;
		cin >> x >> y >> r;
		rad.push_back({{x, y}, r});
	}	
	int xact = xa, yact = ya, ans = 0;
	while(yact <= yb){
		bool cov = false;
		for(int i = 0; i < rad.size(); i++){
			int xrad = rad[i].first.first, yrad = rad[i].first.second, ra = rad[i].second;
			int dist = (xact-xrad)*(xact-xrad) + (yact-yrad)*(yact-yrad);
			if(dist <= ra*ra){								
				cov = true;				
				break;
			}
		}		
		ans += !cov;
		yact++;
	}	
	xact = xa+1; yact = yb;
	while(xact <= xb){
		bool cov = false;
		for(int i = 0; i < rad.size(); i++){
			int xrad = rad[i].first.first, yrad = rad[i].first.second, ra = rad[i].second;
			int dist = (xact-xrad)*(xact-xrad) + (yact-yrad)*(yact-yrad);
			if(dist <= ra*ra){								
				cov = true;				
				break;
			}
		}		
		ans += !cov;
		xact++;
	}	
	xact = xb; yact = ya;
	while(yact < yb){
		bool cov = false;
		for(int i = 0; i < rad.size(); i++){
			int xrad = rad[i].first.first, yrad = rad[i].first.second, ra = rad[i].second;
			int dist = (xact-xrad)*(xact-xrad) + (yact-yrad)*(yact-yrad);
			if(dist <= ra*ra){								
				cov = true;				
				break;
			}
		}		
		ans += !cov;
		yact++;
	}
	xact = xa+1, yact = ya;
	while(xact < xb){
		bool cov = false;
		for(int i = 0; i < rad.size(); i++){
			int xrad = rad[i].first.first, yrad = rad[i].first.second, ra = rad[i].second;
			int dist = (xact-xrad)*(xact-xrad) + (yact-yrad)*(yact-yrad);
			if(dist <= ra*ra){								
				cov = true;				
				break;
			}
		}		
		ans += !cov;
		xact++;
	}
	cout << ans<<'\n';
}
