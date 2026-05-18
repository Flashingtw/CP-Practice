#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    deque<int> dq;
    while(n--){
        int type;
        cin>>type;
        if(type==1){
            int c;
            cin>>c;
            dq.push_back(c);
        }
        if(type==2){
            int c;
            cin>>c;
            dq.push_front(c);
        }
        if(type==3){
            if(dq.empty()) cout << "error" << '\n';
            else cout << dq.back() << '\n';
        }
        if(type==4){
            if(dq.empty()) cout << "error" << '\n';
            else cout << dq.front() << '\n';
        }
        if(type==5){
            if(dq.empty()) cout << "error" << '\n';
            else dq.pop_back();
        }
        if(type==6){
            if(dq.empty()) cout << "error" << '\n';
            else dq.pop_front();
        }
        if(type==7){
            cout << dq.size() << '\n';
        }
    }
}