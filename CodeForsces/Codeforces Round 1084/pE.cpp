#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXA = 1000005;
int spf[MAXA];
void pre() {
    for (int i=1;i<MAXA;i++) spf[i]=i;
    for (int i=2;i*i<MAXA;i++){
        if(spf[i]==i){
            for(int j=i*i;j<MAXA;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}
int get_base(int x){
    if(x==1) return 1;
    int p = spf[x];
    while(x%p==0) x/=p;
    if(x==1) return p;
    return -1;
}
bool solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    bool sorted=true;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i>0&&a[i]<a[i-1]) sorted=false;
    }
    if(sorted) return false;
    vector<int> base(n);
    for(int i=0;i<n;i++){
        base[i]=get_base(a[i]);
        if(base[i]==-1) return true;
    }
    bool chk=true;
    for(int i=1;i<n;i++){
        if(base[i]<base[i-1]) {
            return true;
        }
    }
    return false;
}
int main(){
    pre();
    int t;
    cin>>t;
    while(t--){
        if(solve()) cout << "Alice" << '\n';
        else cout << "Bob" << '\n';
    }
}