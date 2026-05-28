#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
struct rect{int l,r,b,t;};

rect a(rect x,rect y){
    int l = max(x.l,y.l);
    int r = min(x.r,y.r);
    int t = min(x.t,y.t);
    int b = max(x.b,y.b);
    return {l,r,b,t};
};

int area(rect x){
    int wid = max(0,x.r-x.l+1);
    int hei = max(0,x.t-x.b+1);
    return wid*hei;
}

void solve(){
    int n;
    cin>>n;
    int rx,ry,bx,by,yx,yy;
    for(int i=0;i<3;i++){
        char c;
        cin>>c;
        switch(c){
            case 'R':
                cin>>rx>>ry;
                break;
            case 'B':
                cin>>bx>>by;
                break;
            case 'Y':
                cin>>yx>>yy;
                break;
        }
    }
    char target; cin>>target;
    int ans=0;
    for(int tm=0;tm<=1000;tm++){
        rect R = {max(0,rx-tm),min(n-1,rx+tm),max(0,ry-tm),min(n-1,ry+tm)};
        rect B = {max(0,bx-tm),min(n-1,bx+tm),max(0,by-tm),min(n-1,by+tm)};
        rect Y = {max(0,yx-tm),min(n-1,yx+tm),max(0,yy-tm),min(n-1,yy+tm)};
        
        rect RB = a(R,B);
        rect RY = a(R,Y);
        rect BY = a(B,Y);
        rect RBY = a(RB,Y);
        int cur=0;
        switch(target){
            case 'R':
                cur = area(R)-area(RY)-area(RB)+area(RBY);
                break;
            case 'B':
                cur = area(B)-area(BY)-area(RB)+area(RBY);
                break;
            case 'Y':
                cur = area(Y)-area(BY)-area(RY)+area(RBY);
                break;
            case 'O':
                cur = area(RY)-area(RBY);
                break;
            case 'P':
                cur = area(RB)-area(RBY);
                break;
            case 'G':
                cur = area(BY)-area(RBY);
                break;
            case 'D':
                cur = area(RBY);
                break;
        }
        ans = max(ans,cur);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}