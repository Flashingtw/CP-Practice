#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    cin>>s;
    deque<char> dq;
    bool re=1;
    for(char c:s){
        if(c=='R') re^=1;
        else if(re) dq.push_back(c);
        else dq.push_front(c);
    }
    string ns;
    if(re) while(!dq.empty()) ns.push_back(dq.front()),dq.pop_front();
    else while(!dq.empty()) ns.push_back(dq.back()),dq.pop_back();
    string st;
    for(char c:ns){
        if(!st.empty()&&st.back()==c) st.pop_back();
        else st.push_back(c);
    }
    cout << st << '\n';
}