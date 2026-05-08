#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int n,t;
void solve(){
    stack<int> cur;
    for(int i=n;i>=1;i--) cur.push(i);
    vector<int> tar(n);
    for(int &a:tar) cin>>a;
    stack<int> tmp;
    for(int a:tar){
        while(!cur.empty()){
            if(!tmp.empty()&&a==tmp.top()){
                tmp.pop();
                break;
            }
            if(cur.top()==a){
                cur.pop(); 
                break;
            }
            tmp.push(cur.top());
            cur.pop();
        }
        if(!tmp.empty()&&a==tmp.top()){
            tmp.pop();
        }
    }
    if(!cur.empty()||!tmp.empty()){
        cout << 'N' << '\n';
    }
    else cout << 'Y' << '\n';
}
int main(){
    cin>>n>>t;
    while(t--) solve();
}