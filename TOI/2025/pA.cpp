#include <bits/stdc++.h>
using namespace std;
struct number{
    int n;
    int count(){
        int mx=0,cnt=0;
        for(int i=0;i<30;i++){
            if(n&(1<<i)) {
                cnt++;
                mx = max(mx,cnt);
            }
            else{
                cnt=0;
            }
        }
        return mx;
    }
    bool operator<(number other){
        int self = count();
        int oth = other.count();
        if(self==oth) return n<other.n;
        return self<oth;
    }
};
int main(){
    int n;
    cin>>n;
    vector<number> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].n;
    }
    sort(v.begin(),v.end());
    for(auto [i]:v) cout<< i << ' ';
}