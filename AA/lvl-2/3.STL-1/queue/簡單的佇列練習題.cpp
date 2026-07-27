#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    queue<int> q;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        if(t==1){
            int n;
            cin>>n;
            q.push(n);
        }
        if(t==2){
            if(!q.empty()) q.pop();
            else cout << "QQ" << '\n';
        }
        if(t==3){
            if(!q.empty()) cout << q.front() << '\n';
            else cout << "QQ" << '\n';
        }
        if(t==4){
            cout << q.size() << '\n';
        }
    }
}