#include<bits/stdc++.h>
using namespace std;
bool mat[55][55], vis[55][55][4];
int n, m, dist[55][55][4];

int orie(string act){
    if(act == "north")return 0;
    if(act == "east")return 1;
    if(act == "south")return 2;
    return 3;
}
bool valid(int r, int c){
    return r >= 1 && r < n && c >= 1 && c < m && !mat[r][c];
}

int avRow(int o, int cant){
    if(o == 0){
        return -1*cant;
    }
    if(o == 2){
        return cant;
    }
    return 0;
}
int avCol(int o, int cant){
    if(o == 1){
        return cant;
    }
    if(o == 3){
        return -1*cant;
    }
    return 0;
}

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    while(n || m){
        memset(dist, -1, sizeof dist);
        memset(mat, 0, sizeof mat);
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int val;
                scanf("%d", &val);
                if(!val)continue;
                mat[i][j] = mat[i+1][j] = val;
                mat[i][j+1] = mat[i+1][j+1] = val;
            }
        }
        int sx, sy, fx, fy;
        string ori;
        scanf("%d %d %d %d", &sx, &sy, &fx, &fy);
        cin >> ori;
        int orAct = orie(ori);
        vis[sx][sy][orAct] = 1;
        dist[sx][sy][orAct] = 0;
        queue<pair<pair<int, int>, int > > q;
        q.push({{sx, sy}, orAct});
        while(!q.empty()){
            pair<pair<int, int>, int > u = q.front(); q.pop();
            int xAux = u.first.first, yAux = u.first.second, orien = u.second;
            if(xAux == fx && yAux == fy)break;
            for(int i = 1; i <= 3; i++){
                if(valid(xAux+avRow(orien, i), yAux+avCol(orien, i))){
                        if(!vis[xAux+avRow(orien, i)][yAux+avCol(orien, i)][orien]){
                                vis[xAux+avRow(orien, i)][yAux+avCol(orien, i)][orien] = 1;
                                dist[xAux+avRow(orien, i)][yAux+avCol(orien, i)][orien] = dist[xAux][yAux][orien]+1;
                                q.push({{xAux+avRow(orien, i), yAux+avCol(orien, i)}, orien});
                        }

                }else break;
            }
            if(!vis[xAux][yAux][(orien+1)%4]){
                vis[xAux][yAux][(orien+1)%4] = 1;
                dist[xAux][yAux][(orien+1)%4] = dist[xAux][yAux][orien] + 1;
                q.push({{xAux, yAux}, (orien+1)%4});
            }
            if(!vis[xAux][yAux][(orien+3)%4]){
                vis[xAux][yAux][(orien+3)%4] = 1;
                dist[xAux][yAux][(orien+3)%4] = dist[xAux][yAux][orien] + 1;
                q.push({{xAux, yAux}, (orien+3)%4});
            }
        }
        int ans = 987654321;
        bool pos = false;
        for(int i = 0; i < 4; i++){
            int valor = dist[fx][fy][i];
            if(valor != -1){
                ans = min(ans, valor);
                pos = true;
            }
        }
        if(!pos)ans = -1;
        printf("%d\n", ans);
        scanf("%d %d", &n, &m);
    }
}