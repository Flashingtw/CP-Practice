#include <bits/stdc++.h>
using namespace std;
struct number{
    int n;
    int id;
    int count(){
        int cnt=0,t=n;
        while(t>0){
            cnt++;
            t-= t&-t;
        }
        return cnt;
    }
};
int main(){
    int n;
    cin>>n;
    vector<number> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i].n;
        v[i].id=i;
    }
    sort(v.begin(),v.end(),[&](number& a,number& b){
        int na=a.count();
        int nb=b.count();
        if(na==nb) return a.id<b.id;
        else return na<nb;
    });
    for(auto [num,id]:v){
        cout << num << ' ';
    }
}