#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
ll len[105];
ll cnt[105][26];
int MAX=88;
ll prefix[3][10005][26];
ll solve(int k,ll cur,int tar){
    if(cur==0) return 0;
    if(k==1) return prefix[1][cur][tar];
    if(k==2) return prefix[2][cur][tar];
    
    if(cur<=len[k-1]){
        return solve(k-1,cur,tar);
    }
    if(cur>len[k-1]){
        return cnt[k-1][tar]+solve(k-2,cur-len[k-1],tar);
    }
}

int main(){
    string x,b;
    cin>>x>>b;
    len[1] = x.length();
    len[2] = b.length();
    for(char i:x) cnt[1][i-'a']++;
    for(char i:b) cnt[2][i-'a']++;
    
    for(int i=1;i<=len[1];i++){
        for(int a=0;a<26;a++){
            prefix[1][i][a] = prefix[1][i-1][a];
        }
        prefix[1][i][x[i-1]-'a']++;
    }
    for(int i=1;i<=len[2];i++){
        for(int a=0;a<26;a++){
            prefix[2][i][a] = prefix[2][i-1][a];
        }
        prefix[2][i][b[i-1]-'a']++;
    }
    for(int i=3;i<=88;i++){
        len[i] = len[i-1]+len[i-2];
        for(int a=0;a<26;a++){
            cnt[i][a] = cnt[i-1][a]+cnt[i-2][a];
        }
        if(len[i]>1e18){
            MAX=i;
            break;
        }
    }
    int q;
    cin>>q;
    while(q--){
        ll l,r;
        char c;
        cin>>l>>r>>c;
        ll ans = solve(MAX,r,c-'a') - solve(MAX,l-1,c-'a');
        cout << ans << '\n';
    }
}