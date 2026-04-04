#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
int next_pos[26][N];

int main(){
    string s,t;
    cin>>s>>t;
    ll n = s.size(),m = t.size();
    for(int i=0;i<26;i++){
        next_pos[i][n] = INF;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<26;j++){
            if(s[i]=='a'+j){
                next_pos[j][i] = i;
            }
            else{
                next_pos[j][i] = next_pos[j][i+1];
            }
        }
    }
    vector<int> f(n+1);
    for(int i=0;i<n;i++){
        int p = next_pos[t[0]-'a'][i];;
        for(int j=1;j<m;j++){
            if(p==INF){
                f[i]=INF;
                break;
            }
            p = next_pos[t[j]-'a'][p+1];           
        }
        f[i]=p;
    }
    ll total = n*(n+1LL)/2;
    ll diff = 0;
    for(int i=0;i<n;i++){
        if(f[i]==INF) continue;
        diff+=n-f[i];
    }
    cout << total - diff;
}