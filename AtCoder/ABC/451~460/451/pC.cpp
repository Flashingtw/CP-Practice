#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int q;
    cin>>q;
    int cur=0;
    int cnt=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    while(q--){
        int type,h;
        cin>>type>>h;
        if(type==1){
            pq.push(h);
        }
        else{
            while(!pq.empty()&&pq.top()<=h){
                pq.pop();
            }
        }
        cout << pq.size() << '\n';
    }
}