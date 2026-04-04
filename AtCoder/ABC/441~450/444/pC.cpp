#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    sort(v.begin(),v.end());
    int L = v.back();
    bool chk=1;
    for(int i=0,j=n-1;i<n&&j>=0;){
        if(v[j]==L) {
            j--;
        }
        else if (i!=j&&v[i]+v[j]==L){
            i++,j--;
        }
        else{
            chk=0;
            break;
        }
    }
    if(chk){
        cout << L << ' ';
    }

    L = v.back()+v.front();
    chk=1;
    for(int i=0,j=n-1;i<n&&j>=0;){
        if (i!=j&&v[i]+v[j]==L){
            i++,j--;
        }
        else{
            chk=0;
            break;
        }
    }
    if(chk){
        cout << L << ' ';
    }
}