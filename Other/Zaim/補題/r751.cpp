#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
int n;
bool chk(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}
ll dfs(int pos,int m,int s,bool has_L){
    if(m==3||s==3) return 0;
    if(pos==n){
        return has_L;
    }
    ll ans=0;
    if(str[pos] == '_'){
        ans += 5*dfs(pos+1,m+1,0,has_L);
        ans += 1*dfs(pos+1,0,s+1,true);
        ans += 20*dfs(pos+1,0,s+1,has_L);
    }
    else{
        if(chk(str[pos])){
            ans = dfs(pos+1,m+1,0,has_L);
        }
        else{
            has_L = has_L||str[pos]=='L';
            ans = dfs(pos+1,0,s+1,has_L);
        }
    }
    return ans;

}
int main(){
    cin>>str;
    n = str.length();
    cout << dfs(0,0,0,0);
}