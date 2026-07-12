#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

struct ver{
    int ma,mi,p;
    bool operator<(ver b){
        if(ma<b.ma){
            return 1;
        }
        else if (ma==b.ma){
            if(mi<b.mi){
                return 1;
            }
            else if(mi==b.mi){
                if(p<b.p){
                    return 1;
                }
                else return 0;
            }
            else return 0;
        }
        return 0;
    }
    bool operator==(ver b){
        return ma==b.ma&&mi==b.mi&&p==b.p;
    }
    bool operator>(ver b){
        if(ma>b.ma){
            return 1;
        }
        else if (ma==b.ma){
            if(mi>b.mi){
                return 1;
            }
            else if(mi==b.mi){
                if(p>b.p){
                    return 1;
                }
                else return 0;
            }
            else return 0;
        }
        return 0;
    }
};

void solve(){
    ver a,b;
    cin>>a.ma>>a.mi>>a.p;
    cin>>b.ma>>b.mi>>b.p;
    if(a>b) cout << '>' << '\n';
    if(a==b) cout << '=' << '\n';
    if(a<b) cout << '<' << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}