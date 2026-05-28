#pragma GCC optimize("O3,unroll-loops")
#include <stdlib.h>
#include <stdio.h>
typedef long long ll;
ll dp[300001];
ll readll(){
    ll res = 0;
    char c = getchar_unlocked();
    while(c>='0'&&c<='9'){
        res = res*10+(c-'0');
        c = getchar_unlocked();
    }
    return res;
}
int main(){
    ll a=readll(),b=readll(),c=readll(),d=readll(),m=readll(),s=readll(),t=readll();
    ll cur=m;
    for(int i=1;i<=t;i++){
        if(cur>=c){
            dp[i] = dp[i-1]+b;
            cur-=c;
        }
        else{
            dp[i] = dp[i-1];
            cur+=d;
        }
    }
    for(int i=1;i<=t;i++){
        dp[i] = dp[i]>dp[i-1]+a?dp[i]:dp[i-1]+a;

        if(dp[i]>=s){
            printf("Yes\n%lld",i);
            return 0;
        }
    }
    printf("No\n%lld",dp[t]);
}