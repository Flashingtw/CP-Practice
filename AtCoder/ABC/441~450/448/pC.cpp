#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> org(n),v(n);
    for(int i=0;i<n;i++){
        cin>>org[i];
        v[i]=org[i];
    }
    sort(v.begin(),v.end());
    while(q--){
        int k;
        cin>>k;
        vector<int> val(k);
        for(int i=0;i<k;i++) {
            int num;
            cin>>num;
            num--;
            val[i]=org[num];
        }
        sort(val.begin(),val.end());
        int j=0;
        for(int i=0;i<k;i++){
            if(val[i]!=v[j]) break;
            else{
                j++;
            }
        }
        cout << v[j] << '\n';
    }
}