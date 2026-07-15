//CSES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct state{
    string s;
    int d;
};
int p1[] = {0,1,3,4,6,7,0,3,1,4,2,5};
int p2[] = {1,2,4,5,7,8,3,6,4,7,5,8};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    s.reserve(9);
    string end;
    for(int i=0;i<9;i++){
        end.push_back('1'+i);
        char c;
        cin>>c;
        s.push_back(c);
    }
    queue<state> q;
    unordered_set<string> us;
    q.push({s,0});
    us.insert(s);
    while(!q.empty()){
        auto [a,d] = q.front();
        q.pop();
        if(a==end){
            cout << d << '\n';
            return 0;
        }
        for(int j=0;j<12;j++){
            string tmp = a;
            swap(tmp[p1[j]],tmp[p2[j]]);
            if(us.find(tmp)!=us.end()) continue;
            q.push({tmp,d+1});
            us.insert(tmp);
        }
    }
}