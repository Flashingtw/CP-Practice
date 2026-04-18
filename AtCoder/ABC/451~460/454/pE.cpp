#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int n,a,b;
char dc[] = {'R','L','U','D'};
bool solve(){
    cin>>n>>a>>b;
    if(n&1||!((a+b)&1)) return 0;
    int cb = ((b-1)/2)*2+1;
    string s;
    for(int i=1;i<cb;i+=2){
        for(int j=1;j<n;j++){
            s.push_back(dc[3]);
        }
        s.push_back(dc[0]);
        for(int j=1;j<n;j++){
            s.push_back(dc[2]);
        }        
        s.push_back(dc[0]);
    }

    bool t=0;
    for(int i=1;i<=n;i++){
        if(i==a){
            if(i<n) s.push_back(dc[3]); 
        }
        else{
            s.push_back(dc[t]);
            t^=1;
            if(i<n) s.push_back(dc[3]);
        }
    }
    
    for(int i=cb+2;i<=n;i+=2){
        s.push_back(dc[0]);
        for(int j=1;j<n;j++){
            s.push_back(dc[2]);
        }
        s.push_back(dc[0]);
        for(int j=1;j<n;j++){
            s.push_back(dc[3]);
        }
    }
    cout << "Yes\n";
    cout << s << '\n';
    return 1;
}

int main(){
    int t;
    cin>>t;
    while(t--) {
        if(!solve()){
            cout << "No\n";
        }
    }
}