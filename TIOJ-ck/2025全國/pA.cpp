#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<char> st;
    for(char c:s){
        if(c=='('){
            st.push(c);
        }
        else{
            if(!st.empty()&&st.top()=='('){
                st.pop();
            }
            else st.push(c);
        }
    }
    cout << st.size() << '\n';
}