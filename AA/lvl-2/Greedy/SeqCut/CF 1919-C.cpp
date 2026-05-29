#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
//只看最後數字做決定
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &i:v) cin>>i;
    vector<int> a={INF},b={INF};
    for(int i:v){
        if(a.back()>b.back()) a.swap(b);
        if(b.back()>=a.back()&&a.back()>=i){
            a.push_back(i);
        }
        else if(b.back()>=i&&i>a.back()){
            b.push_back(i);
        }
        else a.push_back(i);
    }
    int p=0;
    int sz = a.size();
    for(int i=0;i<sz-1;i++){
        if(a[i]<a[i+1]) p++;
    }
    sz = b.size();
    for(int i=0;i<sz-1;i++){
        if(b[i]<b[i+1]) p++;
    }
    cout << p << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}