#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct box{
    int w,d;
    bool operator<(box other){
        return w+d<other.w+other.d;
    }
};
int main(){
    int n;
    cin>>n;
    vector<box> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].w>>v[i].d;
    }
    sort(v.begin(),v.end());
    ll cur_w=0;
    priority_queue<int> pq;
    for(auto [w,d]:v){
        if(cur_w<=d){
            cur_w+=w;
            pq.push(w);
        }
        else{
            if(pq.top()>w){
                cur_w -= pq.top();
                pq.pop();
                pq.push(w);
                cur_w+=w;
            }
        }
    }
    cout << pq.size();
}