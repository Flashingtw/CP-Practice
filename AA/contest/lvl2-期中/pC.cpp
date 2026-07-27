#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,m,x,k;
    cin>>n>>m>>x>>k;
    k--;
    x--;
    vector<int> v(n),c(m);
    for(int &i:v) cin>>i;
    for(int &i:c) cin>>i;
    priority_queue<int> left,mid;
    sort(v.begin(),v.end());
    ll cur=0;
    for(int i=k;i<=k+x;i++) {
        mid.push(v[i]);
        cur+=v[i];
    }
    for(int i=0;i<k;i++){
        left.push(v[i]);
    }
    cout << cur << '\n';
    for(int a:c){
        if(!left.empty()&&a<left.top()){
            left.push(a);
            mid.push(left.top());
            cur+=left.top()-mid.top();
            left.pop();
            mid.pop();
        }
        else if(a<mid.top()){
            mid.push(a);
            cur+=a-mid.top();
            mid.pop();
        }
        cout << cur << '\n';
    }
}
//n=5 m=3 x=2 k=3
// [3,4]
//12 13 [13 15] 19
//17 14 13

// 1:
// 12 13 [13 15] 17 19
// ans:28

// 2:
// 12 13 [13 14] 15 17 19
// ans:27

// 3:
// 12 13 [13 13] 14 15 17 19
// ans:26