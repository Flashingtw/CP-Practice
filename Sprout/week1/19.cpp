#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> team(1000005,-1);
    for(int i=0;i<n;i++){
        int k; cin>>k;
        for(int j=0;j<k;j++){
            int a;
            cin>>a;
            team[a]=i;
        }
    }
    queue<int> t[1005],q;
    int m;
    cin>>m;
    while(m--){
        string s;
        cin>>s;
        if(s[0]=='E'){
            int num;
            cin>>num;
            if(team[num]==-1) {
                q.push(1001);
                team[num]=1001;
            }
            else if(t[team[num]].empty()) q.push(team[num]);
            t[team[num]].push(num);
        }
        else{
            cout << t[q.front()].front() << '\n';
            t[q.front()].pop();
            if(t[q.front()].empty()||q.front()==1001) q.pop();
        }
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cout << "Line #" << i << '\n';
        solve();
    }
}