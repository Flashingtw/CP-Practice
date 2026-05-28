#include <bits/stdc++.h>
using namespace std;

bool ck(string &s){
    vector<vector<bool>> row(9,vector<bool>(9));
    vector<vector<bool>> col(9,vector<bool>(9));
    vector<vector<bool>> squ(9,vector<bool>(9));
    for(int i=0;i<81;i++){
        if(s[i]=='.') continue;
        int n = s[i]-'1';
        int r = i/9;
        int c = i%9;
        if(row[r][n]||col[c][n]||squ[(r/3)*3+c/3][n]){
            return false;
        }
        row[r][n]=1;
        col[c][n]=1;
        squ[(r/3)*3+c/3][n]=1;
    }
    return true;
}

bool chk(string &s,int idx,char t){
    int r=idx/9;
    int c=idx%9;
    for(int i=0;i<9;i++){
        if(s[i*9+c]==t) return false;
    }
    for(int i=0;i<9;i++){
        if(s[r*9+i]==t) return false;
    }
    r/=3 , r*=3;
    c/=3 , c*=3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(s[(r+i)*9+c+j] == t) return false;
        }
    }
    return true;
}
bool a;
void dfs(string &s,int idx){
    if(a) return;
    if(idx==81){
        cout << s << '\n';
        a=1;
        return;
    }
    if(s[idx]!='.'){
        dfs(s,idx+1);
        return;
    }
    for(char i='1';i<='9';i++){
        if(chk(s,idx,i)){
            s[idx]=i;
            dfs(s,idx+1);
            s[idx]='.';
        }
    }
}
void solve(){
    a=0;
    string s;
    cin>>s;
    if(!ck(s)){
        cout << "No solution.\n";
        return;
    }
    dfs(s,0);
    if(!a) cout << "No solution.\n";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}