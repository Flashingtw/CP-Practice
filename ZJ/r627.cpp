#include <bits/stdc++.h>
using namespace std;
vector<job> v;
struct job {
    int s,d,t;
    bool operator<(const job &other) const {
        if (s != other.s) return s < other.s;
        if (d != other.d) return d < other.d;
        return t < other.t;
    }
};

bool chk(int lmt){
    int cur=0,t=0;
    for(job &j : v){
        int start_at = max(cur, j.s);
        int end_at = start_at + j.t;
        if (end_at > j.d) return false;
        cur = end_at + lmt;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i].s>>v[i].d>>v[i].t;
    sort(v.begin(),v.end());
    int _max=0;
    do{
        int l=0,r=1000,ans=0;
        while(l<=r){
            int mid = (l+r)/2;
            if(chk(mid)){
                ans=mid;
                l = mid+1;
            }
            else r = mid-1;
        } 
        _max= max(_max,ans); 
    }while(next_permutation(v.begin(),v.end()));
    cout << _max;
}