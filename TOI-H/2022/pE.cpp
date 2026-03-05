#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,s;
bool chk(int k){
    pii prev={-1,-1};
    int cur=0;
    for(int i=0;i<s;i++){
        int r = cur/m +1;
        int c = cur%m +1;
        auto [pr,pc] = prev;
        if(i!=0&&(pr==r||pc==c||abs(r-pr)==abs(c-pc))){
            return false;
        }
        cur = (cur+k)%s;
        prev={r,c};
    }
    return true;
}
int main(){
    cin>>n>>m;
    s=n*m;
    int ans=-1;
    for(int k=1;k<s;k++){
        if(gcd(k,s)!=1) continue;
        if(chk(k)){
            ans=k;
            break;
        }
    }
    if(ans==-1) cout << -1;
    else{
        int cur=0;
        for(int i=0;i<=s;i++){
            int r= cur/m+1;
            int c= cur%m+1;
            cout << r << ' ' << c << '\n';
            cur = (cur+ans)%s;
        }
    }
}