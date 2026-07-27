#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==6||a==7) v.push_back(a);
    }
    int cnt6=0,cnt7=0;
    for(int a:v){
        if(a==6) cnt6++;
        else cnt7++;
    }
    if(cnt6==0||cnt7==0) cout << 0 << '\n';
    else if(cnt6==cnt7){
        cout << cnt6*2 -1 << '\n';
    }
    else cout << min(cnt6,cnt7)*2 << '\n';
}