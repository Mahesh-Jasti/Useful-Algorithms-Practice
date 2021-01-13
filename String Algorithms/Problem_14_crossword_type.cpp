// Longest connected 1s -- Backtracking
#include <bits/stdc++.h>
using namespace std;

int n,m;
string pattern;
int traverse(const vector<vector<char>> &v, vector<vector<bool>> &b, int i, int j, int pattern_idx){
    if(v[i][j]==pattern[pattern_idx]) b[i][j]=true;
    else return -1;
    pattern_idx++;
    if(pattern_idx==pattern.size()) return 1;
    int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    for(int k=0;k<8;k++){
        int nextx=i+dir[k][0];
        int nexty=j+dir[k][1];
        int val=0;
        if(nextx<0 || nextx>n-1 || nexty<0 || nexty>m-1) val=0;
        else if(v[nextx][nexty]==pattern[pattern_idx]) val=1;
        if(val && !b[nextx][nexty]){
            return traverse(v,b,nextx,nexty,pattern_idx);
        }
    }
    b[i][j]=false;
}

int main() {
    // your code goes here
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char> (m,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> v[i][j];
    cin >> pattern;
    vector<vector<bool>> b(n, vector<bool> (m,false));
    int x=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            x=traverse(v,b,i,j,0);
            if(x==1) break;
        }
        if(x==1) break;
    }
    if(x==1) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
