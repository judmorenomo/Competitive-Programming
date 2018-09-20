#include<bits/stdc++.h>
using namespace std;
map<string, int> ma;

class UnionFind{
private: vector<int> p, rank;
public:
    UnionFind(int n){
        p.assign(2*n, 0);
        rank.assign(2*n, 0);
        for(int i = 0; i < n; i++){
            p[i] = i;
            p[i+n] = i+n;
        }
    }
    int findSet(int i){
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) p[y] = x;
            else{
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0 ; i < n; i++){
        string s;
        cin >> s;
        if(ma.find(s) == ma.end()){
            ma[s] = ma.size();
        }
    }
    UnionFind UF(n);
    for(int i = 0; i < m; i++){
        int id;
        string s1, s2;
        cin >> id >> s1 >> s2;
        int id1 = ma[s1], id2 = ma[s2];
        if(id == 1){
            if((UF.findSet(id1) == UF.findSet(id2+n)) || (UF.findSet(id1+n) == UF.findSet(id2))){
                cout << "NO"<<'\n';
            }else{
                cout << "YES"<<'\n';
                UF.unionSet(id1, id2);
                UF.unionSet(id1+n, id2+n);
            }
        }else{
            if((UF.findSet(id1) == UF.findSet(id2)) || (UF.findSet(id1+n) == UF.findSet(id2+n))){
                cout << "NO"<<'\n';
            }else{
                cout << "YES"<<'\n';
                UF.unionSet(id1, id2+n);
                UF.unionSet(id1+n, id2);
            }
        }
    }

    for(int i = 0; i < q; i++){
        string s1, s2;
        cin >> s1 >> s2;
        int id1 = ma[s1], id2 = ma[s2];
        if(UF.isSameSet(id1, id2))cout << "1"<<'\n';
        else if(UF.findSet(id1) == UF.findSet(id2+n))cout << "2"<<'\n';
        else cout << "3"<<'\n';
    }

}