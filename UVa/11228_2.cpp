#include<bits/stdc++.h>
using namespace std;
const int N = 30000;

vector<pair<int, int> > points;
int states = 1, may;
double longR = 0.0, shortR = 0.0;
vector < pair < double, pair < int, int > > > E;
vector < int > st [N];

int pr[N], rk[N];
int find(int x) { return pr[x] = ( pr[x] == x? x: find( pr[x] ) ); }

void merge( int x, int y ){
    x = find(x), y = find(y);    
   if( rand() % 1 ) pr[x] = y;
   else pr[y] = x;
}

double dist(int x1, int y1, int x2, int y2){
	double val1 = x1-x2, val2 = y1-y2;
	return sqrt(val1*val1 + val2*val2);
}

int rond(double val){
	return (int)(val+0.5);
}

int main(){
	int t, test = 1;
	scanf("%d", &t);
	while(t--){
		E.clear();
		states = 1;
		longR = 0.0;
		shortR = 0.0;		
		points.clear();
		int n;
		scanf("%d %d", &n, &may);
		for(int i = 0; i < n; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			points.push_back({x, y});
		}		
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				int x1 = points[i].first, y1 = points[i].second, x2 = points[j].first, y2 = points[j].second;		
				double d = dist(x1, y1, x2, y2);		
				E.push_back({d, {i, j}});
			}
		}		
		
		sort(E.begin(),E.end());
		for(int i = 0; i<n; i++) pr[i] = i;
    	int numd = n-1;
		for( auto ed : E ){
        if( find( ed.second.first ) != find( ed.second.second)){
        	double valor = ed.first;        	
        	if(valor <= may){
        		shortR += valor;
        	}else{
        		longR += valor;
        		states++;
        	}            
            merge( ed.second.first, ed.second.second );
            st[ed.second.first].push_back( ed.second.second);
            st[ed.second.second].push_back( ed.second.first);
            if( --numd == 0 ) break;
        }
    }	
		printf("Case #%d: %d %d %d\n", test, states, rond(shortR), rond(longR));
		test++;
	}	
}