#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    vector<ll> v;
    v.push_back(n);
    unordered_set<ll> s;
    s.insert(n);
    ll max_num=0;
    while(1){
        ll last= v.back();
        max_num=max(max_num,last);
        ll p;
        if(last&1) p=3*last+1;
        else p=last/2;
        if(!s.count(p)){
            v.push_back(p);
            s.insert(p);
        }
        else break;
    }
    cout << v.size() << " " << max_num;
}
