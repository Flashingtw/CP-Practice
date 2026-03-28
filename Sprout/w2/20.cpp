#include <bits/stdc++.h>
using namespace std;
struct node{
    int id;
    int l,r;
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<node> v(n+2);
    for(int i=0;i<=n+1;i++){
        v[i].l=i-1;
        v[i].id=i;
        v[i].r=i+1;
    }
    while(m--){
        int t,x;
        cin>>t>>x;
        if(t){
            if(v[x].l!=0){
                int prev= v[x].l;
                int next= v[x].r;
                int prev_prev = v[prev].l;

                v[x].l=prev_prev;
                v[x].r=prev;

                v[prev].l=x;
                v[prev].r=next;

                v[prev_prev].r=x;
                v[next].l=prev;
            }
        }
        else {
            int prev = v[x].l;
            int next = v[x].r;

            v[prev].r = next;
            v[next].l = prev;
        }
    }
    int cur=0;
    while(v[cur].r!=n+1){
        cur = v[cur].r;
        cout << cur << ' ';
    }
}