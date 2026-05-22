#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &a:v) cin>>a;
    vector<int> two,three,six,oth;
    for(int i:v){
        if(i%6==0){
            six.push_back(i);
        }
        else if(i%2==0){
            two.push_back(i);
        }
        else if(i%3==0){
            three.push_back(i);
        }
        else oth.push_back(i);
    }
    vector<int> ans;
    ans.reserve(n);
    for(int i:six){
        ans.push_back(i);
    }
    for(int i:two){
        ans.push_back(i);
    }
    for(int i:oth){
        ans.push_back(i);
    }
    for(int i:three){
        ans.push_back(i);
    }
    for(int i:ans) cout << i << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}