#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    list<string> ls;
    ls.push_back("ButterFly");
    int q;
    cin>>q;
    auto curr = ls.begin();
    while(q--){
        string t;
        cin>>t;
        if(t=="CURR"){
            cout << *curr << '\n';
        }
        else if(t=="ADD_LEFT"){
            string n;
            cin>>n;
            ls.insert(curr,n);
        }
        else if(t=="ADD_RIGHT"){
            string n;
            cin>>n;
            ls.insert(next(curr),n);
        }
        else if(t=="PLAY_NEXT"){
            int k;
            cin>>k;
            for(int i=0;i<k;i++){
                curr = next(curr);
                if(curr==ls.end()){
                    curr = ls.begin();
                }
            }
        }
        else if(t=="PLAY_PREV"){
            int k;
            cin>>k;
            for(int i=0;i<k;i++){
                if(curr==ls.begin()){
                    curr = ls.end();
                }
                curr = prev(curr);
            }
            
        }
        else if(t=="DELETE"){
            curr = ls.erase(curr);
            if(curr==ls.end()) curr=ls.begin();
        }
    }
}