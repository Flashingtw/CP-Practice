#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
ll grid[20][20];
int main(){
    int h,w;
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>grid[i][j];
        }
    }
    vector<ll> totallr(h+1);
    for(int i=1;i<=h;i++){
        ll sum=0;
        for(int j=1;j<=w;j++){
            sum+=grid[i][j];
        }
        totallr[i] = sum;
    }
    vector<ll> totaltb(w+1);
    for(int j=1;j<=w;j++){
        ll sum=0;
        for(int i=1;i<=h;i++){
            sum+=grid[i][j];
        }
        totaltb[j] = sum;
    }
    ll mx=0;
    for(int i=1;i<=h;i++){
        if(totallr[i]>0) mx+=totallr[i];
    }
    for(int i=1;i<=w;i++){
        ll sum=0;
        if(totaltb[i]>0) sum+=totaltb[i];
        mx = max(mx,sum);
    }
    for(int mask=0;mask<(1<<w);mask++){
        ll cur=0;
        for(int u=0;u<w;u++){
            if(mask&(1<<u)){
                cur+=totaltb[u+1];
            }
        }
        for(int i=1;i<=h;i++){
            ll ex=totallr[i];
            for(int u=0;u<w;u++){
                if(mask&(1<<u)){
                    ex-=grid[i][u+1];
                }
            }
            if(ex>0){
                cur+=ex;
            }
        }
        mx = max(mx,cur);
    }
    cout << mx;
}